#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<deque>
#include<functional>
#include<iterator>
#include<vector>
#include<list>
#include<map>
#include<memory>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#define abs(a) ((a>0)?(a):-(a))
#define sgm(a) (a==0?(0):((a>0)?(1):(-1)))
#define sqr(a) ((a)*(a))
#define swap(a,b,lx) {lx t;t=a;a=b;b=t;}
#define oo 0xfffffff
using namespace std;
int N,M,K,T;
inline int rd(int a)
{
		long long b=((long long)rand()+1)*((long long)rand()+1)*((long long)rand()+1)%100000007*(rand()+1)%a+1; 
		return(b);
}
void work()
{
	double C,F,X;
	scanf("%lf%lf%lf",&C,&F,&X);
	double f=0;
	double ans=X/2.00;
	for(int i=1;i<=10000;i++)
	{
		f=f+C/((i-1)*F+2.00);
		ans=min(ans,f+X/(i*F+2.00));
	}
	printf("%0.7lf",ans);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,l;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		work();
		printf("\n");
	}
    return(0);
}
