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

#define INP_FILE "B-small-attempt0.in"
#define OUT_FILE "output.txt"

int main()
{
    freopen(INP_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    int tstCnt; cin >> tstCnt;
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        string s; cin >> s;
        int ans = (s.back() == '-');
        fi(i, 0, s.size() - 1) {
            ans += (s[i] != s[i + 1]);
        }
        printf("Case #%d: %d\n",tst,ans);
    }

    return 0;
}