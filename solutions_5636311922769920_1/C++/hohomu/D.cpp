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

int n, m, x, y, z, k, w, tc, tt;
ll ANS[105], tmp;
ll pos[105];

int main ()
{
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d %d", &n, &m, &k);
		
		pos[0] = 1ll;
		if (m > n) m = n;
		
		FOR(i, 1, m) pos[i] = pos[i - 1] * (ll)(n); 
		
		if (m == n) x = 1;
		else { x = n / m; if (n % m != 0) x++; }
		
		if (k < x) { printf("Case #%d: IMPOSSIBLE\n", ++tt); continue; }
		
		y = 0; w = 0;
		
		while (y <= n)
		{
			tmp = 0ll;
			FOD(i, m - 1, 0) { tmp += (ll)(y) * pos[i]; y++; }
			tmp++;
			ANS[w++] = tmp;
			if (y >= n) break;
			else if (y + m > n) y = n - m;
		}
		
		printf("Case #%d:", ++tt);
		FOR(i, 0, w) printf(" %lld", ANS[i]);
		printf("\n");
	}
	
	return 0;
}
			
