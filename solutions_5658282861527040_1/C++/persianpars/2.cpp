// written by Amirmohsen Ahanchi //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
#include <complex>
#include <cassert>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Size(n) ((int)(n).size())
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define dbg(x) "#" << #x << ": " << x 
#define spc << " " <<

using namespace std;

//#define cin fin
//#define cout fout

typedef long long LL;
typedef pair <int, int> PII; 

const int lg = 30 + 2;

int a[lg][3];

LL d[lg][9];

int main()
{
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int A, B, K;
		cin >> A >> B >> K;
		memset(a, 0, sizeof a);
		for (int i = 0; i < lg; i++)
			a[i][0] = A >> i & 1,
			a[i][1] = B >> i & 1,
			a[i][2] = K >> i & 1;
		memset(d, 0, sizeof d);
		d[lg-1][0] = 1;
		for (int i = lg-2; i >= 0; i--)
		{
			for (int j = 0; j < (1 << 3); j++)
				for (int p = 0; p < (1 << 3); p++)
				{
					if (((p>>0&1) & (p>>1&1)) != (p>>2&1))
						continue;
					bool flag = false;
					int mask = j;
					for (int r = 0; r < 3; r++)
					{
						if (!(mask>>r&1) && (p>>r & 1) > a[i][r]) flag = true;
						if ((p>>r & 1) != a[i][r]) mask |= (1 << r);
					}
					if (flag) continue;
//					cerr << i << " " << mask << endl;
					d[i][mask] += d[i+1][j];
				}
		}
		cout << "Case #" << t+1 << ": ";
		cout << d[0][7] << endl;
	}
	return 0;
}

