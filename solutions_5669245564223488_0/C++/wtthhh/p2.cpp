#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define FILL(a,b) memset(a,b,sizeof(a))
#define MD 1000000007LL
#define N 1201
string s[N];
typedef long long LL;
int T,cas,n, sum, nt[N],pr[N], oc[N], g[N],fa[N];
LL ans, f[N];
int find(int x){
	return fa[x] == x? x: fa[x] = find(fa[x]);
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	f[0] = 1;
	FOR(i,1,1000) f[i] = (f[i-1]*i) % MD;
	scanf("%d",&T);
	FOR(cas,1,T){
		FILL(oc,0);
		FILL(nt,0);
		FILL(pr,0);
		scanf("%d",&n);
		FOR(i,1,n){
			cin >> s[i];
			FOR(j,0,s[i].size()-1) if(s[i][j] == s[i][j+1]) s[i].erase(j,1);
		}
		sort(s+1, s+n+1);
		FOR(i,1,n) g[i] = 1;
		FOR(i,1,n) fa[i] = i;
		FOR(i,1,n-1){
			if(s[i].size() == 1 && s[i][0] == s[i+1][0]){
				n--; g[i+1] = g[i] + (s[i+1].size() == 1);
				FOR(j,i,n){
					g[j] = g[j+1];
					s[j] = s[j+1];
				}
				i--;
				continue;
			}
		}
		ans = 1;
		FOR(i,1,n){
			int len = s[i].size()-1;
			FOR(j,1,n) if(i != j && s[i][len] == s[j][0]){
				int fx = find(i), fy = find(j);
				if(fx == fy || pr[j]) ans = 0;
				fa[fx] = fy;
				nt[i] = j;
				pr[j] = i;
				break;
			}
		}
		if(ans == 0){
			printf("Case #%d: 0\n",cas);
			continue;
		}
		sum = 0;
		FOR(i,1,n) if(!pr[i]){
			char las = '#'; int j;
			for(int j=i; j; j=nt[j]){
				FOR(k,0,s[j].size()-1){
					if(s[j][k] != las) oc[las] = true;
					if(oc[s[j][k]]) ans = 0;
					las = s[j][k];
				}
				las = s[j][s[j].size()-1];
				ans = (ans * f[g[j]]) %MD;
			}
			oc[las] = true;
			sum++;
		}
		printf("Case #%d: %lld\n",cas,(ans * f[sum]) %MD);
	}
	return 0;
}

