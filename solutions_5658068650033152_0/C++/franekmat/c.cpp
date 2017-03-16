#include "cstdio"
#include "algorithm"
using namespace std;
int t,n,m,k,w,plus;
int main()
{
	scanf ("%d", &t);
	for (int i=0; i<t; i++)
	{
		scanf ("%d%d%d", &n, &m, &k);
		w=1000000;
		plus=0;
		
		if (n==1 || m==1 || n==2 || m==2) w=k;
		else if (k<=5) w=4;
		
		else
		{
			if (k>(n*m)-4) plus=(n*m)-k,k=(n*m)-4;
			for (int x=3; x<=n; x++)
			{
				for (int y=3; y<=m ;y++)
				{
					if ((2*(x-2))+(2*(y-2))+((x-2)*(y-2))>=k)
					{
						w=min(w,(2*(x-2))+(2*(y-2)));
					}
				}
			}
		}
		printf ("Case #%d: %d\n", i+1, w+plus);
	}
	
	return 0;
}
