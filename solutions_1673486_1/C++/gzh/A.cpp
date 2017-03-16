#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i <= k ; ++i )
#define Maxn 100005

int Q, A, B ; 
double sumP, P[Maxn], ans, pre[Maxn] ;

int main()
{
	int t, i, j ; 
	
	freopen("A-large.in","r",stdin) ;
	freopen("output.txt","w",stdout) ; 
	
	for( scanf("%d", &Q), t = 1 ; t <= Q ; ++t )
	{
		ans = 312346573210357430237432.0 ; 
		printf("Case #%d: ",t) ; 
		
		scanf("%d%d", &A, &B) ; 
		pre[0] = 1.0 ; 
		rep( i, 1, A )
		{
			scanf("%lf", &P[i]) ; 
			pre[i] = pre[i-1] * P[i] ; 
		}
			
		rep( i, 0, A-1 ) // É¾ i¸ö¡£
		{
			sumP = pre[A-i] ;  
			ans = min( ans, sumP * ( 1.0+B-A+i+i ) + ( 1.0-sumP ) * ( 2.0+B-A+B+i+i ) ) ;
		} 
		ans = min( ans, 2.0+B ) ; 
		printf("%.6lf\n",ans) ; 
	}
	return 0 ; 	
}
