#include <bits/stdc++.h>
#define MAX 11111

using namespace std;

int M[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
int V[MAX];

int getInt(char c)
{
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	return 4;
}

int getRes(int a, int b)
{
	int sign = a / abs(a);
	sign *= b / abs(b);
	int c = M[abs(a)][abs(b)];
	return c * sign;
}

int getRange(int l, int r) // Inclusive
{
	int a = V[l - 1], b = V[r];
//	printf(" *%d %d* ", a, b);
	int sign = a / abs(a);
	a = abs(a);
	for (int k = 1; k < 5; k++)
		if (M[a][k] == b)
			return k * sign;
}

int main()
{
	freopen("CC.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	cin >> T;	
	for (int t = 1; t <= T; t++)
	{
		string s = " ", temp;
		int L, X;
		cin >> L >> X;
		cin >> temp;
		for (int i = 0; i < X; i++)
			s += temp;
			V[0] = 1;

		bool s1 = false, s2 = false;
		bool ok = false;
		for (int i = 1; i < s.size(); i++)
		{
			V[i] = getRes(V[i - 1], getInt(s[i]));
			if (V[i] == 2) s1 = true;
			if (s1 and V[i] == 4) s2 = true;
		//	printf("%d %d %d\n", s1, s2, V[i]);
		}
		ok = ((V[L * X] == -1) and s1 and s2);

		if (ok)
			printf("Case #%d: YES\n", t);
		else
			printf("Case #%d: NO\n", t);
	}
}
