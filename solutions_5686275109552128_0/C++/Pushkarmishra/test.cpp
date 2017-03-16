#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
#define wf freopen("out.out", "w", stdout)
#define rf freopen("in.txt", "r", stdin)
const int mx = 1e5+10;

int test, n;
int p[mx];

int main()
{
	rf; wf;
	
	scanf("%d", &test);
	rep(t, 1, test)
	{
		scanf("%d", &n);
		rep(i, 1, n)
			scanf("%d", &p[i]);
		
		int ans = 1e9;
		rep(i, 1, 1000)
		{
			int tans = 0;
			rep(j, 1, n)
				tans += (p[j]-1)/i;
			ans = min(tans+i, ans);
		}
		
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}