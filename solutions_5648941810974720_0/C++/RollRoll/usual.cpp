#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (x); i++)
#define DEP(i,x) for(int i = (x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define ALL(x) (x).begin(), (x).end()
#define SZ(v) ((int)v.size())
#define UNIQUE(v) sort(ALL(v)); v.erase(unique(ALL(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
// ************************************************************************

int ans[10];

string solve(string s) {
    string res;
    int ans[10] = {0};
    int cnt[26] = {0};
    for (int i = 0; i < (int)s.size(); i++)
        cnt[s[i] - 'A']++;
    ans[0] = cnt['Z' - 'A'];
    ans[1] = cnt['O' - 'A'] - cnt['Z' - 'A'] - cnt['W' - 'A'] - cnt['U' - 'A'];
    ans[2] = cnt['W' - 'A'];
    ans[3] = cnt['H' - 'A'] - cnt['G' - 'A'];
    ans[4] = cnt['U' - 'A'];
    ans[5] = cnt['F' - 'A'] - cnt['U' - 'A'];
    ans[6] = cnt['X' - 'A'];
    ans[7] = cnt['S' - 'A'] - cnt['X' - 'A'];
    ans[8] = cnt['G' - 'A'];
    ans[9] = cnt['I' - 'A'] + cnt['U' - 'A'] - cnt['F' - 'A'] - cnt['X' - 'A'] - cnt['G' - 'A'];
    for (int i = 0; i < 10; i++)
        if (ans[i])
            for (int j = 0; j < ans[i]; j++)
                res += ('0' + i);
    return res;
}

int main() {
#ifdef MANGOGAO
    // freopen("data.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/A-small-attempt0.in", "r", stdin);
    // freopen("/Users/Lodour/Downloads/.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif


    fastcin;
    int t, cnt = 0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << "Case #" << ++cnt << ": " << solve(s) << endl;
    }

    return 0;
}

