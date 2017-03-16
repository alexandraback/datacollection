#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

const int m[5][5] = {{0,0,0,0,0},
   		     {0,1,2,3,4},
		     {0,2,-1,4,-3},
		     {0,3,-4,-1,2},
		     {0,4,3,-2,-1}};
int d[5][5];

int getV(char a)
{
	if (a == 'i') return 2;
	if (a == 'j') return 3;
	if (a == 'k') return 4;
	return 1;
}
int multi(int a, int b)
{
	int sig = 1;
	if (a < 0) {
		sig = -sig;
		a = -a;
	}
	if (b < 0) {
		sig = -sig;
		b = -b;
	}
	return sig * m[a][b];
}
int di(int a, int b)
{
	int sig = 1;
	if (a < 0) {
		sig = -sig;
		a = -a;
	}
	if (b < 0) {
		sig = -sig;
		b = -b;
	}
	return sig * d[a][b];
}
int pow(int a, int b)
{
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b == 2) return multi(a, a);
	if (b == 3) return multi(multi(a, a), a);
	assert(false);
}
int main()
{
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
		{
			int t = m[i][j], sig = 1;
			if (t < 0)
			{
				t = -t;
				sig = -sig;
			}
			d[t][i] = sig * j;
		}
	int cases;
	cin >> cases;
	for (int tcase = 1; tcase <= cases; ++tcase)
	{
		int L;
		long long K;
		string s;
		cin >> L >> K;
		cin >> s;
		vector<int> pre(L);
		pre[0] =  getV(s[0]);
		for (int i = 1; i < L; ++i)
			pre[i] = multi(pre[i - 1], getV(s[i]));

		int all = pre[L - 1];
		bool find = false;
		for (int i = 0; i < L && !find; ++i)
			for (int ll = 0; ll < 4 && ll + 1 <= K && !find; ++ll)
			{
				if (multi(pow(all, ll), pre[i]) != 2)
					continue;
				for (int j = 0; j < L; ++j)
				{
					int smm;
					if (i + 1 < j)
						smm = -1;
					else
						smm = 0;
					for (int mm = smm; mm < 4 && ll + mm + 2 <= K && !find; ++mm)
					{
						int t = 1;
						if (mm == -1)
						{
							t = di(pre[j - 1], pre[i]);
						}
						else
						{
							t = multi(di(all, pre[i]), pow(all, mm));
							if (j > 0) t = multi(t, pre[j - 1]);
						}
						if (t != 3) continue;
						int rr = (K - (ll + mm + 2) + 100) % 4;
						if (ll + mm + rr + 2 <= K)
						{
							if (j == 0)
								t = all;
							else
								t = di(all, pre[j - 1]);
							t = multi(t, pow(all, rr));
							 
							if (t == 4)
							{
								find = true;
							}
						}
					}
				}
			}
		cout << "Case #" << tcase << ": ";
		if (find) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
