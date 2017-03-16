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

int E,R,n;
int v[50];
int ans;

void dfs(int x,int d,int e)
{
	if (x>n)
	{
		ans = max(d,ans);
		return;
	}

	for (int i=0;i<=e;i++)
		dfs(x+1,d+i*v[x],min(E,e-i+R));
}

int main()
{
    freopen("C:\\Users\\py\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\py\\Desktop\\output.txt","w",stdout);

    int tt;
    scanf("%d",&tt);
    for (int id=1;id<=tt;id++)
    {
    	scanf("%d%d%d",&E,&R,&n);
    	for (int i=1;i<=n;i++)
    		scanf("%d",&v[i]);
    	ans = 0;
    	dfs(1,0,E);
    	printf("Case #%d: %d\n",id,ans);
    }

    return 0;
}
