#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

struct data{
	int a, b, c;
}datas[1005];

int be;

int finds(int a, int b, int c)
{
	int ca = 0, cb = 0, cc = 0;
	for (size_t i = 0; i < be; i++)
	{
		if (datas[i].a == a&&datas[i].b == b)
		{
			cc++;
		}
		if (datas[i].a == a&&datas[i].c == c)
		{
			cb++;
		}
		if (datas[i].b == b&&datas[i].c == c)
		{
			ca++;
		}
	}
	int ret = max(ca, cb);
	ret = max(ret, cc);
	return ret;
}

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	int t;
	cin >> t;
	for (size_t s = 0; s < t; s++)
	{
		memset(datas, 0, sizeof(datas));

		int a, b, c, kk;

		cin >> b >> a >> c >> kk;

		cout << "Case #" << s + 1 << ": ";
		be = 0;

		for (size_t i = 0; i < a; i++)
		{
			for (size_t j = 0; j < b; j++)
			{
				for (size_t k = 0; k < c; k++)
				{
					if (finds(i + 1, j + 1, k + 1) < kk)
					{
						datas[be].a = i + 1;
						datas[be].b = j + 1;
						datas[be].c = k + 1;
						be++;
					}
				}
			}
		}
		cout << be << "\n";
		for (size_t i = 0; i < be; i++)
		{
			cout << datas[i].b << " " << datas[i].a << " " << datas[i].c << "\n";
		}
	}

}