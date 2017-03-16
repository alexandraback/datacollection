#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#define eps 1e-8
#define MOD 1000000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1010
using namespace std;

int prime[1000010], cnt;
bool flag[1000010];
char que[20];
vector<int> d;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int t;
	int k, c, s;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d: ",ii);
		for(int i = 1; i <= k; i ++)
		{
			printf("%d",i);
			if(i == k)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	return 0;
}