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

bool can[35];

int rec(set<int>& d, int sum, int pos)
{
	can[sum] = true;
	if (pos >= d.size()) return 0;
	auto it = d.begin();
	for (int i = 0; i < pos; i++, it++);
	rec(d, sum + *it, pos + 1);
	rec(d, sum, pos + 1);
	return 0;
}


int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("f.in", "r", stdin); freopen("f.out", "w", stdout);
#endif

	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int C, D, V;
		cin >> C >> D >> V;
		mems(can, 0);
		set<int> d;
		for (int i = 0; i < D; i++)
		{
			int temp; cin >> temp;
			d.insert(temp);
		}


		int ans = 0;

		while (true)
		{
			rec(d, 0, 0);
			

			bool flag2 = false, flag4 = false, flag8 = false, flag16 = false;
			for (int i = 2; i <= min(3, V); i++)
			{
				if (!can[i]) flag2 = true;
			}
			for (int i = 4; i <= min(7, V); i++)
			{
				if (!can[i]) flag4 = true;
			}
			for (int i = 8; i <= min(15, V); i++)
			{
				if (!can[i]) flag8 = true;
			}
			for (int i = 16; i <= V; i++)
			{
				if (!can[i]) flag16 = true;
			}

			if (!can[1])
			{
				ans++;
				d.insert(1);
			}
			else if (flag2)
			{
				ans++;
				d.insert(2);
			}
			else if (flag4)
			{
				ans++;
				d.insert(4);
			}
			else if (flag8)
			{
				ans++;
				d.insert(8);
			}
			else if (flag16)
			{
				ans++;
				d.insert(16);
			}
			else
			{
				break;
			}
				
			
		}
		
		

		printf("Case #%d: %d\n", test + 1, ans);
	}
	

	return 0;
}