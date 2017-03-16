#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define SIZE_N 2010

FILE *in , *out ;

int T , n , a ;
double d ;
double tim[SIZE_N] , dis[SIZE_N] , ace[SIZE_N] ;

int main(void)
{
	in = fopen("B-small-attempt0.in" , "r") ;
	out = fopen("pb.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count)
	{
		fscanf(in , "%lf%d%d" , &d , &n , &a) ;
		for(int i = 0 ; i < n ; ++i)
			fscanf(in , "%lf%lf" , &tim[i] , &dis[i]) ;
		for(int i = 0 ; i < a ; ++i)
			fscanf(in , "%lf" , &ace[i]) ;
		
		fprintf(out , "Case #%d:\n" , count) ;
		for(int que = 0 ; que < a ; ++que)
		{
			double nowa = ace[que] ;
			if(n == 1)
			{
				fprintf(out , "%.10lf\n" , sqrt(2 * d / nowa)) ;
			}
			else
			{
				if(dis[0] >= d)
					fprintf(out , "%.10lf\n" , sqrt(2 * d / nowa)) ;
				else
				{
					double t1 = sqrt(2 * d / nowa) ;
					double t2 = (tim[1] - tim[0]) / (dis[1] - dis[0]) * (d - dis[0]) ;
					fprintf(out , "%.10lf\n" , std::max(t1 , t2)) ;
				}
			}
		}
	}
	
	fclose(in) , fclose(out) ;
	
	return 0 ;
}
