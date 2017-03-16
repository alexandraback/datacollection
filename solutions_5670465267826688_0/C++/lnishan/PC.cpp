#include <cstdio>
#include <cstring>
#include <algorithm>
#define I 2
#define J 3
#define K 4

using namespace std;

const int L = 10005 << 2;

char s[L];
int t[5][5];


void pre()
{
	int i;
	for (i = 1; i <= K; i++)
		t[1][i] = t[i][1] = i;
	for (i = I; i <= K; i++)
		t[i][i] = -1;
	t[I][J] = K; t[I][K] = -J;
	t[J][I] = -K; t[J][K] = I;
	t[K][I] = J; t[K][J] = -I;
}

inline int cal(int n1, int n2)
{
	int sign = (n1 * n2) >= 0;
	n1 = n1 < 0 ? -n1 : n1;
	n2 = n2 < 0 ? -n2 : n2;
	return t[n1][n2] * ((sign << 1)-1);
}

int main()
{
	int i, j, t, l, x, r;
	int res;
	char used_i, used_k;
	pre();
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		used_i = used_k = 0;
		scanf("%d%d", &l, &x);
		scanf(" ");
		gets(s);
		for (i = 0; i < l; i++)
			switch (s[i])
			{
				case 'i':
					s[i] = I;
					break;
				case 'j':
					s[i] = J;
					break;
				case 'k':
					s[i] = K;
					break;
			}
		for (i = 0; i < l; i++)
			for (j = 1; j <= 3; j++)
				s[l * j + i] = s[i];
		
		printf("Case #%d: ", c);
		
		if (x >= 4)
		{
			res = 1;
			for (i = 0; i < (l << 2); i++)
			{
				res = cal(res, s[i]);
				if (res == I)
					used_i = 1;
				else if (res == K && used_i)
				{
					used_k = 1;
					break;
				}
			}	
			x %= 4;
		}
		
		r = l * x;
		res = 1;
		for (i = 0; i < r; i++)
			res = cal(res, s[i]);
		if (res != -1)
			puts("NO");
		else
		{
			res = 1;
			for (i = 0; i < r; i++)
			{
				res = cal(res, s[i]);
				if (res == I)
					used_i = 1;
				else if (res == K && used_i)
				{
					used_k = 1;
					break;
				}
			}
			if (used_k)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
