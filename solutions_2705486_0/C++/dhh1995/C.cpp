#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define N 1200005
int n,m,tot=1,ans,c[N][26],a[N],q[N],f[4005][6];
char s[4005];
void read(int &x)
{
	#define CH getchar()
	char ch; x=0; for (ch=CH;ch<'0' || ch>'9';ch=CH);
	for (;ch>='0' && ch<='9';x=x*10+ch-48,ch=CH);
}
void ins()
{
	scanf("%s",s); int x=1,L=strlen(s);
	rep(i,L){
		int y=s[i]-97;
		if (!c[x][y]) c[x][y]=++tot;
		x=c[x][y];
		}
	a[x]++;
}
void trans(int x,int i,int j,int z)
{
	if (!x) return; if (a[x]) f[i][j]=min(f[i][j],z);
//	printf("%d %d %d %d %d\n",a[x],x,i,j,z);
	trans(c[x][s[i]-97],i+1,j?j-1:0,z);
	if (!j) rep(k,26) if (k!=s[i]-97) trans(c[x][k],i+1,4,z+1);
}
int main()
{
	freopen("C_dict.txt","r",stdin);
	n=521196; rep(i,n) ins();
//	printf("tot=%d\n",tot); for (;;);
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,Case=0; read(T);
	while (T--){
		scanf("%s",s),n=strlen(s),ans=n; memset(f,6,sizeof(f)),f[0][0]=0;
		rep(i,n) rep(j,5) if (f[i][j]<n) trans(1,i,j,f[i][j]);
		rep(j,5) ans=min(ans,f[n][j]); printf("Case #%d: %d\n",++Case,ans);
		}
	return 0;
}
