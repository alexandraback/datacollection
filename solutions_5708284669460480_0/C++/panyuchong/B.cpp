#include <stdio.h>
#include <string.h>
using namespace std;

int Case,T,K,L,S,i,j,k,u,Max;
int num[100];
char s[10005];
int f[105][105],fail[105];
double ans;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d",&K,&L,&S);
		scanf("%s",s+1);
		memset(num,0,sizeof(num));
		for(i=1;i<=K;++i)++num[s[i]];
		ans=S-L+1;
		scanf("%s",s+1);
		for(i=2;i<=L;++i)
		{
			for(j=fail[i-1];j&&s[j+1]!=s[i];j=fail[j]);
			if(s[j+1]==s[i])fail[i]=j+1;else fail[i]=0;
		}
		memset(f,0x80,sizeof(f));
		f[0][0]=0;
		for(i=0;i<=S;++i)
		{
			if(f[i][L]+1>f[i][fail[L]])f[i][fail[L]]=f[i][L]+1;
			for(j=0;j<L;++j)
			if(f[i][j]>=0)
			for(k='A';k<='Z';++k)
			if(num[k])
			{
				for(u=j;u&&s[u+1]!=k;u=fail[u]);
				if(s[u+1]==k)++u;
				if(f[i][j]>f[i+1][u])f[i+1][u]=f[i][j];
			}
		}
		Max=0;
		for(i=0;i<=L;++i)if(f[S][i]>Max)Max=f[S][i];
		for(i=1;i<=L;++i)ans*=((double)num[s[i]])/K;
		++Case;
		printf("Case #%d: %.10lf\n",Case,Max-ans);
	}
}
