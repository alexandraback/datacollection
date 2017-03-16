#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define SIZE_N 1010

FILE *in , *out ;

int T , n , m ;
std::vector< int > edg[SIZE_N] ;

int vis[SIZE_N] ;
char ans[2][10] = {"No" , "Yes"} ;

int dfs(int now)
{
	vis[now] = 1 ;
	for(int i = 0 ; i < edg[now].size() ; ++i)
	{
		int ne = edg[now][i] ;
		if(vis[ne] == 1) return 1 ;
		if(dfs(ne) == 1) return 1 ;
	}
	return 0 ;
}

int main(void)
{
	in = fopen("A-large.in" , "r") ;
	out = fopen("pa.out" , "w") ;
	
	fscanf(in , "%d" ,&T) ;
	for(int count = 1 ; count <= T ; ++count)
	{
		fscanf(in , "%d" , &n) ;
		
		for(int i = 1 , t ; i <= n ; ++i)
		{
			fscanf(in , "%d" , &t) ;
			for(int a ; t > 0 ; --t)
			{
				fscanf(in , "%d" , &a) ;
				edg[i].push_back(a) ;
			}
		}
		//puts("xd") ;
		int dia = 0 ;
		for(int i = 1 ; dia == 0 && i <= n ; ++i)
		{
			for(int j = 1 ; j <= n ; ++j)
				vis[j] = 0 ;
			dia = dfs(i) ;
		}
		
		fprintf(out , "Case #%d: %s\n" , count , ans[dia]) ;
		
		for(int i = 1 ; i <= n ; ++i)
			edg[i].clear() ;
	}
	
	fclose(in) , fclose(out) ;
	
	return 0 ;
}
