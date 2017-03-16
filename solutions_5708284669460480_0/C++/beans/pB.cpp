#include<bits/stdc++.h>
#define DB double 
int K,L,S,Max;
char Key[101],Tar[101];
int fail[101];
DB POS[26];
struct Matrix
{
	DB v[101][101];
}M;
Matrix mul(Matrix a,Matrix b)
{
	Matrix ret;
	for(int i=0;i<=L;i++)
		for(int j=0;j<=L;j++)
		{
			ret.v[i][j]=0;
			for(int k=0;k<=L;k++)
			{
				ret.v[i][j]+=a.v[i][k]*b.v[k][j];
			}
		}
	return ret;
}
void build_fail(char *s,int *f)
{
	f[0]=f[1]=0;
	for(int i=1;s[i];i++)
	{
		int u=f[i];
		while(u&&s[u]!=s[i])u=f[u];
		f[i+1]=s[u]==s[i]?u+1:0;
	}
}
void build_M()
{
	for(int i=0;i<=L;i++)
		for(int j=0;j<=L;j++)
		{
			M.v[i][j]=0;
		}
	for(int i=0;i<L;i++)
		for(int j=0;j<26;j++)
		{
			if(Tar[i]=='A'+j)
			{
				M.v[i+1][i]+=POS[j];
			}
			else
			{
				int k=fail[i];
				while(k&&Tar[k]!='A'+j)k=fail[k];
				if(Tar[k]=='A'+j)k++;
				M.v[k][i]+=POS[j];
			}
		}
	M.v[fail[L]][L-1]+=POS[Tar[L-1]-'A'];
	M.v[L][L]+=1;
}
Matrix I()
{
	Matrix ans;
	for(int i=0;i<=L;i++)
	{
		for(int j=0;j<=L;j++)
		{
			ans.v[i][j]=0;
		}
		ans.v[i][i]=1;
	}
	return ans;
}
Matrix pow(Matrix o,int b)
{
	Matrix ans=I();
	Matrix a;
	for(int i=0;i<=L;i++)
	{
		for(int j=0;j<=L;j++)
		{
			a.v[i][j]=o.v[i][j];
		}
	}
	while(b)
	{
		if(b&1)
		{
			ans=mul(ans,a);
		}
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
DB solve()
{
	build_fail(Tar,fail);
	build_M();
	Matrix A=pow(M,S);
	bool impos=false;
	for(int i=0;i<L;i++)
	{
		if(POS[Tar[i]-'A']==0)
		{
			impos=true;
			break;
		}
	}
	if(impos)Max=0;
	else
	{
		Max=0;
		S-=L;
		if(S>=0)Max++;
		while(S>=L-fail[L])
		{
			S-=L-fail[L];
			Max++;
		}
	}
	return Max-A.v[L][0];
}
int main()
{
	//freopen("smallB.in","r",stdin);
	//freopen("smallB.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%s%s",&K,&L,&S,Key,Tar);
		for(int i=0;i<26;i++)POS[i]=0;
		for(int i=0;i<K;i++)POS[Key[i]-'A']+=1;
		for(int i=0;i<26;i++)POS[i]/=K;
		printf("Case #%d: %.7f\n",++kase,solve());
	}
	return 0;
}
