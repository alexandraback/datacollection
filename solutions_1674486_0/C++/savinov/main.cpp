#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

using namespace std;

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;
typedef long long ll;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

#define x first
#define y second

using namespace std;

vector < vector <int> > g;
vector<char> cl;
bool flag;

void dfs (int v) {
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (cl[to] == 0) {
			dfs(to);
		}
		else flag=true;
	}
	cl[v] = 2;
}

int main()
{
    freopen ("INPUT.TXT","r",stdin);
    freopen ("OUTPUT.TXT","w",stdout);
    int T;
    cin >> T;
    forn(q,T)
    {
        cout << "Case #" << q+1 << ": ";
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        forn(i,n)
        {
            int m;
            cin >> m;
            forn(j,m)
            {
                int temp;
                cin >> temp;
                g[i].pb(temp-1);
            }
        }
        flag=false;
        forn(i,n)
        {
            cl.assign (n, 0);
            dfs(i);
            if (flag) break;
        }
        if (!flag) puts ("No"); else puts("Yes");
    }
    return 0;
}
