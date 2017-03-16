#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

char s1[110],s2[110];
int ok[30];
int dp[110],dp2[110];
long double dp3[110][110],dp4[110][110];
int pre[110];

int main()
{
	#ifdef waltz
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int test;scanf("%d",&test);
	for (int tt=1;tt<=test;tt++)
	{
		int n,m,l;scanf("%d%d%d",&n,&m,&l);
		scanf("%s%s",s1+1,s2+1);
		memset(ok,0,sizeof(ok));
		memset(pre,0,sizeof(pre));
		for (int i=1;i<=n;i++) ok[s1[i]-65]++;
		int k=pre[1]=0;
		for (int i=2;i<=m;i++)
		{
			while (k&&s2[k+1]!=s2[i]) k=pre[k];
			if (s2[k+1]==s2[i]) k++;
			pre[i]=k;
		}
		int ans=0;int t=0;
		for (int i=1;i<=l;i++)
		{
			t++;
			if (t==m) {t=pre[t];ans++;}
		}
		bool v=1;
		for (int i=1;i<=m;i++) if (!ok[s2[i]-65]) {v=0;break;}
		if (!v) {printf("Case #%d: 0.000000\n",tt);continue;}
		for (int j=0;j<m;j++)
			for (int k=0;k<=l;k++)
				dp3[j][k]=(long double)0.0;
		dp3[0][0]=(long double)1.0;
		for (int i=1;i<=l;i++)
		{
			for (int j=0;j<m;j++)
				for (int g=0;g<=l;g++)
					dp4[j][g]=(long double)0.0;
			for (int j=0;j<m;j++)
				for (int g=0;g<=ans;g++)
					for (int k=0;k<26;k++)
						if (ok[k])
						{
							int t=j,x=g;
							while (t&&s2[t+1]-65!=k) t=pre[t];
							if (s2[t+1]-65==k) t++;
							if (t==m) {t=pre[t];x+=1;}
							dp4[t][x]+=(long double)dp3[j][g]*ok[k]/n;
						}
			for (int j=0;j<m;j++)
				for (int g=0;g<=l;g++)
					dp3[j][g]=(long double)dp4[j][g];
		}
		long double tmp=(long double)0.0;
		for (int i=0;i<m;i++)
			for (int j=0;j<=l;j++)
				tmp+=(long double)dp3[i][j]*j;
		printf("Case #%d: %.8lf\n",tt,(double)ans-(double)tmp);
	}
	return 0;
}

