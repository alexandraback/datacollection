#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int Maxn=100;

int list[Maxn][10];
int sub[Maxn][Maxn];
int use[Maxn][Maxn];
int cur[10];
int R,N,M,K,tot,cnt;

void Make(int tot,int dep,int mul)
{
	if (dep==4)
	{
		sub[tot][++cnt]=mul;
		return;
	}
	Make(tot,dep+1,mul);
	Make(tot,dep+1,mul*list[tot][dep]);
}

void Dfs(int dep)
{
	if (dep==4)
	{
		++tot;
		for (int i=1;i<=4;++i) list[tot][i]=cur[i];
		cnt=0;
		Make(tot,1,1);
		return;
	}
	for (int i=2;i<=5;++i)
	{
		cur[dep]=i;
		Dfs(dep+1);
	}
}

void Prepare()
{
	tot=0;
	Dfs(1);
}

void Work()
{
	int Test;
	scanf("%d",&Test);
	printf("Case #1:\n");
	scanf("%d%d%d%d",&R,&N,&M,&K);
	for (int ii=0;ii<R;++ii)
	{
		memset(use,0,sizeof(use));
		for (int i=0;i<K;++i)
		{
			int v;
			scanf("%d",&v);
			for (int j=1;j<=tot;++j)
			{
				bool find=false;
				for (int k=1;k<=8;++k)
					if (!use[j][k] && sub[j][k]==v)
					{
						find=true;
						++use[j][k];
						break;
					}
				if (find) continue;
				for (int k=1;k<=8;++k)
					if (sub[j][k]==v)
					{
						++use[j][k];
						break;
					}
			}
		}
		int opt=-1,t=-1;
		for (int i=1;i<=tot;++i)
		{
			int sum=0,z=0;
			for (int j=1;j<=8;++j)
			{
				sum+=use[i][j];
				z+=(use[i][j]!=0);
			}
			if (sum==K && z>opt) 
			{
				opt=z;t=i;
			}
		}
		for (int i=1;i<=N;++i) printf("%d",list[t][i]);
		printf("\n");
	}
}

int main()
{
	freopen("C1.in","r",stdin);
	freopen("C1.out","w",stdout);

	Prepare();

	Work();
	
	return 0;
}
