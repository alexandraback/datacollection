
#define _CRT_SECURE_NO_DEPRECATE 

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

using namespace std; 

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define ALL(V) V.begin(), V.end()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PI;

const int SZ = 2000001;

VI v[SZ];

char buf[10];

void init()
{
	FOR(i, 1, SZ)
	{
		if(i % 1000 == 0)
			cerr << i << endl;
		sprintf(buf, "%d", i);
		string s = buf;
		int len = (int)strlen(buf);
		int m = i;
		REP(j, len)
		{
			if(buf[0] != '0')
			{
				int x;
				sscanf(buf, "%d", &x);
				m = min(m, x);
			}
			rotate(buf, buf + 1, buf + len);
		}
		if(v[m].empty() || v[m].back() != i)
			v[m].pb(i);
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	init();
		
	int tests;

	scanf("%d", &tests);

	REP(I, tests)
	{
		int a, b;

		scanf("%d%d", &a, &b);

		int res = 0;

		FOR(i, 1, SZ)
		{
			int cnt = 0;
			REP(j, (int)v[i].size())
				if(a <= v[i][j] && v[i][j] <= b)
					++cnt;
			//if(cnt > 1)
			//	cout << i << endl;
			res += cnt * (cnt - 1) / 2;
		}
		//cout << "--------" << endl;
		cerr << I + 1 << endl;
		printf("Case #%d: %d\n", I + 1, res);
	}

	return 0;
}