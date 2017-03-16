#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*
 claim: T(n) = sum of all prev T(1)...T(n-1)
 T(1) = 1
 T(2) = 1
 T(n) = 2^(n-1) n >= 2

 proof by induction
 T(n+1) = T(n) +...T(2) + T(1) = 2^0....2^(n-1) + 1 = 2^n - 1 + 1

 so if target T > 2^(n-1), can't do it
 otherwise, we go through the bits, if the bit is 1, add edge from that node to n! (that node being at least 2)

 for each i
 for each j
 if (j > i and j < B-1)
 print 1;
 else if(i >= 1 && j == B - 1){
 if(M >> (i -1)) % 2
 print 1
 else
 print 0



 }else
 print 0;



 cur i = 2
 while(M > 0)
 {
 if (M % 2)
 add from i to B-1

 M /= 2
 i++
 }


 */

LL maxValue (int B){
	if(B == 2)
		return 1;
	else
		return 2 * maxValue(B-1);
}

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-small-attempt0.in", "r", stdin);
	freopen("/Users/georgeli/B_small0.out", "w", stdout);

	int T;
	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		int B;
		LL M;
		scanf("%d %lld", &B, &M);

		LL maxV = maxValue(B);

		//printf("%lld %lld\n", maxV, M);

		if (maxV < M) {
			printf("Case #%d: IMPOSSIBLE\n", cn);
			continue;
		} else {
			printf("Case #%d: POSSIBLE\n", cn);
		}


		LP(i, 0, B)
		{
			LP(j, 0, B)
			{
				if (i < j && j != B - 1) {
					printf("1");
				} else if (i >= j) {
					printf("0");
				} else {
					//printf("\n%d %d\n", i, j);
					assert(j == B-1);

					if (maxV == M ||
							(i >= 1 && ((M >> (i - 1)) % 2)))
						printf("1");
					else
						printf("0");

				}
			}

			printf("\n");
		}

	}

	return 0;
}
