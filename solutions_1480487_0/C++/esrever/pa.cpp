#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define EPS 1e-9
#define MAX 1000
#define INF 999999

#define SIZE_N 210

FILE *in , *out ;

int T , n , s ;
int ary[SIZE_N] ;

int chk(double min , double lim)
{
	double sum = 0 ;
	for(int i = 1 ; i < n ; ++i)
		sum += std::max((double)(min - ary[i]) / s , .0) ;
	return sum < lim ;
}

double bs1(double le , double ri , double lim)
{
	for(int i = 0 ; i < MAX ; ++i)
	{
		double mi = (le + ri) / 2 ;
		int val = chk(mi , lim) ;
		if(val == 1) le = mi ;
		else ri = mi ;
	}
	return (le + ri) / 2 ;
}

double bs(double le , double ri)
{
	for(int i = 0 ; i < MAX ; ++i)
	{
		double mi = (le + ri) / 2 ;
		double val = bs1(0 , INF , 1 - mi) , tar = ary[0] + s * mi ;
		//printf("%.10lf %.10lf %.10lf %.10lf %.10lf\n" , le , ri , mi , val , tar) ;
		if(val < tar + EPS) ri = mi ;
		else le = mi ;
		//if(i == 100) system("pause") ;
	}
	return (le + ri) / 2 ;
}

int main(void)
{
	in = fopen("A-small-attempt0.in" , "r") ;
	out = fopen("pa.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count)
	{
		s = 0 ;
		
		fscanf(in , "%d" , &n) ;
		for(int i = 0 ; i < n ; ++i)
		{
			fscanf(in , "%d" , &ary[i]) ;
			s += ary[i] ;
		}
		
		fprintf(out , "Case #%d: " , count) ;
		//printf("Case #%d: " , count) ;
		for(int i = 0 ; i < n ; ++i)
		{
			std::swap(ary[0] , ary[i]) ;
			fprintf(out , "%.10lf%c" , bs(0 , 1) * 100 , (i + 1 == n) ? '\n' : ' ') ;
			std::swap(ary[0] , ary[i]) ;
		}
		//system("pause") ;
	}
	
	fclose(in) , fclose(out) ;
	
	return 0 ;
}
