#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int BufferSize = 100;

char buf[BufferSize];
int table[5000000] = {0};

int recycle(int a, int b)
{
	fill_n(table, b+1, 0);

	int total = 0;
	for (int x = a; x <= b; ++x)
	{
		sprintf(buf, "%d", x);
		int len = strlen(buf);

		for (int i = 1; i < len; ++i)
		{
			rotate(buf, buf + 1, buf + len);
			if (buf[0] != '0')
			{
				int y = atoi(buf);
				if (a <= y && y <= b && y > x
						&& table[y] != x)
				{
					++total;
					table[y] = x;
					//cout << x << " " << y << endl;
				}
			}
		}
	}

	return total;
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;

	for (int index = 1; index <= t; ++index)
	{
		int a, b;
		cin >> a >> b;

		printf("Case #%d: %d\n", index, recycle(a, b));
	}

	return 0;
}

