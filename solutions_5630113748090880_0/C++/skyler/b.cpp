#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2501;
int cnt[MAX];

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, x;
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < 2 * n - 1; j++) {
            for (int k = 0; k < n; k++) {
                cin >> x;
                cnt[x]++;
            }
        }

        vector<int> v;
        for (int j = 1; j <= 2500; j++) {
            if (cnt[j] & 1) {
                v.push_back(j);
            }
        }
        sort(v.begin(), v.end());

        cout << "Case #" << i << ":";
        for (int j = 0; j < v.size(); j++) {
            cout << " " << v[j];
        }
        cout << endl;
    }
}
