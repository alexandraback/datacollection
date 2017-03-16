#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1010000000;
const int MAX = 1<<10;
const long long INFF = 100000000000000000LL;

#define BASE 1000000000

int T, a, n;
int A[MAX];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf("%d", &T);
	FOR (test,0,T)
	{
		scanf("%d %d", &a, &n);
		FOR (i,0,n)
			scanf("%d", &A[i]);
		sort(A, A+n);
		int res = n;
		FOR (i,1,n+1)
		{
			int cnt = n - i;
			Int cur = a;
			bool ok = 1;
			FOR (j,0,i)
			{
				if (cur > A[j])
					cur += A[j];
				else
				{
					if (cur == 1)
					{
						ok = 0;
						break;
					}
					while (cur <= A[j])
					{
						cnt ++;
						cur += cur - 1;
					}
					cur += A[j];
		
				}
			}
			if (ok)
				res = min(res, cnt);
		}
		printf("Case #%d: %d\n", test+1, res);
	}
	


		
	return 0;
}