#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i <= k ; ++i )
#define drep( i, j, k ) for( i = j ; i >= k ; --i )
#define Maxn 1015

struct node
{
	int v1, v2, fr ; 
}R[Maxn] ;
int ans, money, n, Q ;
bool vis[Maxn] ;

inline bool cmp ( node a, node b )
{
	return ( ( a.v2 < b.v2 ) || ( a.v2 == b.v2 && a.v1 < b.v1 ) ) ; 	
}

int main()
{
	int t, i, p, j, pos ;
	
	freopen("B-small-attempt0.in","r",stdin) ;
	freopen("output.txt","w",stdout) ;
	
	for( scanf("%d", &Q ), t = 1 ; t <= Q ; ++t )
	{
		ans = money = 0 ; 
		p = 1 ; 
		memset( vis, 0, sizeof( vis ) ) ; 
		printf("Case #%d: ",t) ; 
		
		scanf("%d", &n) ; 
		rep( i, 1, n )
		{
			scanf("%d%d", &R[i].v1, &R[i].v2 ) ;
			R[i].fr = i ; 
		}
		sort( R+1, R+1+n, cmp ) ; 
		rep( i, 1, n )
		{
			while( money < R[i].v2 ) 
			{
				pos = 0 ; 
				drep( j, n, 1 )
					if( vis[R[j].fr] == 0 && R[j].v1 <= money )
					{
						pos = j ; 
						break ; 
					}
				if( ! pos )
					break ; 
				else 
				{
					++ money ;
					vis[R[pos].fr] = 1 ;
					++ ans ; 
				}
			}
			
			if( money >= R[i].v2 )
			{
				money += 2 - vis[R[i].fr] ; 
				vis[R[i].fr] = 1 ; 
				++ ans ; 
			}	
			else 
			{
				ans = -1 ;
				break ; 	
			}
		}
		
		if( ans == -1 )
			printf("Too Bad\n") ;
		else 
			printf("%d\n",ans) ;
	}
//	system("pause") ;
	return 0 ;
}
