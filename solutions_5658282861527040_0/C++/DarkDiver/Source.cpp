#pragma warning (disable : 4996)

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stack>
#include <algorithm>
#include <ios>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <sstream>
#include <map>
#include <memory.h>
#include <stdio.h>
#include <cassert>
#include <string.h>

#define forn(i , n) for (int i = 0; i < n; ++i)
#define down(i, n) for (int i = n - 1; i >= 0; --i)


using namespace std;

typedef unsigned long long int u64;
typedef long long int i64;
typedef vector<int> vint;
typedef vector<i64> vi64;
typedef pair<int, int> pint;
typedef pair<i64, i64> pi64;

#define FILE_NAME "file"

double sqr(double a)
{
	return a * a;
}

struct Node
{
	vint nbr;
	int n, p;
	bool used;
	Node()
	{
		p = -1;
		used = false;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
#ifdef FILE_INPUT
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	int test;
	cin >> test;
	forn(t, test)
	{

		int a, b, k;
		cin >> a >> b >> k;
		i64 ans = 0;
		forn(i, a)
		{
			forn(j, b)
			{
				if ((i & j) < k)
				{
					++ans;
				}
			}
		}




		cout << "Case #" << t + 1 << ": ";
		cout << ans;
		cout << "\n";
	}


	return 0;
}