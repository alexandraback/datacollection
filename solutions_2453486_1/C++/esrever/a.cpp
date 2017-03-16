#include <cstdio>
#include <cstdlib>
#include <algorithm>

FILE *in , *out ;

int T ;
char map[10][10] ;

int win(int i , int t , int cc)
{
	char c = (cc == 0 ? 'O' : 'X') ;
	
	if(t == 0)
	{
		int ok = 1 ;
		for(int j = 0 ; j < 4 ; ++j)
			if(map[i][j] != c && map[i][j] != 'T') ok = 0 ;
		return ok ;
	}
	if(t == 1)
	{
		int ok = 1 ;
		for(int j = 0 ; j < 4 ; ++j)
			if(map[j][i] != c && map[j][i] != 'T') ok = 0 ;
		return ok ;
	}
	if(t == 2)
	{
		if(i == 0)
		{
			for(int j = 0 ; j < 4 ; ++j)
				if(map[j][j] != c && map[j][j] != 'T') return 0 ;
			return 1 ;
		}
		if(i == 1)
		{
			for(int j = 0 ; j < 4 ; ++j)
				if(map[j][3 - j] != c && map[j][3 - j] != 'T') return 0 ;
			return 1 ;
		}
		return 0 ;
	}
	return 0 ;
}

int main(void)
{
	in = fopen("A-large.in" , "r") ;
	out = fopen("a.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count)
	{
		for(int i = 0 ; i < 4 ; ++i)
			fscanf(in , "%s" , map[i]) ;
		
		int ow = 0 , xw = 0 ;
		for(int i = 0 ; i < 4 ; ++i)
		{
			ow |= win(i , 0 , 0) ;
			ow |= win(i , 1 , 0) ;
			ow |= win(i , 2 , 0) ;
			xw |= win(i , 0 , 1) ;
			xw |= win(i , 1 , 1) ;
			xw |= win(i , 2 , 1) ;
		}
		
		int cnt = 0 ;
		for(int i = 0 ; i < 4 ; ++i)
			for(int j = 0 ; j < 4 ; ++j)
				cnt += (map[i][j] == '.') ;
		
		fprintf(out , "Case #%d: " , count) ;
		if(ow == 1) fprintf(out , "O won") ;
		else if(xw == 1) fprintf(out , "X won") ;
		else if(cnt != 0) fprintf(out , "Game has not completed") ;
		else fprintf(out , "Draw") ;
		fprintf(out , "\n") ;
	}
	
	return 0 ;
}

