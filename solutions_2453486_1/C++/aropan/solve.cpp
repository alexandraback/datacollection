#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int _t;
	scanf("%d\n", &_t);
	for (int t = 1; t <= _t; t++)
	{
		printf("Case #%d: ", t);
		
		char s[6][6];
		for (int i = 0; i < 4; i++)
			scanf("%s", s[i]);
		int k;
		int x = 0;
		for (int i = 0; i < 4; i++)
		{
			
			k = 0;
			for (int j = 0; j < 4; j++)
				k += (s[i][j] == 'X' || s[i][j] == 'T');
			x = max(x, k);
			
			k = 0;
			for (int j = 0; j < 4; j++)
				k += (s[j][i] == 'X' || s[j][i] == 'T');
			x = max(x, k);
		}

		k = 0;
		for (int i = 0; i < 4; i++)
			k += (s[i][i] == 'X' || s[i][i] == 'T');
		x = max(x, k);

		k = 0;
		for (int i = 0; i < 4; i++)
			k += (s[3 - i][i] == 'X' || s[3 - i][i] == 'T');
		x = max(x, k);

		int o = 0;
		for (int i = 0; i < 4; i++)
		{
			
			k = 0;
			for (int j = 0; j < 4; j++)
				k += (s[i][j] == 'O' || s[i][j] == 'T');
			o = max(o, k);
			
			k = 0;
			for (int j = 0; j < 4; j++)
				k += (s[j][i] == 'O' || s[j][i] == 'T');
			o = max(o, k);
		}

		k = 0;
		for (int i = 0; i < 4; i++)
			k += (s[i][i] == 'O' || s[i][i] == 'T');
		o = max(o, k);

		k = 0;
		for (int i = 0; i < 4; i++)
			k += (s[3 - i][i] == 'O' || s[3 - i][i] == 'T');
		o = max(o, k);
		
		int d = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				d += s[i][j] == '.';
				
		if (x == 4) puts("X won"); else
		if (o == 4) puts("O won"); else
		if (d) puts("Game has not completed"); else
			puts("Draw");
	}

	return 0;
}
