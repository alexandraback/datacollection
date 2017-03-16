#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char s[1010];
int T, t, n;
deque<int> q;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		char now = s[1];
		q.push_back(1);
		for (int i = 2; i <= n; i++)
		{
			if (s[i] >= now)
			{
				now = s[i];
				q.push_front(i);
			}
			else q.push_back(i);
		}
		printf("Case #%d: ", t);
		while (q.size())
		{
			printf("%c", s[q.front()]);
			q.pop_front();
		}
		puts("");
	}
}