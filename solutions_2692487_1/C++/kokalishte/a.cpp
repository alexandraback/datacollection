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

string inttostr(int i)
{
	stringstream ss;
	ss << i;
	string res;
	ss >> res;
	return res;
}

//data for prob:
int a, n, motes[101];

void read()
{
	scanf("%d %d", &a, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d",	&motes[i]);
	sort(motes, motes+n);
}

bool solvable(int moves)
{
	vector <bool> movie;
	for (int i = 0; i < moves; ++i)
		movie.push_back(true);
	for (int j = 0; j <= moves; ++j)
	{
		for (int k = 0; k < j; ++k)
		{
			movie[k] = 0;
		}
		vector <int> motez;
		for (int i = 0; i < n; ++i)
			motez.push_back(motes[i]);
		int br = 0;
		int A = a;
		bool moje = true;
		for (int i = 0; i < n; ++i)
		{
again:
			if (A > motez[i]) A += motez[i];
			else if (br < movie.size() && movie[br] == 0) {
				A += A-1; br++; goto again;
			} else if (br < movie.size() && movie[br] == 1)
			{
				br++;
				motez[i] = 0;
			}
			else if (br >= movie.size()) 
			{
				moje = false;
				break;
			}
		}
		if (moje) return true;
	}
	return false;
}

string solve()
{
	for (int i = 0; i <= 100; ++i)
		if (solvable(i))
			return inttostr(i);
	return "ERROR";
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
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




