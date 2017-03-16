//BISMILLAHIRRAHMANIRRAHIM



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define i64 long long
#define pii pair < int , int >
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

int cn[210],pr[210],tp[210],n;
vector < int > vis(7);

#define CH(X) (vis[X>>5]&(1<<(X&31)))
#define S(X) (vis[X>>5]^=(1<<(X&31)))

vector < int > g[210];

set < vector < int > > chk;
set < vector < int > > ::iterator it;


bool dfs(int p) {
	if(p==n) return true;
	if(chk.find(vis)!=chk.end()) return false;
	chk.insert(vis);
	int i,j,k;
	for(i=1;i<=n;i++) if(!CH(i) && cn[tp[i]]) {
		pr[p]=i;
		cn[tp[i]]--;
		k=g[i].size();
		for(j=0;j<k;j++) cn[g[i][j]]++;
		S(i);
		if(dfs(p+1)) return true;
		cn[tp[i]]++;
		k=g[i].size();
		for(j=0;j<k;j++) cn[g[i][j]]--;
		S(i);
	}
	return false;
}

int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("output1.out","w",stdout);
	int I,T,i,j,u,k,l;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>k>>n;;
		for(i=0;i<7;i++) vis[i]=0;
		chk.clear();
		CLR(cn);
		while(k--) {
			cin>>u;
			cn[u]++;
		}
		for(i=1;i<=n;i++) {
			cin>>tp[i]>>l;
			g[i].resize(l);
			for(j=0;j<l;j++) cin>>g[i][j];
		}
		printf("Case #%d:",I);
		if(dfs(0)) for(i=0;i<n;i++) cout<<' '<<pr[i];
		else printf(" IMPOSSIBLE");
		puts("");
	}
	return 0;
}
