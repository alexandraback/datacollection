
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
		int x = 0;
		REP(i, n)
			x += s[i];
		printf("Case #%d:", I + 1);
		REP(i, n)
		{
			double Min = 0;
			double Max = 1;
			double Mid;
			int it = 500;
			while(Max - Min > 1e-11 && it)
			{
				--it;
				Mid = (Min + Max) / 2;
				double lim = s[i] + x * Mid;
				double sum = Mid;
				REP(j, n)
					if(j != i && s[j] < lim)
					{
						double need = (lim - s[j]) / x;
						sum += need;
					}
				if(sum < 1 - 1e-11)
					Min = Mid;
				else
					Max = Mid;
			}
			printf(" %.9lf", Mid * 100);
		}
		puts("");
	}
	return 0;
}