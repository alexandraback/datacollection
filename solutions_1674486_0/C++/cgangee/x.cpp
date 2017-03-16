#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

const int N=1000;

struct node{
	int name;
	node *next;
};

int i,j,k,m,n,l;
node *a[N+10];
int f[N+10];
bool v[N+10];

void add(int i,int j)
{
	node *p=(node *)malloc(sizeof(node));
	p->name=j;
	p->next=a[i];
	a[i]=p;
}

bool dfs(int i)
{
    v[i]=true;
	for (node *p=a[i]; p!=NULL; p=p->next)
	{
		if (v[p->name] || dfs(p->name))
			return true;		
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		scanf("%d", &n);
		for (i=1; i<=n; i++)
		{
			a[i]=NULL;
			f[i]=0;
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &k);
			for (j=1; j<=k; j++)
			{
				scanf("%d", &l);
				add(i,l);
				f[l]++;
			}
		}
		bool flag=false;
		for (i=1; i<=n; i++)
			if (f[i]==0)
			{
                memset(v,0,sizeof(v));
				if (dfs(i))
				{
					flag=true;
					break;
				}
            }
		printf("Case #%d: ",t);
		if (flag)
			printf("Yes\n");
		else 
			printf("No\n");
					
	}
	return 0;
}
