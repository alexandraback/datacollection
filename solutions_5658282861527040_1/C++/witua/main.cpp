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
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 64;
const int MAX2 = 7000;
const int BASE = 1000000000;

int T;
int a, b, c;
Int R[MAX][2][2][2];

void Init()
{
	FILL(R, 0);
}

string get(int x)
{
	string s = "";
	while (x > 0)
	{
		s += char('0' + (x % 2));
		x /= 2;
	}
	while (SZ(s) < 40)
		s += '0';
	reverse(ALL(s));
	return s;
}

void SolveTest(int test)
{
	scanf("%d %d %d", &a, &b, &c);
	string A = get(a);
	string B = get(b);
	string C = get(c);
	R[0][1][1][1] = 1;
	FOR (pos,0,SZ(A))
		FOR (bA,0,2)
			FOR (bB,0,2)
				FOR (bC,0,2)
				{
					if (R[pos][bA][bB][bC] == 0)
						continue;
					FOR (dA,0,2)
						FOR (dB,0,2)
						{
							int dC = (dA & dB);
							int new_bA = bA, new_bB = bB, new_bC = bC;
							if (bA == 1)
							{
								if (dA > A[pos] - '0')
									continue;
								else
								if (dA < A[pos] - '0')
									new_bA = 0;
							}
							if (bB == 1)
							{
								if (dB > B[pos] - '0')
									continue;
								else
								if (dB < B[pos] - '0')
									new_bB = 0;
							}
							if (bC == 1)
							{
								if (dC > C[pos] - '0')
									continue;
								else
								if (dC < C[pos] - '0')
									new_bC = 0;
							}
							R[pos+1][new_bA][new_bB][new_bC] += R[pos][bA][bB][bC];
						}
				}
	printf("Case #%d: %I64d\n", test+1, R[SZ(A)][0][0][0]);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("B-large (1).in", "r", stdin);
		//freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	scanf("%d", &T);
	FOR (test,0,T)
	{
		Init();
		SolveTest(test);
	}

	return 0;
}