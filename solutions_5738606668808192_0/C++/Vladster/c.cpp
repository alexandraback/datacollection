#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define fi(i,a,b) for(int i=(a);i<(b); ++i)
#define fd(i,a,b) for(int i=(a);i>(b); --i)
#define fie(i,a,b) for(int i=(a);i<=(b); ++i)
#define fde(i,a,b) for(int i=(a);i>=(b); --i)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define rall(s) (s).rbegin(),(s).rend()
#define C(u) memset((u),0,sizeof((u)))
#define x first
#define y second
#define inf 1000000000
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef pair<int, int> pii;

#define INP_FILE "C-small-attempt0.in"
#define OUT_FILE "output.txt"

int main()
{
    freopen(INP_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    int tstCnt; cin >> tstCnt;
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        int n, q; cin >> n >> q;
        printf("Case #%d:\n", tst);
        fi(i, 0, q) {
            printf("11");
            int c = i;
            fi(j, 0, (n / 2) - 2) {
                printf("%d%d", c & 1, c & 1);
                c = c >> 1;
            }
            printf("11");
            fie(base, 2, 10) {
                printf(" %d", base + 1);
            }
            printf("\n");
        }
    }

    return 0;
}