#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define MAX 11000
using namespace std;

struct Q
{
	int val;
	bool minus;

	Q()
	{
		minus = false;
		val = 0;
	}

	Q(char c)
	{
		minus = false;
		if (c == 'i')
			val = 1;
		else if (c == 'j')
			val = 2;
		else if (c == 'k')
			val = 3;
		else 
			val = 0;
	}
};

int matr[4][4] = 
{
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}
};

bool minuses[4][4] = 
{
	{false, false, false, false},
	{false, true, false, true},
	{false, true, true, false},
	{false, false, true, true}
};

Q operator * (Q & q1, Q q2)
{
	Q res;
	res.val = matr[q1.val][q2.val];
	res.minus = q1.minus != q2.minus;
	res.minus = res.minus != minuses[q1.val][q2.val];
	return res;
}

bool operator == (Q & q1, Q q2)
{
	return q1.minus == q2.minus && q1.val == q2.val;
}

Q I('i'), J('j'), K('k');


int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int L, X;
		string s, p;
		Q q('1');
		cin >> L >> X;
		cin >> p;
		s = "";
		int cnt = 0;
		for (int i = 0; i < 12 && i < X; i++)
		{
			cnt++;
			s += p;
		}
		X -= cnt;
		while (X % 4 != 0)
		{
			s += p;
			X--;
		}
		cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			q = q * Q(s[i]);
			if (cnt == 0)
			{
				if (q == I)
				{
					cnt++;
					q = Q(1);
				}
			}
			else if (cnt == 1)
			{
				if (q == J)
				{
					cnt++;
					q = Q(1);
				}
			}
		}
		bool ok = ((cnt == 2) && (q == K)); 
		printf("Case #%d: %s\n", t+1, ok ? "YES" : "NO");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}