#include <ctime>
#include <bitset>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;


#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

#define y1 asdfasdf

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-7;
const int MOD = 1000000007;
const int INF = 2000000000;

int convertString(string& s)
{
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

int l;

void createString(int x, string& s)
{
	switch (l)
	{
	case 1:
		s = " ";
		s[0] = '0' + x;
		break;
	case 2:
		s = "  ";
		s[1] = '0' + x % 10;
		s[0] = '0' + x / 10;
		break;
	case 3:
		s = "   ";
		s[2] = '0' + x % 10;
		s[1] = '0' + (x / 10) % 10;
		s[0] = '0' + x / 100;
		break;
	}
}

bool match(string& s1, string& s2)
{
	for (int i = 0; i < l; ++i)
		if (s1[i] != s2[i] && s1[i] != '?' && s2[i] != '?')
			return false;
	return true;
}

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	l = s1.size();
	if (s1=="?2?")
	{
		int kk = 47;
	}
	string a, b;
	int mx = 1;
	for (int i = 0; i < l; ++i)
		mx *= 10;

	int res = 1000;
	string aa,bb;
	for (int i = 0; i < mx; ++i)
	{
		for (int j = 0; j < mx; ++j)
		{
			if (abs(i-j) < res)
			{
				createString(i, a);
				createString(j, b);
				if (match(a,s1) && match(b,s2))
				{
					aa=a;
					bb=b;
					res = abs(i-j);
				}
			}
		}
	}

	cout << aa << " " << bb << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);

	for (int test = 1; test <= tests; ++test)
	{
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}
