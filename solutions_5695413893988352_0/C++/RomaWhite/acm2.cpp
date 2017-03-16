#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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
#include <time.h>
#include <complex>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 1007;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 18;

int PRIME = 1000003;

bool Match(string s, int x)
{
	VI a;
	FOR(i,0,s.size())
	{
		a.push_back(x % 10);
		x /= 10;
	}
	reverse(ALL(a));
	if (x) return 0;
	FOR(i,0,s.size())
	{
		if (s[i] == '?') continue;
		if (s[i] - '0' != a[i]) return 0;
	}
	return 1;
}

void print(int x, int n)
{
	VI a;
	FOR(i,0,n)
	{
		a.push_back(x % 10);
		x /= 10;
	}
	reverse(ALL(a));
	FOR(i,0,a.size())
	{
		cout << a[i];
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt" , "w", stdout);
	//freopen("equation.in", "r", stdin);
	//freopen("equation.out", "w", stdout);

	int t;
	cin >> t;
	FOR(tt,0,t)
	{
		cerr << tt << endl;
		printf("Case #%d: " , tt + 1);
		string S , T;
		cin >> S >> T;
		int x = INF;
		int y = 0;
		FOR(i,0,1000)
			FOR(j,0,1000)
			{
				if (!Match(S, i)) break;
				if (!Match(T , j)) continue;
				if (abs(i - j) < abs(x - y))
				{
					x = i;
					y = j;
				}
				else
				{
					if (abs(i - j) == abs(x - y) && MP(i,j) < MP(x , y))
					{
						x = i;
						y = j;
					}
				}
			}
		print(x, S.size());
		cout << ' ';
		print(y, T.size());
		cout << endl;

	}
}
