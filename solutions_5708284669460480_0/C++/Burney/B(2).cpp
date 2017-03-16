#include<cstdio>
int T,K,L,S,MAX;
char KEY[101],TAR[101];
int FAIL[101];
double POS[26];
struct Matrix
{
	double v[101][101];
	void show()
	{
		for(int i=0;i<=L;i++)
		{
			for(int j=0;j<=L;j++)
			{
				printf("\t%.3lf",v[i][j]);
			}
			printf("\n");
		}
	}
}M;
Matrix mul(Matrix a,Matrix b)
{
	Matrix ans;
	for(int i=0;i<=L;i++)
	{
		for(int j=0;j<=L;j++)
		{
			ans.v[i][j]=0;
			for(int k=0;k<=L;k++)
			{
				ans.v[i][j]+=a.v[i][k]*b.v[k][j];
			}
		}
	}
	return ans;
}
void build_FAIL(char *s,int *f)
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
	{
		for(int j=0;j<=L;j++)
		{
			M.v[i][j]=0;
		}
	}
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(TAR[i]=='A'+j)
			{
				M.v[i+1][i]+=POS[j];
			}
			else
			{
				int k=FAIL[i];
				while(k&&TAR[k]!='A'+j)k=FAIL[k];
				if(TAR[k]=='A'+j)k++;
				M.v[k][i]+=POS[j];
			}
		}
	}
	M.v[FAIL[L]][L-1]+=POS[TAR[L-1]-'A'];
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
double solve()
{
	build_FAIL(TAR,FAIL);
//	printf("fail:");
//	for(int i=0;i<=L;i++)printf(" %d",FAIL[i]);printf("\n");
	build_M();
//	M.show();
//	for(int i=1;i<=S;i++)
//	{
//		printf("i=%d\n",i);
//		pow(M,i).show();
//	}
	Matrix A=pow(M,S);
//	printf("ans:");
//	for(int i=0;i<=L;i++)printf("\t%.3lf",A.v[i][0]);printf("\n");
	bool impos=false;
	for(int i=0;i<L;i++)
	{
		if(POS[TAR[i]-'A']==0)
		{
			impos=true;
			break;
		}
	}
	if(impos)MAX=0;
	else
	{
		MAX=0;
		S-=L;
		if(S>=0)MAX++;
		while(S>=L-FAIL[L])
		{
			S-=L-FAIL[L];
			MAX++;
		}
	}
//	printf("max=%d\n",MAX);
	return MAX-A.v[L][0];
}
int main()
{
	freopen("B.txt","r",stdin);
	freopen("B1.txt","w",stdout);
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d%d%d",&K,&L,&S);//keyboard, target word, attempt time
		scanf("%s%s",KEY,TAR);
		for(int i=0;i<26;i++)POS[i]=0;
		for(int i=0;i<K;i++)POS[KEY[i]-'A']+=1;
		for(int i=0;i<26;i++)POS[i]/=K;
		printf("Case #%d: %.7lf\n",kase++,solve());
//		break;
	}
	return 0;
}
