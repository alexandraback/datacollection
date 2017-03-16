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

int tt, tc, n, m, x, y, z, k, w;
int B[2501], ANS[55];

int main ()
{
	scanf("%d", &tc);
	while(tc--)
	{
		memset(B, 0, sizeof(B));
		scanf("%d", &n);
		FOR(i, 0, 2 * n - 1)
		{
			FOR(j, 0, n) { scanf("%d", &x); B[x]++; }
		}
		
		printf("Case #%d: ", ++tt);
		w = 0;
		FOE(i, 1, 2500) if (B[i] % 2 == 1) ANS[w++] = i;
		
		FOR(i, 0, w) if (i != w - 1) printf("%d ", ANS[i]); else printf("%d\n", ANS[i]);
	}
	return 0;
}
			
			
			
				
			
			 
		
		
