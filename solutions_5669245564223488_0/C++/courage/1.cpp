#include <cstdio>
#include <cstring>
const int md = 1000000007;
char s[110],a[110][110],t[10010];
bool v[210] = {0},g[210] = {0};
int te,n,ans,f[110];
bool yes(){
	memset(g,0,sizeof g);
	int l = strlen(t),p = 0,q;
	while (p < l){
		if (g[t[p]]) return 0;
		q = p;
		while (q + 1 < l && t[q + 1] == t[p]) q++;
		g[t[p]] = 1;
		p = q + 1;
	}
	return 1;
}
void work(int k,int x){
	f[k] = x;
	v[x] = 1;
	if (k == n){
		t[0] = 0;
		for (int i = 1;i <= n;i++) strcat(t,a[f[i]]);
		v[x] = 0;
		if (yes()) ans++;
		return;
	}
	for (int i = 1;i <= n;i++) if (!v[i]) work(k + 1,i);
	v[x] = 0;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&te);
	for (int T = 1;T <= te;T++){
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) scanf("%s",a[i]);
		ans = 0;
		memset(v,0,sizeof v);
		work(0,0);
		printf("Case #%d: %d\n",T,ans);
	}
}
