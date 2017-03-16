
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

const int SZ = 1 << 8;

int tests;

int n;

int s[SZ];

VI v1, v2;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &tests);
	REP(I, tests)
	{
		scanf("%d", &n);
		REP(i, n)
		{
			scanf("%d", &s[i]);
		}
		printf("Case #%d:\n", I + 1);
		v1.clear();
		v2.clear();
		REP(mask, (1 << n))
		{
			int a = 0, b;
			REP(j, n)
				if(!(mask & (1 << j)))
					a += s[j];
			for (int x = mask; x; x = (x - 1) & mask)
			{
				b = 0;
				REP(k, n)
					if(x & (1 << k))
						b += s[k];
				if(a == b)
				{
					REP(j, n)
						if(!(mask & (1 << j)))
							v1.pb(s[j]);
					REP(k, n)
						if(x & (1 << k))
							v2.pb(s[k]);
					break;
				}
			}
			if(!v1.empty())
				break;
		}
		if(!v1.empty())
		{
			REP(i, (int)v1.size())
				printf("%s%d", i ? " " : "", v1[i]);
			puts("");
			REP(i, (int)v2.size())
				printf("%s%d", i ? " " : "", v2[i]);
			puts("");
		}
		else
			puts("Impossible");
		cerr << I + 1 << endl;
	}
	return 0;
}