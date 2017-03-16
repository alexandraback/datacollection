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

#define INP_FILE "D-small-attempt0.in"
#define OUT_FILE "output.txt"

int main()
{
    freopen(INP_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    int tstCnt; cin >> tstCnt;
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        ll k, c, s; cin >> k >> c >> s;
        printf("Case #%d:", tst);
        if ((k+c-1)/c > s) {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        ll ch = 0;
        ll last = 1; fi(i, 0, c) last *= k;
        fi(num, 0, s) {
            if (ch == k) {
                printf(" %lld", last--);
            }
            else {
                ll d = 0;
                fi(i, 0, c) {
                    d *= k;
                    if (ch < k) {
                        d += ch;
                        ++ch;
                    }
                }
                d += 1;
                printf(" %lld", d);
            }
        }
        printf("\n");

        //printf("Case #%d: ",tst);
    }

    return 0;
}