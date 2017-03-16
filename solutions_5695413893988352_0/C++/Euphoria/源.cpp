#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<set>
#include<algorithm>
#include<stack>
#include<list>

//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define ll long long
#define eps 1e-8
#define PI 2*cos(0.0)
#define MOD 1000000007

#define MAXN 2005

int visa[1000], visb[1000];

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("Bout.txt", "w", stdout);
	int ad[3], bd[3];
	int T;
	cin >> T;
	string a, b;

	for (int kase = 1; kase <= T; kase++)
	{
		cin >> a >> b;
		mem(ad, 0); mem(bd, 0);
		mem(visa, 0); mem(visb, 0);
		int dif = INF;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == '?')ad[i] = -1;
			else ad[i] = a[i] - '0';
			if (b[i] == '?')bd[i] = -1;
			else bd[i] = b[i] - '0';
		}
		if (a.length() == 3)
		{
			if (ad[0] == -1 && ad[1] == -1 && ad[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						for (int k = 0; k <= 9; k++)
							visa[100 * i + 10 * j + k] = 1;
			}
			else if (ad[0] == -1 && ad[1] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visa[100 * i + 10 * j + ad[2]] = 1;
			}
			else if (ad[0] == -1 && ad[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visa[100 * i + ad[1] * 10 + j] = 1;
			}
			else if (ad[1] == -1 && ad[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visa[ad[0] * 100 + 10 * i + j] = 1;
			}
			else if (ad[0] == -1)
			{
				for (int i = 0; i <= 9; i++)
					visa[100 * i + ad[1] * 10 + ad[2]] = 1;
			}
			else if (ad[1] == -1)
			{
				for (int i = 0; i <= 9; i++)
					visa[10 * i + ad[0] * 100 + ad[2]] = 1;
			}
			else if (ad[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					visa[100 * ad[0] + 10 * ad[1] + i] = 1;
			}
			else
			{
				visa[100 * ad[0] + 10 * ad[1] + ad[2]] = 1;
			}

			if (bd[0] == -1 && bd[1] == -1 && bd[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						for (int k = 0; k <= 9; k++)
							visb[100 * i + 10 * j + k] = 1;
			}
			else if (bd[0] == -1 && bd[1] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visb[100 * i + 10 * j + bd[2]] = 1;
			}
			else if (bd[0] == -1 && bd[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visb[100 * i + bd[1] * 10 + j] = 1;
			}
			else if (bd[1] == -1 && bd[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visb[bd[0] * 100 + 10 * i + j] = 1;
			}
			else if (bd[0] == -1)
			{
				for (int i = 0; i <= 9; i++)
					visb[100 * i + bd[1] * 10 + bd[2]] = 1;
			}
			else if (bd[1] == -1)
			{
				for (int i = 0; i <= 9; i++)
					visb[10 * i + bd[0] * 100 + bd[2]] = 1;
			}
			else if (bd[2] == -1)
			{
				for (int i = 0; i <= 9; i++)
					visb[100 * bd[0] + 10 * bd[1] + i] = 1;
			}
			else
			{
				visb[100 * bd[0] + 10 * bd[1] + bd[2]] = 1;
			}
		}
		else if (a.length() == 2)
		{
			if (ad[0] == -1 && ad[1] == -1)
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visa[i * 10 + j] = 1;
			else if (ad[0] == -1)
				for (int i = 0; i <= 9; i++)
					visa[i * 10 + ad[1]] = 1;
			else if (ad[1] == -1)
				for (int i = 0; i <= 9; i++)
					visa[ad[0] * 10 + i] = 1;
			else
				visa[ad[0] * 10 + ad[1]] = 1;

			if (bd[0] == -1 && bd[1] == -1)
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 9; j++)
						visb[i * 10 + j] = 1;
			else if (bd[0] == -1)
				for (int i = 0; i <= 9; i++)
					visb[i * 10 + bd[1]] = 1;
			else if (bd[1] == -1)
				for (int i = 0; i <= 9; i++)
					visb[bd[0] * 10 + i] = 1;
			else
				visb[bd[0] * 10 + bd[1]] = 1;
		}
		else
		{
			if (ad[0] == -1)
				for (int i = 0; i <= 9; i++)
					visa[i] = 1;
			else
				visa[ad[0]] = 1; 

			if (bd[0] == -1)
				for (int i = 0; i <= 9; i++)
					visb[i] = 1;
			else
				visb[bd[0]] = 1;
		}

		int ansa, ansb;

		int upper = 1;
		for (int i = 1; i <= a.length(); i++)
		{
			upper *= 10;
		}

		for (int i = 0; i < upper; i++)
		{
			if (visa[i])
			{
				for (int j = 0; j < upper; j++)
				{
					if (visb[j])
					{
						if (abs(i - j) < dif)
						{
							ansa = i;
							ansb = j;
							dif = abs(i - j);
						}
					}
				}
			}
		}

		printf("Case #%d: ", kase);
		if (a.length() == 3)
		{
			printf("%03d %03d\n", ansa, ansb);
		}
		else if (a.length() == 2)
		{
			printf("%02d %02d\n", ansa, ansb);
		}
		else if (a.length() == 1)
		{
			printf("%d %d\n", ansa, ansb);
		}
		//cout << ansa << ' ' << ansb << endl;
	}
}
