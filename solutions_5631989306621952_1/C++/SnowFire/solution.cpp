#include <stdio.h>
#include <string>
#include <deque>
#include <iostream>

using namespace std;

string S;

inline void init()
{
	cin >> S;
}

inline void solve()
{
	int i;

	deque<char> Q;

	Q.push_back(S[0]);

	for (i = 1; i < S.length(); i++)
	{
		if (S[i] >= Q.front())
			Q.push_front(S[i]);
		else
			Q.push_back(S[i]);
	}

	for (i = 0; i < Q.size(); i++)
		putchar(Q[i]);
	putchar('\n');
}

int main()
{
	int T, i;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		init();

		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}