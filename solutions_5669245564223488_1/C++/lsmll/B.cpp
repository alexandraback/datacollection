#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mm=1000000007;
char ch[111];
ll fac[111],ans;
int tests,i,j,k,n,m,p[111][2],w[111][111],a[111][2],len[111],fa[111],tot,c[111],cc,t[111],d[111],pre[111],next[111],cot[111];
int prework(){
	int i,j,res=0;
	for (i=1;i<=n;i++){
		a[i][0]=w[i][1];a[i][1]=w[i][len[i]];memset(t,0,sizeof(t));
		if (a[i][0]!=a[i][1]){
			if (p[a[i][0]][0]||p[a[i][1]][1]) return -1;
			p[a[i][0]][0]=p[a[i][1]][1]=i;res++;
		}else c[a[i][0]]++;
		for (j=1;j<=len[i];j++){
			t[w[i][j]]++;
			if (t[w[i][j]]>1&&w[i][j]!=w[i][j-1]) return -1;
			if (d[w[i][j]]!=i&&d[w[i][j]]) return -1;
			if (w[i][j]!=w[i][1]&&w[i][j]!=w[i][len[i]]&&t[w[i][j]]==1) d[w[i][j]]=i;
		}
	}
	for (i=1;i<=26;i++){
		if (c[i]&&!p[i][0]&&!p[i][1]) res++;
		ans=ans*fac[c[i]]%mm;
	}
	return res;
}
int getfa(int x){
	return (fa[x])?fa[x]=getfa(fa[x]):x;
}
void merge(int x,int y){
	if (!x||!y) return;
	int i=getfa(x),j=getfa(y);
	if (i==j) return;
	tot--;fa[j]=i;
	next[x]=y;pre[y]=x;
}
bool check(){
	int i,j;
	for (i=1;i<=n;i++){
		if (a[i][0]==a[i][1]||pre[i]) continue;
		for (j=i;j;j=next[j]){
			if (!pre[j]) cot[a[j][0]]++;
			cot[a[j][1]]++;
			if (cot[a[j][0]]>1||cot[a[j][1]]>1) return 0;
		}
	}
	return 1;
}
int main(){
	//freopen("B.in","r",stdin);
	scanf("%d",&tests);cc=0;
	for (fac[0]=i=1;i<=105;i++) fac[i]=fac[i-1]*(ll)i%mm;
	while (tests--){
		scanf("%d",&n);cc++;
		memset(len,0,sizeof(len));memset(w,0,sizeof(w));memset(p,0,sizeof(p));memset(a,0,sizeof(a));memset(fa,0,sizeof(fa));memset(c,0,sizeof(c));memset(d,0,sizeof(d));
		memset(cot,0,sizeof(cot));memset(pre,0,sizeof(pre));memset(next,0,sizeof(next));
		for (i=1;i<=n;i++){
			scanf("%s",ch);len[i]=strlen(ch);
			for (j=0;j<len[i];j++) w[i][j+1]=ch[j]-'a'+1;
		}
		ans=1;tot=prework();
		if (tot==-1){
			printf("Case #%d: 0\n",cc);continue;
		}
		for (i=1;i<=n;i++){
			if (a[i][0]==a[i][1]) continue;
			merge(p[a[i][0]][1],i);merge(i,p[a[i][1]][0]);
		}
		ans=ans*fac[tot]%mm;
		if (!check()){
			printf("Case #%d: 0\n",cc);continue;
		}
		printf("Case #%d: %lld\n",cc,ans);
	}
	return 0;
}
