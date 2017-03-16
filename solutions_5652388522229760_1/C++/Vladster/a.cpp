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

#define INP_FILE "A-large.in"
#define OUT_FILE "output.txt"

int solve(int n) {
    int s = 0;
    int c = 0;
    while (s != ((1 << 10) - 1)) {
        c += n;
        if (c < 0) {
            printf("\n\n\nfuu\n\n\n");
        }
        int d = c; 
        while (d) {
            s |= (1<<(d%10));
            d /= 10;
        }
    }
    return c;
}

int main()
{
    freopen(INP_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    int tstCnt; cin >> tstCnt;
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        int n; cin >> n;
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", tst);
        }
        else {
            int ans = solve(n);
            printf("Case #%d: %d\n", tst, ans);
        }
        
    }

    return 0;
}