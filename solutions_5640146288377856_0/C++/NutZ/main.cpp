#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <hash_map>
#include <string> //
#include <iomanip>
#include <vector> 
#include <memory.h>
#include <queue>
#include <set>
#include <stack> 
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
typedef long long LL;
const LL MOD = 1000000000 + 7;


int W;
int D[25][2];

int rec(int kol, bool no)
{
	if (D[kol][no] != -1) return D[kol][no];

	if (no)
	{
		if (kol < W) {
			D[kol][no] = 0;
			return 0;
		}
		if (kol == W) {
			D[kol][no] = 1;
			return 1;
		}

		int minA = 100000000;

		for (int i = 1; i < kol; i++)
		{
			if (i - 1 >= W || kol - i >= W)
				minA = min(minA, rec(i - 1, true) + rec(kol - i, true) + 1);
		}

		D[kol][no] = minA;
	}
	else
	{
		if (kol == W)
		{
			D[kol][no] = W;
			return W;
		}

		int minA = 100000000;

		for (int i = 1; i < kol; i++)
		{
			int temp = -1;
			if (i - 1 >= W)
				temp = max(rec(i - 1, false) + rec(kol - i, true) + 1, temp);
			if (kol - i >= W)
				temp = max(rec(i - 1, true) + rec(kol - i, false) + 1, temp);

			int popal = W + 1;

			minA = min(minA, max(popal, temp));
		}

		D[kol][no] = minA;
	}	

	return D[kol][no];
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("f.in", "r", stdin); freopen("f.out", "w", stdout);
#endif

	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int R, C;

		cin >> R >> C >> W;
		mems(D, -1);
		cout << "Case #" << test + 1 << ": " << R*rec(C, false) << endl;
	}
	

	return 0;
}