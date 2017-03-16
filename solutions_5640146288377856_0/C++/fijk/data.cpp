#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
#define LL long long
#define For(i,n) for(int (i)=1;(i)<=(n);(i)++)
FILE*f1;
int d[1010];

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T,n,m,w;
	scanf("%d",&T);
	For(tcase,T)
	{
		printf("Case #%d: ",tcase);
		scanf("%d%d%d",&n,&m,&w);
		printf("%d\n",n*m/w+((m%w)!=0)+w-1);
	}
    return 0;
} 
