/* Michał Adamczyk, saddam */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<utility>
#include<ext/numeric>
#include<tr1/unordered_map>

using namespace std;
using namespace std::tr1;
using namespace __gnu_cxx;

#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=(n)-1;i>=0;--i)
#define FORU(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define ALL(X) (X).begin(),(X).end()
#define SIZE(X) (int)(X).size()
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

LL nwd(LL a,LL b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }

const int INF = 1000000007;
const int MX = 1007;
bool d[MX];
VI g[MX];
int n;

bool dfs(int v) {
    d[v] = true;
    bool p = false;
    for(int i = 0; i < SIZE(g[v]) && !p; ++i) {
        if(d[g[v][i]])
            return true;
        else {
            p |= dfs(g[v][i]);
        }
    }
    return p;
}

void solve(int cnt) {
    bool p = false;
    scanf("%d",&n);
    int m, a;
    REP(i,n) {
        g[i+1].clear();
        d[i+1] = false;
    }
    
    REP(i,n) {
        scanf("%d",&m);
        REP(j,m) {
            scanf("%d",&a);
            g[i+1].PB(a);
        }
    }
    
    for(int i=1; i <= n && !p; ++i) {
        REP(j,n) d[j+1] = false;
        p |= dfs(i);
    }

    printf("Case #%d: %s\n", cnt, p ? "Yes" : "No");
}

int main() {
	int _T;
	scanf("%d",&_T);
	REP(i,_T) solve(i+1);
	return 0;
}

