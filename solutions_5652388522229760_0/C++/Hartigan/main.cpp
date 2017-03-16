#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int t, n;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> t;

	char buffer[100];
	bool f[10];
	int count;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		cout << "Case #" << i+1 << ": ";

		if (n == 0)
		{
			cout << "INSOMNIA" << endl;
			continue;
		}

		int count = 0;
		for (int j = 0; j < 10; j++)
		{
			f[j] = false;
		}

		int s = 0;

		while (count < 10)
		{
			s += n;
			sprintf(buffer, "%d", s);

			for (int j = 0; j < strlen(buffer); j++)
			{
				char ch = buffer[j] - '0';
				if (!f[ch])
				{
					f[ch] = true;
					count++;
				}
			}
		}

		cout << s << endl;
	}

	return 0;
}