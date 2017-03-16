#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define travel(u) for(int i=start[u],v;v=e[i].a,i;i=e[i].next)
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define pb push_back
int T, n, m, d[15], a[15], cnt, x, y;
int bo[2000005], p, l, r;
int gcd(int a, int b){};
int main()
{
	//freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	scanf("%d", &T);
	int ca = 0;
	while (T--)
	{
		++ca;
		printf("Case #%d: ", ca);
		scanf("%d%d", &l, &r);
		cnt = 0;
		for (int i = l; i <= r; i++)
		{
			++p;
			d[0] = 0;
			x = i;
			
			
			
			
			
			while (x)
			{
				
				
				d[++d[0]] = x % 10;
				x =(int) x / 10;
			}
			
			
			for (int j = 1; j < d[0]; j++)
			{
				
				
				y = 0;
				for (int k = d[0]; k; k--) y = y * 10 + d[(k - j - 1 + d[0]) % d[0] + 1];
				if (y > i && y <= r && bo[y] != p)
				{
					++cnt;
					bo[y] = p;
				}
				
				
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
