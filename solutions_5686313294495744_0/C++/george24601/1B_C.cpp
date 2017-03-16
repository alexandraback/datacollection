#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*
 unknown: phone #
 length unknown
 condition: non-decreasing number
 S, completely reordered => i.e., can reorder whichever way we want
 S < 2000

 500 digits, each has 9 choices => bad!

 # of Z = # of 0s
 # of U = # of 4s
 # of X  = # of 6s
 pretty much a linear equation!

 */

string C;
string J;
int N;
int const MaxSize = 16;
string first[MaxSize];
string second[MaxSize];

int main() {
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/C-small-attempt0.in", "r", stdin);
	freopen("/Users/georgeli/C_0.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d", &N);

		LP(i, 0, N)
		{
			cin >> first[i];
			cin >> second[i];
		}

		int res = 0;
		int bs = 1 << N;
		LP(s, 0, bs)
		{
			int fakeC = 0;

			bool possible = true;

			LP(i, 0, N)
			{
				int isFake = (s >> i) & 1;
				if (!isFake)
					continue;

				fakeC++;

				bool firstFound = false;
				bool secondFound = false;

				LP(j, 0, N)
				{
					int isTargetFake = (s >> j) & 1;

					if (isTargetFake)
						continue;

					if (first[j] == first[i])
						firstFound = true;

					if (second[j] == second[i])
						secondFound = true;
				}

				if (!(firstFound && secondFound)) {
					possible = false;
					break;
				}
			}

			if (possible)
				res = max(res, fakeC);
		}

		printf("Case #%d: %d\n", cn, res);
	}

	return 0;

}
