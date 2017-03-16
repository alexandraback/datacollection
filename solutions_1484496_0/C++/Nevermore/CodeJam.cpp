#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>
using namespace std;

const int maxn = 2000000+10 ;
int n;
int vis[maxn];
int elem[20];


void work()
{
	int i , j , k ;
	for(i = 0; i < maxn; i++) 
		vis[i] = -1 ;

	for(i = 0; i < (1<<n); i++)
	{
		for(j = k = 0; j < n; j++) 
			if(i & (1<<j)) 
				k += elem[j];
		if(vis[k] != -1)
			break;
		vis[k] = i;
	}
	if(i == (1<<n)) 
	{
		puts("Impossible");
		return;
	}
	for(j = 0 ; j < n; j++) if (vis[k] & (1<<j)) printf("%d ",elem[j]);
	printf("\n");
	for(j = 0 ; j < n; j++) if (i & (1<<j)) printf("%d ",elem[j]);
	printf("\n");
}

int main()
{
	int i , t ,Case = 1;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
    {
		scanf("%d",&n);
		for(i = 0; i < n; i++) 
			scanf("%d",&elem[i]);
		printf("Case #%d:\n",Case++);
		work();
    }
	return 0;
}