#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
#define wf freopen("out.out", "w", stdout)
#define rf freopen("in.txt", "r", stdin)
const int mx = 1e5+10;

int test, n, m, ans;
static int suff[mx], pr[mx], st[10010][10010];
string s, fs;

int getit(int a, int b)
{
	int chk = 1;
	
	if(a < 0 and b < 0) chk = 1;
	else if(a < 0 or b < 0) chk = -1;

	if(a<0) a*=-1; if(b<0) b*=-1;
	
	if(a == 1) return chk*b;
	if(b == 1) return chk*a;

	if(a == 105 and b == 106) return chk*107;
	if(a == 106 and b == 105) return chk*(-107);

	if(a == 105 and b == 107) return chk*(-106);
	if(a == 107 and b == 105) return chk*106;

	if(a == 106 and b == 107) return chk*105;
	if(a == 107 and b == 106) return chk*(-105);

	return chk*(-1);
}

int main()
{
	rf; wf;
	
	scanf("%d", &test);
	rep(t, 1, test)
	{
		cin >> n >> m >> s; fs = ""; n *= m;
		rep(i, 1, m) fs += s;

		pr[0] = 1; suff[n+1] = 1;
		rep(i, 1, n)
		{
			int p = fs[i-1];
			pr[i] = getit(pr[i-1], p);
		}
		for(int i = n; i; --i)
		{
			int p = fs[i-1];
			suff[i] = getit(p, suff[i+1]);
		}

		for(int i=n-1; i-1; i--) rep(j, i, n-1)
		{
			int tmp = (i+1 > j)? 1: st[i+1][j];
			st[i][j] = getit(fs[i-1], tmp);
		}

		ans = 0;
		for(int i=2; i<n and !ans; ++i) for(int j=i; j<n and !ans; ++j)
		{
			if(pr[i-1] == 105 and st[i][j]==106 and suff[j+1]==107)
				ans = 1;
		}
		printf("Case #%d: %s\n", t, (ans)? "YES": "NO");
	}
	return 0;
}