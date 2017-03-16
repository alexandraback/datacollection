//By Lin
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 

int		n,data[20];
struct	Node{
	int key , x; 
}a[1<<21];

bool	cmp( const Node &a , const Node & b ) 
{
	return a.key < b.key; 
}

int		main()
{
	int cas, tt = 0; 
	scanf("%d", &cas );
	while ( cas -- ) 
	{
		printf("Case #%d:\n" , ++ tt );
		scanf("%d", &n );
		for (int i = 0; i<n; i++) scanf("%d", &data[i] );
		for (int i = 0; i<n; i++) a[1<<i].key = data[i]; 
		for (int i = 1; i<(1<<n); i++) 
		{
			for (int j = 0; j<n; j++) 
				if ( (i|(1<<j)) ==  i ) 
				{
					a[i].key = a[1<<j].key + a[i^(1<<j)].key; 
					break; 
				}
			a[i].x = i;
		}
		sort( a+1 , a+(1<<n) , cmp );
		bool flag = false; 
		for (int i = 1; i <(1<<n) && !flag ; i++) 
		{
			int j = i; 
			//printf("%d %d\n" , j , a[j].key );
			while ( a[i].key == a[j].key )
			{
				i++; 
			}
//			printf("%d %d\n" , i , j );
			for (int g = j; g<i && !flag; g++) 
				for (int h = g+1; h<i && !flag ; h++) 
				{
					if ( (a[g].x & a[h].x) == 0 ) 
					{
						flag = true; 
						g = a[g].x; 
						for (int k = 0; k<n; k++) 
							if ( (g|(1<<k)) == g ) {
								g = g^(1<<k);
								printf("%d" , data[k] );
								if ( g == 0 ) printf("\n"); 
								else printf(" " );
							}
						g = a[h].x; 
						for (int k = 0; k<n; k++) 
							if ( (g|(1<<k)) == g ) {
								g = g^(1<<k);
								printf("%d" , data[k] );
								if ( g == 0 ) printf("\n"); 
								else printf(" " );
							}
						break; 
					}
				}
			i--; 
		}
		if ( !flag ) printf("Impossible\n" );
	}
	return 0;
}
