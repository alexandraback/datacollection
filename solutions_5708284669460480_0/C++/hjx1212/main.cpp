#include<bits/stdc++.h>
using namespace std;

char a[105],b[105];
double s[105][105][105];
bool f[105][105][105];
double p[26];
int nxt[105];
void find_nxt(char* a)
{
	nxt[0]=0;
	for(int i=1;a[i];i++)
	{
		int j=nxt[i-1];
		while(a[j]!=a[i]&&j>0)
			j=nxt[j-1];
		if(a[j]==a[i])
			nxt[i]=j+1;
		else nxt[i]=0;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t,K,L,S,i,j,k,l,m;
	double ans;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		scanf("%d%d%d%s%s",&K,&L,&S,a,b);
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		find_nxt(b);
		for(i=0;i<K;i++)
			p[a[i]-'A']+=1.0;
		for(i=0;i<26;i++)
			p[i]/=K;
		f[0][0][0]=1,s[0][0][0]=1.0;
		for(ans=i=0;i<S;i++)
			for(j=0;j<L;j++)
				for(k=0;k<=S;k++)
					if(f[i][j][k])
						for(l=0;l<26;l++)
							if(p[l]>0.0)
							{
								for(m=j;m;m=nxt[m-1])
									if(b[m]-'A'==l)
										break;
								if(b[m]-'A'==l)
									m++;
								if(m>=L)
								{
									m=nxt[m-1];
									f[i+1][m][k+1]=1;
									s[i+1][m][k+1]+=s[i][j][k]*p[l];
									ans=max(ans,1.0*(k+1));
								}
								else
								{
									f[i+1][m][k]=1;
									s[i+1][m][k]+=s[i][j][k]*p[l];
								}
							}
		for(j=0;j<L;j++)
			for(k=0;k<=S;k++)
				if(f[i][j][k])
					ans-=s[i][j][k]*k;
		printf("Case #%d: %.10f\n",t,ans);
	}
}
