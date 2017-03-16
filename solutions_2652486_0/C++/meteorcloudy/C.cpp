#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define maxn
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

int R,N,M,K;

ll p[50];

ll a[1000][4200];
int v[100];
int top;

void find(int x)
{
	a[x][0]=521;

	for (int i=0;i<=top;i++)
	{
		a[x][i+1]=1;
		int tmp = i;
		int flag = 1;
		while (tmp)
		{
			a[x][i+1]*=(tmp%2==0?1:v[flag]);
			flag++;
			tmp>>=1;
		}
	}
	sort(a[x]+1,a[x]+1+top);
}

void dfs(int d,int x)
{
	if (x>N)
	{
		find(d);
		return ;
	}
	for (int i=2;i<=M;i++)
	{
	    v[x]=i;
	    dfs(d*10+i,x+1);
	}

}

	int bsearch(ll *A,int l,int r,int x)
	{	int m;
		while (l<r)
		{	m=(l+r)/2;
			if (A[m]==x) return m;
			if (A[m]>x) r=m; else l=m+1;
		}
		return -1;
	}

int main()
{
    freopen("C:\\Users\\py\\Desktop\\input.txt","r",stdin);
    //freopen("C:\\Users\\py\\Desktop\\output.txt","w",stdout);

    int tt;
    scanf("%d",&tt);
    scanf("%d%d%d%d",&R,&N,&M,&K);
    printf("Case #1:\n");

    top = ((1<<N)-1);
    dfs(0,1);

    for (int id=1;id<=R;id++)
    {
    	for (int i=1;i<=K;i++)
    		scanf("%I64d",&p[i]);
    	for (int i=0;i<1000;i++)
    		if (a[i][0]==521)
    		{
    			bool flag = true;
    			for (int j=1;j<=K;j++)
    				if (bsearch(a[i],1,top+2,p[j])==-1)
    				{
    					flag=false;
    					break;
    				}
    			if (flag)
    			{
    				printf("%d\n",i);
    				goto fuck;
    			}
    		}
    	for (int i=1;i<=N;i++)
    		printf("2");
    	printf("\n");
    	fuck: {};
    }

    return 0;
}
