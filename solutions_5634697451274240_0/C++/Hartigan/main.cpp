#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int t, n;

inline bool is_plus(char ch)
{
	return ch == '+';
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> t;

	char buffer[200];

	

	for (int i = 0; i < t; i++)
	{
		cin >> buffer;

		int j = strlen(buffer) - 1;
		int flip_count = 0;

		while (j >= 0)
		{
			int cur = j;
			for (; buffer[cur] == buffer[j] && cur >= 0; cur--);

			if ((is_plus(buffer[j]) && flip_count % 2 == 1)
				|| (!is_plus(buffer[j]) && flip_count % 2 == 0))
			{
				flip_count++;
			}

			j = cur;
		}

		cout << "Case #" << i + 1 << ": " << flip_count << endl;
	}

	return 0;
}