#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL unsigned long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define K 101

typedef struct{ int f, s; }ta;

ta v[20];
int usedF[20];
int usedS[20];
int main()
{
//#ifdef _DINARISIO
	ifstream cin("C-small-attempt1.in");
	ofstream cout("C.out");
//#endif

	int T;
	cin >> T;
	map<string, int> allS;
	map<string, int> allF;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t + 1 << ": ";

		int n;
		cin >> n;
		allS.clear();
		allF.clear();
		map<string, int>::iterator it;
		for (int i = 0; i < n; ++i)
		{
			string f, s;
			cin >> f >> s;

			it = allF.find(f);
			if (it != allF.end())
			{
				v[i].f = it->second;
			}
			else
			{
				v[i].f = i;
				allF.insert(make_pair(f, i));
			}

			it = allS.find(s);
			if (it != allS.end())
			{
				v[i].s = it->second;
			}
			else
			{
				v[i].s = i;
				allS.insert(make_pair(s, i));
			}
		}
		int mmax = 0;
		memset(usedF, 0, sizeof(usedF));
		memset(usedS, 0, sizeof(usedS));
		int l = 1 << n;
		for (int state = 0; state < l; ++state)
		{
			int cnt = 0;
			for (int cur = state, used = 0; cur > 0; cur /= 2, used++)
			{
				if (cur & 1)
				{
					cnt++;
					usedF[v[used].f] = 1 + state;
					usedS[v[used].s] = 1 + state;
				}
			}
			bool bOK = true;
			for (int used = 0; used < n; ++used)
			{
				if (usedF[v[used].f] < 1 + state){ bOK = false; break; }
				if (usedS[v[used].s] < 1 + state){ bOK = false; break; }
			}
			if (bOK)
		 	{
				cnt = n - cnt;
				if (cnt >= mmax)mmax = cnt;
			}
		}
		if (mmax >= n)mmax = n - 1;
		cout << mmax <<endl;
	}
	re 0;
}