#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int smax;
        std::string str;
        cin >> smax;
        cin >> str;
        std::vector<int> nums(smax + 1);
        transform(begin(str), end(str), begin(nums), [](char c){ return c - '0'; });
        int ssum = 0;
        int ans = 0;
        for (int s = 0; s <= smax; ++s) {
            if (ssum < s) {
                ans += s - ssum;
                ssum = s;
            }
            ssum += nums[s];
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
