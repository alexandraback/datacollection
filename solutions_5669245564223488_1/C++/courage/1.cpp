#include <cstdio>
#include <cstring>
typedef long long ll;
const int md = 1000000007;
char s[110],a[110][110],t[10010];
bool v[210] = {0},g[210] = {0},flag,forB[210];
int te,n,ans,f[110],pure[110],b[110],m,tail[110],numOf,fact[110];
bool yes(char *t){
	memset(g,0,sizeof g);
	int l = strlen(t),p = 0,q;
	while (p < l){
		if (g[t[p] - 'a'] || forB[t[p] - 'a']) return 0;
		q = p;
		while (q + 1 < l && t[q + 1] == t[p]) q++;
		g[t[p] - 'a'] = 1;
		p = q + 1;
	}
	return 1;
}
bool Pure(char *s){
	int l = strlen(s);
	for (int i = 0;i < l - 1;i++) if (s[i] != s[i + 1]) return 0;
	return 1;
}
void connect(int k,bool &q){
	v[b[k]] = 1;
	strcat(t,a[b[k]]);
	tail[a[b[k]][strlen(a[b[k]]) - 1] - 'a']--;
	for (int i = 1;i <= m;i++) if (!v[b[i]] && a[b[i]][0] == a[b[k]][strlen(a[b[k]]) - 1]){
		connect(i,q);
		break;
	}
	if (q) return;
	q = 1;
	if (!yes(t)){
		flag = 0;
		return;
	}
	int l = strlen(t);
	for (int i = 0;i < l;i++) forB[t[i] - 'a'] = 1;
	numOf++;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	fact[0] = 1;
	for (int i = 1;i <= 26;i++) fact[i] = (ll)fact[i - 1] * i % md;
	scanf("%d",&te);
	for (int T = 1;T <= te;T++){
		memset(forB,0,sizeof forB);
		flag = 1;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) scanf("%s",a[i]);
		ans = 0;
		for (int i = 1;i <= n;i++) if (!yes(a[i])) flag = 0;
		if (flag == 0){
			printf("Case #%d: 0\n",T);
			continue;
		}
		memset(pure,0,sizeof pure);
		m = 0;
		for (int i = 1;i <= n;i++) if (Pure(a[i])){
			pure[a[i][0] - 'a']++;
		}else{
			b[++m] = i;
		}
		memset(tail,0,sizeof tail);
		for (int i = 1;i <= m;i++){
			tail[a[b[i]][strlen(a[b[i]]) - 1] - 'a']++;
		}
		memset(v,0,sizeof v);
		numOf = 0;
		while (1){
			bool tmp = 0;
			for (int i = 1;i <= m;i++) if (!v[b[i]] && tail[a[b[i]][0] - 'a'] == 0){
				tmp = 1;
				t[0] = 0;
				bool test = 0;
				connect(i,test);
			}
			if (!tmp) break;
			if (!flag) break;
		}
		for (int i = 1;i <= m;i++) if (!v[b[i]]) flag = 0;
		ans = 1;
		for (int i = 0;i < 26;i++){
			ans = (ll)ans * fact[pure[i]] % md;
			if (!forB[i] && pure[i]) numOf++;
		}
		ans = (ll)ans * fact[numOf] % md;
		if (!flag) ans = 0;
		printf("Case #%d: %d\n",T,ans);
	}
}
