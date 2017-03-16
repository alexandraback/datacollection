#include<cstdio>
#include<cstring>

using namespace std;

int T, k, len, sz, l, r;
char s[1000005];
long long ans = 0;

int main()
{                                    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &T);
	for (int g = 0; g < T; g++)
	{
		ans = 0;
		sz = 0;
		l = -1;
		r = 0;
		scanf("%s%d\n", s, &k);
		len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				sz = 0;
			else
				sz++;
			if (sz == k)
			{
				ans += (i - k - l + 1) * (len - i);
				l = i - k + 1;
				r = k;
				sz--;
			}
		}
		printf("Case #%d: %I64d\n", g + 1, ans);
	}
	return 0;
}
