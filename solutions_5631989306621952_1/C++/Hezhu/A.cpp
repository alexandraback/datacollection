#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char s[1001];
char final[1001];
bool vis[1001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%s", s);
		int n = strlen(s);
		stack<int> stk;
		for (int i = n - 1; i >= 0; --i)
		{
			while (stk.size() && s[stk.top()] < s[i])
				stk.pop();
			stk.push(i);
			vis[i] = false;
		}
		while (stk.size())
		{
			vis[stk.top()] = true;
			stk.pop();
		}
		printf("Case #%d: ", kase);
		for (int i = n - 1; i >= 0; --i)
			if (vis[i])
				putchar(s[i]);
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				putchar(s[i]);
		puts("");
	}
	return 0;
}
