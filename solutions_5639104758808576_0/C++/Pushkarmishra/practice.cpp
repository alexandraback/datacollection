#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
#define wf freopen("out.out", "w", stdout)
#define rf freopen("in1.txt", "r", stdin)
const int mx = 1e5+10;

int t, n;
char s[mx];

int main()
{
	rf; wf;
	
	scanf("%d", &t);
	rep(j, 1, t)
	{
		scanf("%d %s", &n, s);

		int cnt = 0, ans = 0;
		rep(i, 0, n)
		{
			if(s[i]-48 != 0)
				if(i-cnt > 0)
					ans += i-cnt, cnt += i-cnt;
			cnt += s[i]-48;
		}
		printf("Case #%d: %d\n", j, ans);
	}
	return 0;
}