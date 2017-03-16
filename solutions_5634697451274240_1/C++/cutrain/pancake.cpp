#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char tmp[200];

int solve(char *s, int len)
{
	int ans = 0;
	int r = len-1, l = 0;
	while (r >= 0 && s[r] == '+') -- r;
	if (r < 0) return 0;
	while (l < len && s[l] == '+') ++ l;
	if (l > 0)
	{
		++ ans;
		for (int i = 0;i < l;++ i)
			s[i] = '-';
	}
	++ ans;
	for (int i = 0;i <= r;++ i)
		tmp[i] = s[i];
	for (int i = 0;i <= r;++ i)
		s[i] = (tmp[r-i]=='-')?'+':'-';
	ans += solve(s, r);
	return ans;
}
char s[200];
int len;
int ans;

int main()
{
//	freopen("B-large.in","r",stdin);
//	freopen("pancake.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int testcase = 1;testcase <= T;++ testcase)
	{
		scanf("%s", s);
		len = strlen(s);
		ans = solve(s, len);
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}
