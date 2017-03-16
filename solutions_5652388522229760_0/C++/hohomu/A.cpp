#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<iterator>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define CLR(a) memset(a,0,sizeof(a))
#define ll long long
#include<ctime>
#include<cmath>
#include<vector>

int tc, tt, n, m, x, y, z, k, w;
int A[15];

int main ()
{
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		memset(A, 0, sizeof(A));
		
		if (n == 0) printf("Case #%d: INSOMNIA\n", ++tt);
		else
		{
			y = n;
			while (1)
			{
				x = y;
				while (x > 0) { A[x % 10] = 1; x /= 10; }
				z = 1;
				FOR(i, 0, 10) if (A[i] == 0) z = 0;
				if (z == 1) break; 
				y += n;
			}
			printf("Case #%d: %d\n", ++tt, y);
		}
	}
	
	return 0;
}
	
	
