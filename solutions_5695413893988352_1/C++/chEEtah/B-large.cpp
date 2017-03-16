#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
char a[100], b[100];
char fmt[100];
int len;

long long A[20][10][10][2];
long long B[20][10][10][2];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%s %s", a, b);
		len = strlen(a);
		sprintf(fmt, "%s%dI64d %s%dI64d\n", "%0", len, "%0", len);

		memset(A, -1, sizeof A);
		A[0][0][0][1] = 0;
		B[0][0][0][1] = 0;

		for(int i = 1; i <= len; i++)
		{
			char chA = a[i - 1];
			char chB = b[i - 1];

			for(int curA = 0; curA < 10; curA++)
			if (chA == '?' || chA == '0' + curA)
			for(int curB = 0; curB < 10; curB++)
			if (chB == '?' || chB == '0' + curB)
			for(int curD = 0; curD < 2; curD++)
			for(int prevA = 0; prevA < 10; prevA++)
			for(int prevB = 0; prevB < 10; prevB++)
			for(int prevD = 0; prevD < 2; prevD++)
			if (A[i - 1][prevA][prevB][prevD] != -1)
			{
				long long newA = curA + 10 * A[i - 1][prevA][prevB][prevD];
				long long newB = curB + 10 * B[i - 1][prevA][prevB][prevD];
				if ((newA <= newB) != curD) continue;
				long long newDiff = abs(newA - newB);			               

				long long oldA = A[i][curA][curB][curD];
				long long oldB = B[i][curA][curB][curD];
				long long oldDiff = abs(oldA - oldB);			               
				if (oldA == -1 || newDiff < oldDiff)
				{
					A[i][curA][curB][curD] = newA;
					B[i][curA][curB][curD] = newB;
					continue;
				}
				if (newDiff > oldDiff) continue;

				if (newA < oldA)
				{
					A[i][curA][curB][curD] = newA;
					B[i][curA][curB][curD] = newB;
					continue;					
				}
				if (newA > oldA) continue;

				if (newB < oldB)
				{
					A[i][curA][curB][curD] = newA;
					B[i][curA][curB][curD] = newB;
					continue;					
				}
			}
		}

		long long bestA = -1, bestB = 0;

		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				for(int k = 0; k < 2; k++)
				if (A[len][i][j][k] != -1)
				{
					long long newA = A[len][i][j][k];
					long long newB = B[len][i][j][k];
					long long newDiff = abs(newA - newB);			               
					long long oldDiff = abs(bestA - bestB);			               
					if (bestA == -1 || newDiff < oldDiff)
					{
						bestA = newA;
						bestB = newB;
						continue;
					}
					if (newDiff > oldDiff) continue;

					if (newA < bestA)
					{
						bestA = newA;
						bestB = newB;
						continue;					
					}
					if (newA > bestA) continue;

					if (newB < bestB)
					{
						bestA = newA;
						bestB = newB;
						continue;					
					}
				}

		printf(fmt, bestA, bestB);
	}
	return 0;
}