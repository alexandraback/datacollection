#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T,L,K,S,len,cnt;
int sum[101],Sum;
int fail[101],tr[101][26];
char s[101];
double f[101][101][101],Ans;

int main()
{
	
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++)
	{
		scanf("%d%d%d",&K,&L,&S);
		Sum=0;
		for (int i=0;i<26;i++) sum[i]=0;
		scanf("%s",s+1); Sum=strlen(s+1);
		for (int i=1;i<=Sum;i++) sum[s[i]-'A']++;
		scanf("%s",s+1); len=strlen(s+1);
		for (int i=2;i<=len;i++)
		{
			int j=fail[i-1];
			for (;j&&s[j+1]!=s[i];j=fail[j]);
			if (s[j+1]==s[i]) fail[i]=j+1;
		}
		
		int now=0; int Max=0;
		for (int i=1;i<=S;i++)
		{
			if (sum[s[now+1]-'A']) now++;
			if (now==len) Max++,now=fail[len];
		}

		for (int i=0;i<=len;i++)
			for (int j=0;j<26;j++)
			{
				if (s[i+1]=='A'+j) tr[i][j]=i+1;
				else {
					for (tr[i][j]=fail[i];tr[i][j]&&s[tr[i][j]+1]!=j+'A';tr[i][j]=fail[tr[i][j]]);
					if (s[tr[i][j]+1]=='A'+j) tr[i][j]++;
				}
			}


		for (int i=0;i<=S;i++)
			for (int j=0;j<=len;j++)
				for (int k=0;k<=Max;k++) f[i][j][k]=0;

		f[0][0][0]=1;
		for (int i=0;i<S;i++)
		{
			for (int j=0;j<=len;j++)
				for (int k=0;k<=Max;k++)
				{
					for (int l=0;l<26;l++)
					{
						if (tr[j][l]==len) f[i+1][tr[j][l]][k+1]+=f[i][j][k]*sum[l]/K;
						else f[i+1][tr[j][l]][k]+=f[i][j][k]*sum[l]/K;
					}
				}
		}
		
//		printf("%lf\n",f[2][1][2]);
//		printf("%d\n",Max);
		
		Ans=0;
		for (int i=0;i<=len;i++)
			for (int k=0;k<=Max;k++)
			{
				Ans+=(Max-k)*f[S][i][k];
//				printf("%d %lf\n",k,f[S][i][k]);
			}
		printf("Case #%d: %.9lf\n",Case,Ans);
	}
}

