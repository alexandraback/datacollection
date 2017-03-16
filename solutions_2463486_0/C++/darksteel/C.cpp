#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
typedef vector<string> VS;

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(),x.end()
#define CLR(x, v) memset((x),v,sizeof (x))
#define gcd(a, b) __gcd(a, b)
#define PB push_back 
#define MP make_pair
#define INF 2000000007

int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

int a[110][110];
int n, m;

ll fs[1000], k;

bool pal(ll x)
{
    ll r = 0, o = x;
    while(x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r == o;
}

void init()
{
    int i;
    FOR(i,1,10000000) if(pal(i) && pal(1ll*i*i))
        fs[k++] = 1ll*i*i;
}

int get(ll x)
{
    int i;
    int ret = 0;
    FOR(i,0,k) if(fs[i] <= x) ret++;
    return ret;
}

int solve()
{
    ll A, B;
    cin>>A>>B;
    return get(B) - get(A-1);
}

int main()
{
    int T;
    cin>>T;
    init();
    for(int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": " << solve() << endl;
    }
	return 0;
}
