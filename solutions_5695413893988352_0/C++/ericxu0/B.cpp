#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int T, N;
ll power[19];
string C, J;
ll bestdif, bestc, bestj;
ll cr[2], jr[2];

/*void go2(int idx, int b, ll c, ll j)
{
	ll c1 = 0, j1 = 0;
	if (b == 0)
	{
		for (int i = 0; i < idx; i++)
		{
			if (C[i] == '?' && J[i] == '?')
			{
				c1 = 10*c1 + 0;
				j1 = 10*j1 + 0;
			}
			else if (C[i] != '?')
			{
				c1 = 10*c1 + C[i] - '0';
				j1 = 10*j1 + C[i] - '0';
			}
			else
			{
				c1 = 10*c1 + J[i] - '0';
				j1 = 10*j1 + J[i] - '0';
			}
		}
		update(power[N - idx]*c1 + c, power[N - idx]*j1 + j);
	}
	else if (b == 1)
	{
		for (int i = 0; i < idx - 1; i++)
		{
			if (C[i] == '?' && J[i] == '?')
			{
				c1 = 10*c1 + 0;
				j1 = 10*j1 + 0;
			}
			else if (C[i] != '?')
			{
				c1 = 10*c1 + C[i] - '0';
				j1 = 10*j1 + C[i] - '0';
			}
			else
			{
				c1 = 10*c1 + J[i] - '0';
				j1 = 10*j1 + J[i] - '0';
			}
		}
		update(power[N - idx]*c1 + c, power[N - idx]*j1 + j);
	}
}

void go()
{
	int idx = 0;
	for (; idx < N; idx++)
		if (C[idx] != '?' && J[idx] != '?' && C[idx] != J[idx])
			break;

	for (int i = idx + 1; i < N; i++)
	{
		if (C[i] == '?')
		{
			cr[0] = 10*cr[0] + 0;
			cr[1] = 10*cr[1] + 9;
		}
		else
		{
			cr[0] = 10*cr[0] + C[i] - '0';
			cr[1] = 10*cr[1] + C[i] - '0';
		}
		if (J[i] == '?')
		{
			jr[0] = 10*jr[0] + 0;
			jr[1] = 10*jr[1] + 9;
		}
		else
		{
			jr[0] = 10*jr[0] + J[i] - '0';
			jr[1] = 10*jr[1] + J[i] - '0';
		}
	}

	if (idx == 0)
	{
		if (C[idx] < J[idx])
		{
			bestc = power[N - 1 - idx]*(C[idx] - '0') + cr[1];
			bestj = power[N - 1 - idx]*(J[idx] - '0') + jr[0];
		}
		else
		{
			bestc = power[N - 1 - idx]*(C[idx] - '0') + cr[0];
			bestj = power[N - 1 - idx]*(J[idx] - '0') + jr[1];
		}
		return;
	}

	if (idx == N)
	{
		go2(N, 0, 0, 0);
		return;
	}

	if (C[idx] < J[idx])
	{
		go2(idx, 1, 10*power[N - idx] + power[N - 1 - idx]*(C[idx] - '0') + cr[0], power[N - 1 - idx]*(J[idx] - '0') + jr[1]);
		go2(idx, 0, power[N - 1 - idx]*(C[idx] - '0') + cr[1], power[N - 1 - idx]*(J[idx] - '0') + jr[0]);
	}
	else
	{
		go2(idx, 2, power[N - 1 - idx]*(C[idx] - '0') + cr[1], 10*power[N - idx] + power[N - 1 - idx]*(J[idx] - '0') + jr[0]);
		go2(idx, 0, power[N - 1 - idx]*(C[idx] - '0') + cr[0], power[N - 1 - idx]*(J[idx] - '0') + jr[1]);
	}
}*/

string getstr(ll x)
{
	string ret = "";
	for (int i = 0; i < N; i++, x /= 10)
		ret = (char)(x % 10 + '0') + ret;
	return ret;
}

void update(ll c, ll j)
{
	ll dif = abs(c - j);
	if (bestdif == -1 || dif < bestdif)
	{
		bestdif = dif;
		bestc = c;
		bestj = j;
	}
	else if (dif == bestdif)
	{
		if (c < bestc)
		{
			bestc = c;
			bestj = j;
		}
		else if (c == bestc)
		{
			if (j < bestj)
				bestj = j;
		}
	}
}

void goJ(int idx, ll c, ll j)
{
	if (idx == N)
	{
		update(c, j);
		return;
	}

	if (J[idx] == '?')
	{
		for (int i = 0; i <= 9; i++)
			goJ(idx + 1, c, 10*j + i);
	}
	else
		goJ(idx + 1, c, 10*j + J[idx] - '0');
}

void goC(int idx, ll c)
{
	if (idx == N)
	{
		goJ(0, c, 0);
		return;
	}

	if (C[idx] == '?')
	{
		for (int i = 0; i <= 9; i++)
			goC(idx + 1, 10*c + i);
	}
	else
		goC(idx + 1, 10*c + C[idx] - '0');
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B.out", "w", stdout);
	ios::sync_with_stdio(0);

	power[0] = 1;
	for (int i = 1; i <= 18; i++)
		power[i] = 10*power[i - 1];

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> C >> J;
		N = C.size();

		bestdif = -1, bestc = -1, bestj = -1;
		goC(0, 0);
		cout << "Case #" << t << ": " << getstr(bestc) << " " << getstr(bestj) << "\n";
	}

	return 0;
}