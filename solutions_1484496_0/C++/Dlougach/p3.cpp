#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main(void) {
    int testCount;
    cin >> testCount;
    for (int testNo = 1; testNo <= testCount; ++testNo) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i< n; ++i)
            cin >> nums[i];
        vector< pair<int, int> > subsets(1<<n);
        for (int i = 1; i < (int)(1<<n); ++i) {
            subsets[i].first = 0;
            subsets[i].second = i;
            for (int j = 0; j < n; ++j)
                if ((1<<j) & i)
                    subsets[i].first += nums[j];
        }
        sort(subsets.begin(), subsets.end());
        int res1 = -1, res2 = -1;
        for (int i = 0; i + 1 < (int)subsets.size(); i++) {
            if (subsets[i].first == subsets[i+1].first) {
                res1 = subsets[i].second;
                res2 = subsets[i+1].second;
            }
        }
        int c = res1 & res2;
        res1 ^= c;
        res2 ^= c;
        cout << "Case #" << testNo <<":" << endl;
        if (res1 == -1) {
            cout << "Impossible" << endl;
        } else {
            for (int i = 0; i < n; ++i) {
                if (res1 & (1<<i)) {
                    cout << nums[i] << " ";
                }
            }
            cout << endl;
            for (int i = 0; i < n; ++i) {
                if (res2 & (1<<i)) {
                    cout << nums[i] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
