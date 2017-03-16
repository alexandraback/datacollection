#include <stdio.h>
#include <string.h>
#define L 1000005
typedef long long i64;
char str[L];
int arr[L];
inline int check(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 0;
	else return 1;
}
int main()
{
	int t, c = 1;
	int n, l, cnt, st, fr, bk, i, j, k;
	i64 ans;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %d", str, &n);
		l = strlen(str);
		for (i = 0; i < l; i++) arr[i] = check(str[i]);
		ans = 0;

		fr = st = 0;
		bk = 1;
		cnt = arr[0];
		
		for (i = 0; i < l; i++)
		{
			while (cnt < n && bk < l)
			{
				if (arr[bk])
				{
					if (arr[bk-1]) cnt++;
					else
					{
						cnt = 1;
						st = bk;
					}
				}
				bk++;
			}
			if (cnt >= n)
				ans += l - bk + 1;
//			printf("%d\n", cnt);
			if (i == st)
			{
				st++;
				cnt--;
			}
		}
		printf("Case #%d: %lld\n", c++, ans);
	}
	return 0;
}
