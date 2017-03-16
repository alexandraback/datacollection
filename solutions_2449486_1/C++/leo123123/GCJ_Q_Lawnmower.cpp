#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

int yard[105][105] ;

int row_max[105] ;
int col_comp[105] ;
int flag[105] ;

int comp_yard[105][105] ;

int main()
{	
	freopen("D:\\B.in","r",stdin);
	freopen("D:\\B.out","w",stdout);
	int cas ;
	scanf("%d",&cas);
	for( int c = 1 ; c <= cas ; c ++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(row_max,0,sizeof(row_max));
		memset(flag,0,sizeof(flag));
		for( int i = 0 ; i < n ; i ++ )
		{
			for( int j = 0 ; j < m ; j ++ )
			{
				scanf("%d",&yard[i][j]);
				row_max[i] = max(yard[i][j],row_max[i]);
			}
		}
		for( int i = 0 ; i < m ; i ++ )
		{
			int flag1;
			for( int test = 100 ; test > 0 ; test -- )
			{
				flag1 = 1 ;
				memset(col_comp,0,sizeof(col_comp));
				for( int j = 0 ; j < n ; j ++ )
				{
					if( test < row_max[j] )
					{
						col_comp[j] = test ;
					}
					else
					{
						col_comp[j] = row_max[j] ;
					}
				}
				for( int j = 0 ; j < n ; j ++ )
				{
					if( col_comp[j] != yard[j][i])
					{
						flag1 = 0 ;
						break;
					}
				}
				if( flag1 == 1 )
				{
					flag[i] = 1 ;
				}
			}
		}
		int res = 1 ;
		for( int i = 0 ; i < m ; i ++ )
		{
			if( flag[i] == 0 )
			{
				res = 0 ;
			}
		}
		if( res == 1 )
		{
			printf("Case #%d: YES\n",c);
		}
		else
		{
			printf("Case #%d: NO\n",c);
		}
	}
	return 0 ;
}