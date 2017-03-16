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

string s = "";
string ks;
string ls;
int K, L, S;

int kol = 0;
int maxA = 0;
int sum = 0;

void rec(int pos)
{
	if (pos == S)
	{
		int temp = 0;
		for (int i = 0; i <= S - L; i++)
		{
			if (ls == s.substr(i, L)) temp++;
		}
		kol++;
		maxA = max(temp, maxA);
		sum += temp;
		return;
	}

	for (int i = 0; i < K; i++)
	{
		s += ks[i];
		rec(pos + 1);
		s.pop_back();
	}	
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
		kol = 0;
		maxA = 0;
		sum = 0;
		cin >> K >> L >> S;

		cin >> ks;
		cin >> ls;

		rec(0);

		int ostB = maxA*kol - sum;
		double ans = (double)ostB / (double)kol;


		printf("Case #%d: %.8f\n", test + 1, ans);
	}
	

	return 0;
}