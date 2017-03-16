#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
#define pb push_back
inline int ri() {
	int x=0, f=1, c=getchar();
	for(; c<48||c>57; f=c=='-'?-1:f, c=getchar());
	for(; c>47&&c<58; x=x*10+c-48, c=getchar());
	return x*f;
}
const int N=2005;
int n, cnt, nxt[N], in[N], d[N], vis[N], now, flag, q[N];
vector<int> cir[N];
void dfs(int x) {
	int y=nxt[x];
	vis[x]=now;
	if(vis[y]==now) {
		flag=y;
		++cnt;
		cir[cnt].clear();
		cir[cnt].push_back(x);
	}
	else if(!vis[y]) {
		dfs(y);
		if(flag) {
			cir[cnt].push_back(x);
			if(flag==x) {
				flag=0;
			}
		}
	}
}
int main() {
	for(int T=ri(), _t=1; _t<=T; ++_t) {
		n=ri();
		printf("Case #%d: ", _t);
		memset(nxt, 0, sizeof nxt);
		memset(vis, 0, sizeof vis);
		memset(in, 0, sizeof in);
		memset(d, 0, sizeof d);
		cnt=0;
		for(int i=1; i<=n; ++i) {
			in[nxt[i]=ri()]++;
		}
		for(int i=1; i<=n; ++i) {
			if(!vis[i]) {
				now=i;
				flag=0;
				dfs(i);
			}
		}
		int *fr=q, *ta=q;
		for(int i=1; i<=n; ++i) {
			if(!in[i]) {
				*ta++=i;
			}
		}
		for(; fr!=ta; ) {
			int x=*fr++;
			int y=nxt[x];
			d[y]=max(d[y], d[x]+1);
			if(!--in[y]) {
				*ta++=y;
			}
		}
		int ans=0, sum=0;
		for(int s=1; s<=cnt; ++s) {
			int len=cir[s].size();
			ans=max(ans, len);
			if(len==2) {
				sum+=d[cir[s][0]]+d[cir[s][1]]+2;
			}
		}
		printf("%d\n", max(ans, sum));
	}
	return 0;
}
