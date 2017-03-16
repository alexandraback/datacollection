#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int n,m;
int h[555][555];
int hx[555], hy[555];

int main() {
	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d%d", &n, &m);
	FOR(i,0,n) FOR(j,0,m) scanf("%d", &(h[i][j]));
	FOR(i,0,n){
		hx[i] = 0;
		FOR(j,0,m) hx[i] = max(hx[i], h[i][j]);
	}
	FOR(j,0,m){
		hy[j] = 0;
		FOR(i,0,n) hy[j] = max(hy[j], h[i][j]);
	}
	bool bad = false;
	FOR(i,0,n) FOR(j,0,m) if(h[i][j] != min(hx[i],hy[j])) bad = true;
	
	printf("Case #%d: ", tt);
	if(bad)printf("NO\n"); else printf("YES\n");
}	
return 0;
}


