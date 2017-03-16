#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int SIZE_N = 1000000 + 10 ;

FILE *in , *out ;

int T ;
int n , x , y ;

double C[2000][2000] ;

double f(int nn , int i , int j)
{
	return C[nn][i] ;
}

void clear(void)
{
}

int main(void)
{
	C[0][0] = 1 ;
	for(int i = 1 ; i < 2000 ; ++i)
	{
		for(int j = 0 ; j <= i ; ++j)
		{
			if(j == 0 || j == i) C[i][j] = 1 ;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1] ;
		}
	}
	
	printf("%lf\n" , C[1000][500] + C[1000][500]) ;
	
	out = fopen("b.out" , "w") ;
	
	scanf("%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count , clear())
	{
		scanf("%d%d%d" , &n , &x , &y) ;
		if(x < 0) x = -x ;
		
		int k = 1 ;
		for( ; (k + 1) * (k + k + 1) <= n ; ++k) ;
		
		if((x + y) / 2 + 1 <= k)
		{
			fprintf(out , "Case #%d: 1.0\n" , count) ;
			continue ;
		}
		
		if((x + y) / 2 + 1 > k + 1 || x == 0)
		{
			fprintf(out , "Case #%d: 0.0\n" , count) ;
			continue ;
		}
		
		int nn = n - k * (k + k - 1) ;
		int m = 2 * (k - 0) ;
		++y ;
		
		//printf("=%d %d\n" , nn , k) ;
		
		double ans1 = 0 , ans2 = 0 ;
		for(int i = 0 ; i <= m ; ++i)
		{
			int j = nn - i ;
			if(j < 0 || m < j) continue ;
			if(i >= y) ans1 += f(nn , i , j) ;
			ans2 += f(nn , i , j) ;
		}
		
		printf("%lf\n%lf\n" , ans1 , ans2) ;
		
		fprintf(out , "Case #%d: %.10lf\n" , count , ans1 / ans2) ;
	}
	
	return 0 ;
}

