#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

struct dat
{
	int x , y ;
	
	dat(int _x = 0 , int _y = 0)
	{
		x = _x , y = _y ;
	}
} ;

const int SIZE_N = 100 + 10 ;
const int SIZE_M = SIZE_N ;
const int SIZE_H = 100 + 10 ;

FILE *in , *out ;

int T , n , m ;
int map[SIZE_N][SIZE_M] ;

std::vector< dat > hei[SIZE_H] ;

int pat[SIZE_N][SIZE_M] ;
int cr[SIZE_N] , cc[SIZE_M] ;
int vr[SIZE_N] , vc[SIZE_M] ;

int valid(void)
{
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
		{
			if(pat[i][j] == 0) continue ;
			if(vr[i] == 0 && vc[j] == 0) return 0 ;
		}
	}
	return 1 ;
}

void clear(void)
{
	for(int i = 0 ; i <= n ; ++i)
	{
		cr[i] = vr[i] = 0 ;
		for(int j = 0 ; j <= m ; ++j)
		{
			map[i][j] = 0 ;
			pat[i][j] = 0 ;
			cc[j] = vc[j] = 0 ;
		}
	}
	for(int i = 0  ; i <= 100 ; ++i) hei[i].clear() ;
}

void update(int h)
{
	for(int i = 0 ; i < hei[h].size() ; ++i)
	{
		dat now = hei[h][i] ;
		int x = now.x , y = now.y ;
		vr[x] = 0 , vc[y] = 0 , pat[x][y] = 0 ;
	}
}

int main(void)
{
	//in = fopen("b.in" , "r") ;
	in = fopen("B-small-attempt3.in" , "r") ;
	out = fopen("b.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count , clear())
	{
		fscanf(in , "%d%d" , &n , &m) ;
		for(int i = 1 ; i <= n ; ++i)
		{
			for(int j = 1 ; j <= m ; ++j)
			{
				fscanf(in , "%d" , &map[i][j]) ;
				hei[map[i][j]].push_back(dat(i , j)) ;
			}
		}
		
		int ok = 1 ;
		for(int i = 0 ; i <= n ; ++i)
			for(int j = 0 ; j <= m ; ++j) pat[i][j] = 1 ;
		for(int i = 0 ; i <= n ; ++i) cr[i] = m , vr[i] = 1 ;
		for(int i = 0 ; i <= m ; ++i) cc[i] = n , vc[i] = 1 ;
		
		for(int i = 100 ; i >= 1 ; --i)
		{
			if(valid() == 0)
			{
				ok = 0 ;
				break ;
			}
			update(i) ;
		}
		
		fprintf(out , "Case #%d: %s\n" , count , ok == 1 ? "YES" : "NO") ;
	}
	
	return 0 ;
}

