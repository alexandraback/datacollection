#include<stdio.h>
#include<string.h>

int n, A, B;
int map[1005][1005];
int path[2005],back[2005],path_len;
int id_a[1005];
int id_b[1005];


int test[20], test2[20], ans2;
void recall(int lev)
{
	int i,chca[1005],chcb[1005],sum=0;
	if(lev==n+1)
	{
		for(i=1;i<=A;i++)
			chca[i]=0;
		for(i=1;i<=B;i++)
			chcb[i]=0;
		for(i=1;i<=n;i++)
		{
			if(chca[id_a[test2[i]]]==1 && chcb[id_b[test2[i]]]==1)
				sum++;
			chca[id_a[test2[i]]]=1;
			chcb[id_b[test2[i]]]=1;
		}
		if(ans2<sum)
			ans2=sum;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(test[i]==0)
		{
			test[i]=1;
			test2[lev]=i;
			recall(lev+1);
			test[i]=test2[lev]=0;
		}
	}
}

void dfs(int v)
{
	if(path[A+B+1]!=-1)
		return;
	int i;
	for(i=0;i<=A+B+1;i++)
	{
		if(map[v][i]==1 && path[i]==-1)
		{
			path[i]=v;
			dfs(i);
		}
	}
}

int main(void)
{
	int pp,ppp;
	int ans;
	int i,j,vv;
	char a[1005][20];
	char b[1005][20];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&ppp);
	for(pp=1;pp<=ppp;pp++)
	{
		A=0;
		B=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%s %s",&a[i][1],&b[i][1]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(strcmp(&a[i][1],&a[j][1])==0)
				{
					id_a[i]=id_a[j];
					break;
				}
			}
			if(j==i)
				id_a[i]=++A;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(strcmp(&b[i][1],&b[j][1])==0)
				{
					id_b[i]=id_b[j];
					break;
				}
			}
			if(j==i)
				id_b[i]=++B;
		}
		for(i=0;i<=A+B+1;i++)
		{
			for(j=0;j<=A+B+1;j++)
				map[i][j]=0;
		}
		for(i=1;i<=A;i++)
			map[0][i]=1;
		for(i=1;i<=B;i++)
			map[A+i][A+B+1]=1;
		for(i=1;i<=n;i++)
			map[id_a[i]][A+id_b[i]]=1;
		ans=0;
		while(1)
		{
			for(i=0;i<=A+B+1;i++)
				path[i]=-1;
			path[0]=0;
			dfs(0);
			if(path[A+B+1]==-1)
				break;
			ans++;
			path_len=1;
			back[1]=A+B+1;
			vv=A+B+1;
			while(1)
			{
				vv=path[vv];
				back[++path_len]=vv;
				if(vv==0)
					break;
			}
			for(i=1;i<path_len;i++)
			{
				map[back[i]][back[i+1]]=1;
				map[back[i+1]][back[i]]=0;
			}
		}
		printf("Case #%d: %d\n",pp,n-(A+B-ans));
		if(n==0)
		{
			ans2=0;
			recall(1);
			printf("%d\n",ans2);
			if(ans2!=n-(A+B-ans))
				printf("jijiji\n");
		}
	}
}