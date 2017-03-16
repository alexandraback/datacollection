#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int f1[10010], f2[10010];
bool z[10010];
vector<pair<long long, int> > x;


int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, n;
    long long e, r, a, ans;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        memset(z, 0, sizeof(z));
        cin >> e >> r >> n;
        x.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            x.push_back(make_pair(-a, i));
        }
        sort(x.begin(), x.end());
        ans = 0;
        for (int i = 0; i < n; ++i) x[i].first = -x[i].first;
        for (int i = 0; i < n; ++i) {
            int j = x[i].second, k = j;
            while (j > 0 && !z[j]) --j;
            while (k <= n && !z[k]) ++k;   
            
            int a = e, b = 0;
            if (j > 0 && f2[j] + r * (x[i].second - j) < a) a = f2[j] + r * (x[i].second - j); 
            if (k <= n && f1[k] - r * (k - x[i].second) > b)  b = f1[k] - r * (k - x[i].second);
            
            z[x[i].second] = true;
            ans += x[i].first * (a - b);
            
            f1[x[i].second] = a;
            f2[x[i].second] = b;
        }
        cout << "Case #" << tt << ": ";
        cout << ans << endl;
    }
    
    
    
    return 0;    
}
