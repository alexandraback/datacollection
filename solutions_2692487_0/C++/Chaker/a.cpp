#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define pb push_back
#define sz(v) (int(v.size()))
#define mp make_pair

int main()
{
    int TEST = 0;
    cin >> TEST;
    for (int test = 1; test <= TEST; ++test) {
        cout << "Case #" << test <<": ";
        int n;
        long long a0;
        cin >> a0 >> n;
        vector <long long> a;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int diff = min(50, n);
        int ans = n;
        for (int d = 0; d <= diff; ++d) {
            int penalty = 0;
            long long w = a0;
            for (int i = 0; i < n - d; ++i) {
                while (w <= a[i] && penalty < n) {
                    ++penalty;
                    w += w - 1;
                }
                w += a[i];
            }
            ans = min(ans, penalty + d);
        }
        cout << ans << endl;
    }
    return 0;
}
