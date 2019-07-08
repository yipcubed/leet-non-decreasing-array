#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/non-decreasing-array/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool isnondecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1])
                return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                int problem = nums[i];
                nums[i] = nums[i-1];
                if (isnondecreasing(nums)) {
                    return true;
                }
                nums[i] = nums[i-1] = problem;
                return isnondecreasing(nums);
            }
        }
        return true;
    }
};

void test1() {
    vector<int> v1{4,2,3};

    cout << "1 ? " << Solution().checkPossibility(v1) << endl;

    vector<int> v2{4,2,1};

    cout << "0 ? " << Solution().checkPossibility(v2) << endl;

    vector<int> v3{3,4,2,3};

    cout << "0 ? " << Solution().checkPossibility(v3) << endl;

    // [2,3,3,2,4]
    vector<int> v4{2,3,3,2,4};

    cout << "1 ? " << Solution().checkPossibility(v4) << endl;
}

void test2() {

}

void test3() {

}