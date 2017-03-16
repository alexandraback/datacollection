#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include<fstream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#define rep(x,n) for(int x=0;x<n;++x)
#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
#define mp(x,y) make_pair(x,y)
#define getBit(code, i) (code & (1 << i))
#define setBit(code, i) (code | (1 << i))
#define resetBit(code, i) (code & ~(1 << i))
#define PI acos(-1.0)
#define rd(x) scanf("%d", &x)
using namespace std;

#define oo 1e9

int n, m;


pair<long long, int> A[4];
pair<long long, int> B[1000];



long long table[4][1001];


long long solve(int ass1, int ass2)
{
	if(ass1 == n || ass2 == m)
		return 0L;
	//long long &ret = table[ass1][ass2];
//	if(ret != -1L)
	//	return ret;
	long long ret = 0;
	if(A[ass1].second == B[ass2].second)
	{
		ret = max(ret, solve(ass1 + 1, ass2 + 1) + min(A[ass1].first, B[ass2].first));

		if(A[ass1].first > B[ass2].first)
		{
			A[ass1].first -= B[ass2].first;
			ret = max(ret, solve(ass1, ass2 + 1) + B[ass2].first);
			A[ass1].first += B[ass2].first;
		}
		else if(A[ass1].first < B[ass2].first)
		{
			B[ass2].first -= A[ass1].first;
			ret = max(ret, solve(ass1 + 1, ass2) + A[ass1].first);
			B[ass2].first += A[ass1].first;
		}
	}
	else
	{
		ret = solve(ass1 + 1, ass2);
		ret = max(ret, solve(ass1, ass2 + 1));
	}

	return ret;
}


int main()
{


	freopen("input.in", "rt", stdin);
	freopen("output.in", "w", stdout);

	int cases;
	rd(cases);
	int inh;
	rep(c, cases)
	{
	//	memset(table, -1, sizeof table);
		rd(n);
		rd(m);
		rep(i, n)
		{
			rd(A[i].first);
			rd(A[i].second);
		}
		rep(i, m)
		{
			rd(B[i].first);
			rd(B[i].second);
		}
		
		cout << "Case #" << c + 1 << ": " << solve(0, 0) << endl;
	}

	return 0;
}


