#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


struct data{
	char fri[25];
	char sec[25];
};

data dats[20];

int datas[20][2];
int ans;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	int ss = 1;
	while (t--)
	{
		cout << "Case #" << ss << ": ";
		ss++;

		int n;
		cin >> n;
		int anss = 1e9;
		int temp=0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> dats[i].fri >> dats[i].sec;
		}

		for (size_t i = 0; i < 1<<n; i++)
		{
			temp = 0;
			memset(datas, 0, sizeof(datas));
			ans = 0;

			for (size_t s = 0; s < n; s++)
			{
				if (1 << s & i)
				{
					temp++;
				}
			}

			for (size_t s = 0; s < n; s++)
			{
				if (1 << s & i)
				{
					for (size_t t = 0; t < n; t++)
					{
						if (datas[t][0] == 0 && strcmp(dats[t].fri, dats[s].fri) == 0)
						{
							datas[t][0] = 1;
							ans++;
						}
						if (datas[t][1] == 0 && strcmp(dats[t].sec, dats[s].sec) == 0)
						{
							datas[t][1] = 1;
							ans++;
						}
					}
				}
			}

			if (ans == 2 * n)
			{
				anss = min(anss, temp);
			}
		}
		cout << n-anss << "\n";
	}
	fclose(stdin);
	fclose(stdout);
}