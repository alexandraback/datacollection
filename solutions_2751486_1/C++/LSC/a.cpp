#include <cstdio>
#include <cstring>
using namespace std;

bool check(char k)
{return k!='a'&&k!='e'&&k!='i'&&k!='o'&&k!='u';}

char s[1000010];
int a[1000010];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		int n;
		scanf("%s%d", s, &n);
		int len = strlen(s);
		a[0] = check(s[0]) ? 1 : 0;
		for(int i=1; i<len; i++)
			a[i] = check(s[i]) ? a[i-1] + 1 : 0;

		long long ans = 0;
		int lb = 0;
		for(long long i=0; i<len; i++)
		{
			if(a[i]>=n)
			{
				ans += (i-n-lb+2) * (len-i);
				lb = i - n + 2;
			}
		}

		printf("Case #%d: %I64d\n", t, ans);
	}
	return 0;
}
