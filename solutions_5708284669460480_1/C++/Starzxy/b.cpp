#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,l;
char s1[110],s2[110];
int cnt[30];
long double f[110][110],h[110][110];
int pre[110];

inline int read()
{
	int c=getchar(),temp=0;
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)
	{
		temp=temp*10+c-48;
		c=getchar();
	}
	return temp;
}

inline void calc_pre()
{
	memset(cnt,0,sizeof(cnt));
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++)
		cnt[s1[i]-65]++;
	int k=pre[1]=0;
	for(int i=2;i<=m;i++)
	{
		while(k&&s2[k+1]!=s2[i])k=pre[k];
		if(s2[k+1]==s2[i])k++;
		pre[i]=k;
	}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b1.out","w",stdout);
	
	int T=read();
	for(int tt=1;tt<=T;tt++)
	{
		n=read();m=read();l=read();
		scanf("%s%s",s1+1,s2+1);
		calc_pre();
		int ans=0;int t=0;
		for(int i=1;i<=l;i++)
		{
			t++;
			if(t==m)
			{
				t=pre[t];
				ans++;
			}
		}
		bool flag=true;
		for(int i=1;i<=m;i++)
			if(!cnt[s2[i]-65])
			{
				flag=false;
				break;
			}
		if(!flag)
		{
			printf("Case #%d: 0.00000000\n",tt);
			continue;
		}
		for (int j=0;j<m;j++)
			for (int k=0;k<=l;k++)
				f[j][k]=(long double)0.0;
		f[0][0]=(long double)1.0;
		for (int i=1;i<=l;i++)
		{
			for(int j=0;j<m;j++)
				for(int g=0;g<=l;g++)
					h[j][g]=(long double)0.0;
			for(int j=0;j<m;j++)
				for(int g=0;g<=ans;g++)
					for(int k=0;k<26;k++)
						if(cnt[k])
						{
							int t=j,x=g;
							while(t&&s2[t+1]-65!=k)t=pre[t];
							if(s2[t+1]-65==k)t=t+1;
							if(t==m){t=pre[t];x+=1;}
							h[t][x]+=(long double)f[j][g]*cnt[k]/n;
						}
			for(int j=0;j<m;j++)
				for(int g=0;g<=l;g++)
					f[j][g]=(long double)h[j][g];
		}
		long double tmp=(long double)0.0;
		for(int i=0;i<m;i++)
			for(int j=0;j<=l;j++)
				tmp+=(long double)f[i][j]*j;
		printf("Case #%d: %.8lf\n",tt,(double)ans-(double)tmp);
	}
	return 0;
}

