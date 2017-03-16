#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a)-1; i>=int(b); --i)
#define FORE(i,q) for(typeof((q).begin()) i=(q).begin(); i!=(q).end(); ++i)
using namespace std;

typedef long long LG;
typedef long double LD;

int n;
list<int> G[1111];
int Was[1111];
bool T[1111][1111];

bool dfs(int s, int p) {
    Was[s] = 1;
    FORE(i,G[s]) {
	if(*i == p) continue;
	if(T[s][*i]) return true;
	T[s][*i] = true;
	if(!Was[*i]) {
	    if(dfs(*i, s)) return true;
	}
	FOR(j,1,n+1) {
	    //printf("1. (%d %d) %d\n", s, j, T[s][j]);
	    //printf("2. (%d %d) %d\n", *i, j, T[*i][j]);
	    if(T[s][j] && T[*i][j]) return true;
	    T[s][j] |= T[*i][j];
	}
    }
    Was[s] = 2;
    return false;
}

void testcase(int zzz) {
    scanf("%d", &n);
    FOR(i,0,n) {
	int m; scanf("%d", &m);
	while(m--) {
	    int x; scanf("%d", &x);
	    G[i+1].push_back(x);
	}
    }
    bool flag = false;
    FOR(i,1,n+1) Was[i] = 0;
    FOR(i,1,n+1) FOR(j,1,n+1) {
	T[i][j] = false;
    }
    FOR(i,1,n+1) if(!Was[i]) {
	flag = dfs(i, 0);
	if(flag) break;
    }

    if(flag) printf("Case #%d: Yes\n", zzz);
    else printf("Case #%d: No\n", zzz);
    FOR(i,1,n+1) G[i].clear();
}

int main() {
    int ZZZ; scanf("%d", &ZZZ);
    FOR(zzz,0,ZZZ) testcase(zzz + 1);
    return 0;
}
