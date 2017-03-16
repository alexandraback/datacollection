#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;
int st[10]={0},fl;
int n,m,edge[10][10]={0};
char zip[10][8];
char ans[200];
int used[10];
int cur[10];
void init(void)
{
	int i,j;
	fl = 0;
	for (i=0;i<10;i++)
		st[i] = 0;
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			edge[i][j] = 0;
}
bool possible(void)
{
	int i=0,x,start;
	deque<int> q;
	q.push_back(cur[0]);
	while(!q.empty() && i<n-1)
	{
		x = q.back();
		if (edge[x][cur[i+1]]==1)
		{
			q.push_back(cur[i+1]);
			i++;
		}
		else
			q.pop_back();
	}
	if (i==n-1)
		return true;
	else
		return false;

}
void perm(int index)
{
	int i;
	char tmp[200];
	if (index==n)
	{
		for (i=1;i<=n;i++)
			used[i] = 0;
		if (possible())
		{
			strcpy(tmp,zip[cur[0]]);
			for (i=1;i<n;i++)
				strcat(tmp,zip[cur[i]]);
			if (fl==0)
			{
				strcpy(ans,tmp);
				fl = 1;
			}
			else if (strcmp(tmp,ans) < 0)
				strcpy(ans,tmp);
		}
	}
	for (i=1;i<=n;i++)
		if (st[i]==0)
		{
			st[i] = 1;
			cur[index] = i;
			perm(index+1);
			st[i] = 0;
		}
	return;
}
int main()
{
	int t,ca=0,i,j,u,v;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		scanf("%d%d%c",&n,&m,&ch);
		init();
		for (i=1;i<=n;i++)
			scanf("%s",zip[i]);
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			edge[u][v] = edge[v][u] = 1;
		}
		cur[0]=5;
		cur[1]=2;
		cur[2]=1;
		cur[3]=4;
		cur[4]=3;
//		if (possible())
//			printf("Yes\n");
		perm(0);
		printf("Case #%d: %s\n",ca,ans);
	}
	return 0;
}
