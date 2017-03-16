#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 p = 1047587;
int64 q = 33544457;

void solve() {
    int n;
    cin >> n;
    vector<int64> a(n);
    for (int i = 0; i < n; ++i)
       cin >> a[i];
    vector<pair<int, int> > res;
    vector<pair<int64, int64> > result;
    vector<vector<int64> > ans1;
    vector<vector<int64> > ans2;
    for (int i = 0; i < 25; ++i) {
        vector<int64> b;
        for (int j = 0; j < n / 25; ++j)
             b.pb(a[i * 20 + j] % p);
        map <int, int> val;
        for (int j = 1; j < (1 << 20); ++j) {
            int64 sum = 0;
            for (int k = 0; k < 20; ++k)
                if (j & (1 << k))
                     sum += b[k];
            sum %= p;
            if (val.find(sum) != val.end()) {
                res.pb(mp(val[sum], j));
                break;
            }
            val[sum] = j;
        }
        int64 sum1 = 0;
        int64 sum2 = 0;
        vector<int64> new_ans1;
        vector<int64> new_ans2;
        for (int j = 0; j < sz(b); ++j)
            if (res[sz(res) - 1].first & (1 << j)) {
                sum1 += a[i * 20 + j];
                new_ans1.pb(a[i * 20 + j]);
            }
        for (int j = 0; j < sz(b); ++j)
            if (res[sz(res) - 1].second & (1 << j)) {
                sum2 += a[i * 20 + j];
                new_ans2.pb(a[i * 20 + j]);
            }
        result.pb(mp(sum1 % q, sum2 % q));
        ans1.pb(new_ans1);
        ans2.pb(new_ans2);
        
    }
    map<int64, int64> val;
    int res1 = 0;
    int res2 = 0;
    for (int i  =0; i < (1 << 25); ++i) {
        int64 sum = 0;
        for (int j = 0; j < 25; ++j)
            if (i & (1 << j))
                sum += result[j].first;
            else
                sum += result[j].second;
        sum %= q;
        if (val.find(sum) != val.end()) {
            res1 = val[sum];
            res2 = i;
            break;
        }
        val[sum] = i;
    }
    cout << endl;
    for (int i  =0; i < 25; ++i)
        if (res1 & (1 << i)) {
            for (int j  =0; j < sz(ans1[i]); ++j)
                cout << ans1[i][j] << " ";
        }
        else
        {
            for (int j  =0; j < sz(ans2[i]); ++j)
                cout << ans2[i][j] << " ";
        }
            
    cout << endl;
    
    for (int i  =0; i < 25; ++i)
        if (res2 & (1 << i)) {
            for (int j  =0; j < sz(ans1[i]); ++j)
                cout << ans1[i][j] << " ";
        }
        else
        {
            for (int j  =0; j < sz(ans2[i]); ++j)
                cout << ans2[i][j] << " ";
        }
    cout << endl;
    
    
    
    
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    for (int tests = 0; tests < t; ++tests) {
        cout << "Case #" << tests + 1 << ": ";
        solve();
    }   
    return 0;
}
