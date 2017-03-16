#include <iostream>
#include <string.h>

using namespace std;

int T, R, N, M, K;
int x[15], y[15];

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> R >> N >> M >> K;
		cout << "Case #1:" << endl;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < K; j++) cin >> x[j];
			memset(y, 0, sizeof(y));
			bool check = 0;
			for(int a = 2; a <= M && !check; a++)
			for(int b = 2; b <= M && !check; b++)			
			for(int c = 2; c <= M && !check; c++)
			{
				for(int j = 0; j < (1 << N); j++)
				{
					int cur = 1;
					if (j & 1) cur *= a;
					if (j & (1 << 1)) cur *= b;
					if (j & (1 << 2)) cur *= c;
					for(int k = 0; k < K; k++)
						if (cur == x[k]) y[k] = 1;
				}
				int flag = 1;
				for(int j = 0; j < K; j++) flag *= y[j];
				if (flag)
				{
					cout << a << b << c << endl;
					check = 1;
				}
			}
			if (!check) cout << "222" << endl;
		}
	}
	return 0;
}
