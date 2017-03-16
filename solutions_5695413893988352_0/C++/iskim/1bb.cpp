#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char str1[20], str2[20];
int len;

pair<int, int> ans{ 999999999, 0 };
pair<string, string> ans2;

void recur(int n)
{
	if (n == len * 2)
	{
		int a = atoi(str1), b = atoi(str2);
		int d1 = abs(a - b), d2 = abs(ans.first - ans.second);
		if (d1 > d2) return;
		if (d1==d2)
		{
			if (a > ans.first)return;
			if (a == ans.first && b > ans.second)return;
		}
		ans = { a,b };
		ans2 = { str1, str2 };
		return;
	}

	if (n < len)
	{
		if (str1[n] != '?') recur(n + 1);
		else
		{
			for (int i = 0; i < 10; i++)
			{
				str1[n] = i + '0';
				recur(n + 1);
			}
			str1[n] = '?';
		}
	}
	else
	{
		if (str2[n-len] != '?') recur(n + 1);
		else
		{
			for (int i = 0; i < 10; i++)
			{
				str2[n-len] = i + '0';
				recur(n + 1);
			}
			str2[n-len] = '?';
		}
	}
}

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\B-small-attempt0.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\B-small-attempt0.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		ans={ 999999999, 0 };
		printf("Case #%d: ", tt);
		scanf("%s%s", str1, str2);
		len = strlen(str1);
		recur(0);
		printf("%s %s\n", ans2.first.c_str(), ans2.second.c_str());
	}
}