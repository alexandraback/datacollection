#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

//data for prob:
int x, y;
void read()
{
	cin >> x >> y;
}

#define MID 200
#define pii pair<int, int>
#define mp make_pair

string solve()
{
	string res;
	if (x > 0)
	{
		res.push_back('E');
		for (int i = 2; i <= x; ++i)
		{
			res.push_back('W');
			res.push_back('E');
		}
	}
	if (x < 0)
	{
		res.push_back('W');
		for (int i = -2; i >= x; --i)
		{
			res.push_back('E');
			res.push_back('W');
		}
	}
	if (y > 0)
	{
		res.push_back('S');
		res.push_back('N');
		for (int i = 2; i <= y; ++i)
		{
			res.push_back('S');
			res.push_back('N');
		}
	} else if (y < 0)
	{
		res.push_back('N');
		res.push_back('S');
		for (int i = -2; i >= y; --i)
		{
			res.push_back('N');
			res.push_back('S');
		}
	}
	return res;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	//program
	int tests;
	scanf("%d\n", &tests);
	for (int CASE = 1; CASE <= tests; ++CASE)
	{
		read();
		printf("Case #%d: %s\n", CASE, solve().c_str());
	}
	//end program
	return 0;
}




