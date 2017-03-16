#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef multiset<int, greater<int>> mmset;

bool double_check(int time_rearrange, int time_eating, const mmset &nums)
{
    int iter_num = 0;
    for (int val: nums) {
        if (val < time_eating) {
            break;
        }
        int iters_needed = (val - time_eating) / time_eating;
        if ((val - time_eating) % time_eating > 0) {
            iters_needed++;
        }
        iter_num += iters_needed;
        if (iter_num > time_rearrange) {
            return false;
        }
    }
    return true;
}

bool check(int time, const mmset &nums)
{
    if (nums.empty() || *nums.begin() <= time) {
        return true;
    }
    if (time <= 0) {
        return false;
    }
    for (int time_eating = time; time_eating > 0; --time_eating) {
        if (double_check(time - time_eating, time_eating, nums)) {
            return true;
        }
    }
    return false;
}

int ans_bin_search(const mmset &nums)
{
    int l = 0;
    int r = *nums.begin();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m, nums)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return check(l, nums) ? l : r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int curt = 0; curt < t; ++curt) {
        int d;
        cin >> d;
        mmset nums;
        for (int i = 0; i < d; ++i) {
            int num;
            cin >> num;
            nums.insert(num);
        }
        int ans = ans_bin_search(nums);
        cout << "Case #" << curt + 1 << ": " << ans << endl;
    }
    return 0;
}
