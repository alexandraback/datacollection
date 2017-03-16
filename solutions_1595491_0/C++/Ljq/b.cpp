#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>


using namespace std;


const int MAXN = 128;


int n, s, p;
int t[MAXN];
int v[32][2];
int f[MAXN][MAXN];


void Work()
{
	cin >> n >> s >> p;
	for (int i = 0; i < n; i ++)
		cin >> t[i];

	memset(f, 0xff, sizeof(f));

	f[0][0] = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= s; j ++)   if (f[i][j] >= 0)
		{
			f[i+1][j] = max(f[i+1][j], f[i][j] + (v[t[i]][0] >= p));
			if (j < s)
				f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + (v[t[i]][1] >= p));
		}

	cout << f[n][s] << endl;
}


int main()
{	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	memset(v, 0, sizeof(v));

	for (int i = 0; i <= 10; i ++)
		for (int j = i; j <= 10 && j <= i + 2; j ++)
			for (int k = j; k <= 10 && k <= i + 2; k ++)
			{
				if (i + 1 >= k)
					v[i+j+k][0] = max(v[i+j+k][0], k);
				if (i + 2 == k)
					v[i+j+k][1] = max(v[i+j+k][1], k);
			}

	int T;
	cin >> T;
	for (int k = 1; k <= T; k ++)
	{
		cout << "Case #" << k << ": ";
		Work();
	}


	return 0;
}