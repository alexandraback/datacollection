#include <stdio.h>
#include <algorithm>

const int N = 100;

using namespace std;

int f[N];
int test, n, m;

int main()
{
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
	
	scanf("%d" ,&test);
	
	for(int t=1; t<=test; t++)
	{
		scanf("%d %d" ,&n ,&m);
		
		printf("Case #%d:\n" ,t);
		
		for(int nol=0; ; nol+=2)
		{
			for(int i=nol+3; i<=n-2; i++)
			{
				for(int j=i+1; j<=n-2; j++)
				{
					if(i%2==1 && j%2==0)
					{
						for(int h=1; h<=n; h++)
							printf("%d" ,(h==1 || h==nol+2 || h==i || h==j || h==n-1 || h==n));
						
						for(int h=3; h<=11; h++)
							printf(" %d" ,h);
						
						printf("\n");
						
						m--;
						
						if(!m)
							return 0;
					}
				}
			}
		}
	}
}
