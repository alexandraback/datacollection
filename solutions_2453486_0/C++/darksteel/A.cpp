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

bool check(char g[5][5], char c)
{
    int i, j;
    FOR(i,0,4) {
        FOR(j,0,4) if(g[i][j]!=c) break;
        if(j==4) return true;
        FOR(j,0,4) if(g[j][i]!=c) break;
        if(j==4) return true;
    }
    FOR(i,0,4) if(g[i][i]!=c) break;
    if(i==4) return true;
    FOR(i,0,4) if(g[i][3-i]!=c) break;
    if(i==4) return true;
    return 0;
}

string solve()
{
    int i, j;
    char g[5][5];
    FOR(i,0,4) cin>>g[i];
    int f = 1;
    int x = -1, y = -1;
    FOR(i,0,4) FOR(j,0,4) {
        if(g[i][j] == '.') f = 0;
        if(g[i][j] == 'T') x=i,y=j;
    }
    if(x>=0) g[x][y]='O';
    if(check(g,'O')) return "O won";
    if(x>=0) g[x][y]='X';
    if(check(g,'X')) return "X won";
    if(f) return "Draw";
    return "Game has not completed";
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
