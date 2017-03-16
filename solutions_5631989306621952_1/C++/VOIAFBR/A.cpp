#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int maxn = 1086;
char s[maxn], ans[maxn];
int len, num_case, l, r;

void work(int key)
{
	if (!key) return;
	char imax = 'A' - 1;
	int pos, now_r = key;
	for (int i = now_r; i >= 1; i--)
	{
		if (imax < s[i])
		{
			pos = i;
			imax = s[i];
		}
	}
	ans[l++] = imax;
	for (int i = key; i >= pos + 1; i--)
		ans[r--] = s[i];
	work(pos - 1);
}

int main()
{
	freopen("A2.in", "r", stdin);
	freopen("A2.out", "w", stdout);
	scanf("%d", &num_case);
	for (int icase = 1; icase <= num_case; icase++)
	{
		scanf("%s", s + 1);
		len = strlen(s + 1);
		l = 1;
		r = len;
		printf("Case #%d: ", icase);
		work(len);
		ans[len + 1] = '\0';
		printf("%s\n", ans + 1);
	}
	return 0;
}
