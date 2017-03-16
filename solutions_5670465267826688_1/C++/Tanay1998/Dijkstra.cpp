#include <bits/stdc++.h>
#define MAX 111111

using namespace std;

long long M[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
long long V[MAX];

long long getInt(char c)
{
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	return 4;
}

long long getRes(long long a, long long b)
{
	long long sign = a / abs(a);
	sign *= b / abs(b);
	long long c = M[abs(a)][abs(b)];
	return c * sign;
}

string s, temp;

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	cin >> T;	
	for (int t = 1; t <= T; t++)
	{
		s = " ";
		long long L, X;
		cin >> L >> X;
		cin >> temp;
		long long tx = X;
		X = X % 4;
		if (tx >= 4) X += 4;

		for (long long i = 0; i < X; i++)
			s += temp;
		V[0] = 1;
		bool s1 = false, s2 = false, ok = false;
		for (long long i = 1; i < s.size(); i++)
		{
			V[i] = getRes(V[i - 1], getInt(s[i]));
			if (V[i] == 2) s1 = true;
			if (s1 and V[i] == 4) s2 = true;
		}
		ok = ((V[L * X] == -1) and s1 and s2);

		if (ok)
			printf("Case #%d: YES\n", t);
		else
			printf("Case #%d: NO\n", t);
	}
}
