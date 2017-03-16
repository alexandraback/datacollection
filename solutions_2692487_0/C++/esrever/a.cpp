#include <cstdio>
#include <cstdlib>
#include <algorithm>

typedef long long lnt ;

const int SIZE_N = 100 + 10 ;
const int INF = 1000000000 ;

FILE *in , *out ;

int T ;
lnt n , st ;

lnt ary[SIZE_N] ;

int tmt[SIZE_N] ;

void clear(void)
{
	for(int i = 0 ; i <= n ; ++i) ary[i] = tmt[i] = 0 ;
	st = 0 ;
}

int main(void)
{
	in = fopen("A-small-attempt1.in" , "r") ;
	out = fopen("a.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count , clear())
	{
		fscanf(in , "%I64d%I64d" , &st , &n) ;
		for(int i = 1 ; i <= n ; ++i) fscanf(in , "%I64d" , ary + i) ;
		
		if(st == 1)
		{
			fprintf(out , "Case #%d: %I64d\n" , count , n) ;
			continue ;
		}
		
		std::sort(ary + 1 , ary + n + 1) ;
		
		int cnt = 0 ;
		for(int i = 1 ; i <= n ; ++i)
		{
			while(st <= ary[i]) st += st - 1 , ++cnt ;
			tmt[i] = cnt ;
			st += ary[i] ;
		}
		
		int ans = n ;
		for(int i = 1 ; i <= n ; ++i)
			ans = std::min((lnt)ans , tmt[i] + n - i) ;
		
		fprintf(out , "Case #%d: %d\n" , count , ans) ;
	}
	
	fclose(in) , fclose(out) ;
	
	return 0 ;
}

