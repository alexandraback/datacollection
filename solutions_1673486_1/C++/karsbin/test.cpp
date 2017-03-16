#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100001 ;
const double precision = 1e-8 ; 
double p[maxn] , s[maxn] ;
int a , b ;

inline double get_min(double x,double y)	{	return x < y ? x : y ;	}

inline double solve()
{
	int i , j , k ;
	double ans = b + 2.0 ;
	ans = get_min( ans , s[a] * (b-a+1) + (1.0-s[a])*(2*b-a+2.0) );
	for ( i = 1 ; i < a ; i++)
	{
		ans = get_min(ans,s[a-i]*(2*i+1.+b-a)+(1-s[a-i])*(2.*i+2.+2.*b-a));
	}
	return ans ;
}

int main()
{
	int n , i , j , k , t ;
	freopen("b.in","r",stdin);
	freopen("outb.txt","w",stdout);
	scanf("%d",&t);
	for ( i = 1 ; i <= t ; i++)
	{
		scanf("%d%d",&a,&b);
		for ( j = 1 , s[0] = 1.0 ; j <= a ; j++)	scanf("%lf",&p[j]) , s[j] = s[j-1] * p[j] ;
		printf("Case #%d: %.6lf\n",i,solve()+precision);
	}
}