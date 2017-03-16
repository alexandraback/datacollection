#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int MOD = 1000000007;
const int N = 10005;
int main()
{
	freopen("D-small-attempt3.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		int flag=0;
		int x,n,m;
		scanf("%d%d%d",&x,&n,&m);
		if(n*m%x)flag=0;
		else if(x<=2)flag=1;
		else if(x==4)
		{
			if(n>=3&&m>=3)flag=1;
			else flag=0;
		}
		else
		{
			if(n>=2&&m>=2)flag=1;
			else flag=0;
		}
		if(flag)puts("GABRIEL");
		else puts("RICHARD");
	}
	return 0;
}
