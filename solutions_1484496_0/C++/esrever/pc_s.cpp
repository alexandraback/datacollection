#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>

#define F first
#define S second

#define SIZE_N 25
#define SIZE_M 1100000

typedef std::pair< int , int > pii ;
pii mp(int a , int b){return std::make_pair(a , b) ;}

FILE *in , *out ;

int T , n ;
int ary[SIZE_N] ;
pii sum[SIZE_M] ;

int main(void)
{
	in = fopen("C-small-attempt0.in" , "r") ;
	out = fopen("pc.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count)
	{
		fprintf(out , "Case #%d:\n" , count) ;
		
		fscanf(in  ,"%d" , &n) ;
		for(int i = 0 ; i < n ; ++i)
			fscanf(in , "%d" , &ary[i]) ;
		
		std::sort(ary , ary + n) ;
		
		for(int i = 0 ; i < (1 << n) ; ++i)
		{
			sum[i] = mp(0 , i) ;
			for(int j = 0 ; j < n ; ++j)
			{
				if((i & (1 << j)) == 0) continue ;
				sum[i].F += ary[j] ;
			}
		}
		
		std::sort(sum , sum + (1 << n)) ;
		
		int flag = 0 ;
		for(int i = 1 ; flag == 0 && i < (1 << n) ; ++i)
		{
			if(sum[i].F != sum[i - 1].F) continue ;
			if((sum[i].S & sum[i - 1].S) != 0) continue ;
			//printf("%d %d\n" , sum[i].F , sum[i - 1].F) ;
			flag = 1 ;
			//*
			for(int t = sum[i].S , j = 0 ; t != 0 ; ++j)
			{
				if((t & (1 << j)) == 0) continue ;
				t -= (1 << j) ;
				fprintf(out , "%d%c" , ary[j] , (t == 0) ? '\n' : ' ') ;
			}
			
			for(int t = sum[i - 1].S , j = 0 ; t != 0 ; ++j)
			{
				if((t & (1 << j)) == 0) continue ;
				t -= (1 << j) ;
				fprintf(out , "%d%c" , ary[j] , (t == 0) ? '\n' : ' ') ;
			}
			/**/
			/*
			for(int j = 0 ; j < n ; ++j)
			{
				if((sum[i - 1].S & (1 << j)) == 0) continue ;
				fprintf(out , "%d " , ary[j]) ;
			}
			fprintf(out , "\n") ;
			for(int j = 0 ; j < n ; ++j)
			{
				if((sum[i].S & (1 << j)) == 0) continue ;
				fprintf(out , "%d " , ary[j]) ;
			}
			fprintf(out , "\n") ;
			/**/
		}
		if(flag == 0)
			fprintf(out , "Impossible\n") ;
	}
	
	fclose(in) , fclose(out) ;
	
	return 0 ;
}
