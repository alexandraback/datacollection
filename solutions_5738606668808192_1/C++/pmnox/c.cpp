#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,b) for(auto i=(0);i<(b);++i)
#define fo(i,a,b) for(auto i=(a);i<=(b);++i)
#define ford(i,a,b) for(auto i=(a);i>=(b);--i)
#define fore(a,b) for(auto a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int n;
int j;

void solve() {
    scanf("%d%d", &n, &j);
    int num[64] = {};

    num[0] = 1;
    num[n - 1] = 1;

    printf("\n");

    while (j > 0) {
        int res[16] = {};
        fo (base, 2, 10) {
            fo (mod, 2, 50) {
                int sum = 0;
                fo (pos, 0, n - 1) {
                    sum = ((sum * base) + num[pos]) % mod;
                }
                if (sum == 0) {
                    res[base] = mod;
                    break;
                }
            }
            if (res[base] == 0)
                break;
        }
        if (res[10] > 0) {
            j--;
            fo (pos, 0, n - 1) printf("%d", num[pos]);
            fo (base, 2, 10)
                printf(" %d", res[base]);
            printf("\n");
        }

        num[n-2]++;
        for (int k = n - 2; k > 0 && num[k] >= 2; k--) {
            num[k] -= 2;
            num[k - 1]++;
        }
        if (num[0] == 2) {
            cerr << "BUG" << endl;
            break;
        }
    }
}

int main(int argc, char ** argv) {
    ios::sync_with_stdio(false);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}
