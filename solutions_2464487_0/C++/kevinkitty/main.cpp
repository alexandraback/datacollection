#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef __int64 Uint;
const int MAX=500005;
const int N=1005;
int f(int r,int n)
{
	return (2*n+2*r-1)*n;
}
int erfen(int low,int high,int r,int t)
{
	int n;
	int mid;
	int tmp;
	while(true)
	{
	mid=(low+high)>>1;
	tmp=f(r,mid);
	if(tmp>t)high=mid;
	else low=mid;
	if(low==high || high==low+1)return (low+high)>>1;
	}
}
int main()
{
	int T,cse=0;
	int r,t;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
	scanf("%d%d",&r,&t);
	int ret=erfen(0,t,r,t);
	printf("Case #%d: ",++cse);
	printf("%d\n",ret);
	}
return 0;
}
/*

5
1 9
1 10
3 40
*/