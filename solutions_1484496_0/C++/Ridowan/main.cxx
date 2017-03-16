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
using namespace std;

#define pii pair < int , int >
#define i64 long long
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

int d[600],vis[22][2000090],t,L,n;
vector < int > g;

bool dfs(int p,int s) {
	//cout<<p<<'\n';
	if(!s) return true;
	if(p==n || vis[p][s]==L) return false;
	vis[p][s]=L;
	if(!(t&(1<<p)) && d[p]<=s) {
		if(dfs(p+1,s-d[p])) {
			g.PB(d[p]);
			return true;
		}
	}
	return dfs(p+1,s);
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int I,T,m,i,s;
	L=1;
	cin>>T;
	for(I=1;I<=T;I++) {
		cin>>n;
		for(i=0;i<n;i++) cin>>d[i];
		m=1<<n;
		g.clear();
		for(t=0;t<m;t++) {
			s=0;
			for(i=0;i<n;i++) if(t&(1<<i)) s+=d[i];
			if(s && dfs(0,s)) break;
			L++;
		}
		printf("Case #%d:\n",I);
		if(t==m)  puts("Impossible");
		else {
			bool f=0;
			for(i=0;i<n;i++) if(t&(1<<i)) {
				if(f) cout<<' '<<d[i];
				else cout<<d[i];
				f=1;
			}
			cout<<'\n'<<g[0];
			for(i=1;i<(int)g.size();i++) cout<<' '<<g[i];
			puts("");
		}
	}
	return 0;
}
