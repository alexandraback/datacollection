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
int b[110][110];
int n, m;

string solve()
{
    int i, j;
    cin>>n>>m;
    FOR(i,0,n) FOR(j,0,m) cin>>a[i][j];
    FOR(i,0,n) FOR(j,0,m) b[i][j] = 100;
    FOR(i,0,n) FOR(j,0,m) {
        int k;
        FOR(k,0,m) if(a[i][k] > a[i][j]) break;
        if(k==m) FOR(k,0,m) b[i][k] = min(b[i][k],a[i][j]);
        FOR(k,0,n) if(a[k][j] > a[i][j]) break;
        if(k==n) FOR(k,0,n) b[k][j] = min(b[k][j],a[i][j]);
    }
    FOR(i,0,n) FOR(j,0,m) if(a[i][j] != b[i][j]) return "NO";
    return "YES";
}

int main()
{
    int T;
    cin>>T;
    for(int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": " << solve() << endl;
    }
	return 0;
}
