#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <climits>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long lint;

#define PI 3.1415926535897932385

char ar[256][256];
int sar[256][256];

int dp[10001][4];

int func(int i,int cuts, string &s,int n) {
    if (dp[i][cuts] != -1) {
        return dp[i][cuts];
    }
    if (cuts == 0) {
        char c = '1';
        int sign = 0;
        for (int j = i; j < n; ++j) {
            char cc = ar[c][s[j]];
            sign ^= sar[c][s[j]];
            c = cc;
        }
        if (!sign && c == 'k') {
            return dp[i][cuts] = 1;
        }
    } else if (cuts == 1) {
        char c = '1';
        int sign = 0;
        int pos = 0;
        for (int j = i; j < n; ++j) {
            char cc = ar[c][s[j]];
            sign ^= sar[c][s[j]];
            c = cc;
            if (c == 'j' && !sign) {
                pos = func(j+1, 0, s, n);
                if (pos) {
                    return dp[i][cuts] = 1;
                }
            }
        }
    } else {
        char c = '1';
        int sign = 0;
        int pos = 0;
        for (int j = i; j < n; ++j) {
            char cc = ar[c][s[j]];
            sign ^= sar[c][s[j]];
            c = cc;
            if (c == 'i' && !sign) {
                pos = func(j+1, 1, s, n);
                if (pos) {
                    return dp[i][cuts] = 1;
                }
            }
        }
    }
    return dp[i][cuts] = 0;
}

int main() {
    freopen("a.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    int tt = 0;
    cin>>t;
    ar['1']['1'] = '1';
    sar['1']['1'] = 0;
    ar['1']['i'] = 'i';
    sar['1']['i'] = 0;
    ar['1']['j'] = 'j';
    sar['1']['j'] = 0;
    ar['1']['k'] = 'k';
    sar['1']['k'] = 0;
    ar['i']['1'] = 'i';
    sar['i']['1'] = 0;
    ar['i']['i'] = '1';
    sar['i']['i'] = 1;
    ar['i']['j'] = 'k';
    sar['i']['j'] = 0;
    ar['i']['k'] = 'j';
    sar['i']['k'] = 1;
    ar['j']['1'] = 'j';
    sar['j']['1'] = 0;
    ar['j']['i'] = 'k';
    sar['j']['i'] = 1;
    ar['j']['j'] = '1';
    sar['j']['j'] = 1;
    ar['j']['k'] = 'i';
    sar['j']['k'] = 0;
    ar['k']['1'] = 'k';
    sar['k']['1'] = 0;
    ar['k']['i'] = 'j';
    sar['k']['i'] = 0;
    ar['k']['j'] = 'i';
    sar['k']['j'] = 1;
    ar['k']['k'] = '1';
    sar['k']['k'] = 1;
    while (t--) {
        ++tt;
        int l, x;
        cin>>l>>x;
        string s, ss;
        cin>>s;
        for (int i = 0; i < x; ++i) {
            ss += s;
        }
        int sz = l * x;
        memset(dp, -1, sizeof(dp));
        cout<<"Case #"<<tt<<": "<<(func(0, 2, ss, sz)?"YES":"NO")<<"\n";
    }
    return 0;
}