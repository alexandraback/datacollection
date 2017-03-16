#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 1000010;
char buf[MAXL];
int n;
int cnt[MAXL];

bool check(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return false;
	return true;
}

int get(int l, int r)
{
	int res = cnt[r];
	if (l > 0)
		res -= cnt[l - 1];
	return res;
}

int main()
{
	int totCas;
	scanf("%d", &totCas);
	for (int cas = 1; cas <= totCas; cas++)
	{
		scanf("%s%d", buf, &n);
		int l = strlen(buf);
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < l; i++)
			if (check(buf[i]))
				cnt[i] = 1;
		for (int i = 1; i < l; i++)
			cnt[i] += cnt[i - 1];

		long long ans = 0;
		int pre = -1;
		for (int i = n - 1; i < l; i++)
		{
			if (get(i - n + 1, i) == n)
				pre = i - n + 1;
			if (pre != -1)
				ans += pre + 1;
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}

