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
char aa[100], bb[100];
char fmt[100];

int gen;
char genNext()
{
	int d = gen % 10;
	gen /= 10;
	return '0' + d;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%s %s", a, b);
		sprintf(fmt, "%s%dd %s%dd\n", "%0", strlen(a), "%0", strlen(b));

		int bestA = 0, bestB = 1000000;
		for(int i = 0; i < 1000000; i++)
		{
			int j;
			gen = i;
			for(j = 0; a[j]; j++)
			{
				aa[j] = a[j];
				if (aa[j] == '?') aa[j] = genNext();
			}
			aa[j] = 0;
			for(j = 0; b[j]; j++)
			{
				bb[j] = b[j];
				if (bb[j] == '?') bb[j] = genNext();
			}
			bb[j] = 0;

			int A, B;
			sscanf(aa, "%d", &A);
			sscanf(bb, "%d", &B);
			if (abs(A - B) < abs(bestA - bestB))
			{
				bestA = A;
				bestB = B;
			}
			else
			if (abs(A - B) == abs(bestA - bestB) && A < bestA)
			{
				bestA = A;
				bestB = B;
			}
			else
			if (abs(A - B) == abs(bestA - bestB) && A == bestA && B < bestB)
			{
				bestA = A;
				bestB = B;
			}
		}

		printf(fmt, bestA, bestB);
	}
	return 0;
}