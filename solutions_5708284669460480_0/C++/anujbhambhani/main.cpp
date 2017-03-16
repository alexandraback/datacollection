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

int maximum;
int cnt = 0;

int func(int j, string &nw, int k, int s, string &orig,int l, string &target) {
    if (j == s) {
        ++cnt;
        int banana = 0;
        for (int i = 0; i < s; ++i) {
            bool fl = 1;
            for (int j = 0; j < l; ++j) {
                if (nw[i+j] != target[j]) {
                    fl = 0;
                    break;
                }
            }
            if (fl) {
                ++banana;
            }
        }
        maximum = max(maximum, banana);
        return banana;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        string ss = nw;
        ss += orig[i];
        ans += func(j + 1, ss, k, s, orig, l, target);
    }
    return ans;
}

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t, k, l, s;
    cin>>t;
    string orig, target;
    int tt = 0;
    while (t--) {
        ++tt;
        maximum = 0;
        cnt = 0;
        cin>>k>>l>>s;
        cin>>orig>>target;
        string ss;
        int banana = func(0, ss, k, s, orig, l, target);
        long long ans = (long long)maximum * cnt - banana;
        printf("Case #%d: %.8f\n", tt, (double)ans/(double)cnt);
    }
    return 0;
}