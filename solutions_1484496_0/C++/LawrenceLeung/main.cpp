#include <cstdlib>
#include <iostream>

using namespace std;

int myMin(int a, int b)
{
	return a <= b ? a : b;
}

int main(int argc, char *argv[])
{
	int cId, nC;

	scanf("%d", &nC);
	for (cId = 1; cId <= nC; cId++)
	{
		printf ("Case #%d:\n", cId);

		int N;
		int v[20];
		scanf("%d", &N);
		for (int i = 0; i < N; scanf("%d", &v[i++]));

		char dp[2000001];
		int bFound = 0;
		for (int i = 1; i < (1 << N); i++) {
			int bitMask = i;
			int set1[20], set2[20];
			int nSet1, nSet2;
			nSet2 = nSet1 = 0;
			int sumSet1 = 0, sumSet2 = 0;
			for (int j = 0; j < N; j++) {
				if (bitMask & 1) {
					set1[nSet1++] = v[j];
					sumSet1 += v[j];
				} else {
					set2[nSet2++] = v[j];
					sumSet2 += v[j];
				}
				bitMask >>= 1;
			}

			//if (i < 10) printf ("%d %d %d\n", i, sumSet1, sumSet2);
			   
			if (sumSet1 > sumSet2) {
				continue;
			}

			memset(dp, 0, sumSet1+1);

			int test = 0;
			dp[0] = 1;
			int largestSum = 0;
			for (int j = 0; j < nSet2; j++)
			{
				int start = myMin(largestSum, sumSet1 - set2[j]);
				for (int k = start; k >= 0; k--) {
					if (dp[k] && dp[k+set2[j]] == 0) {
						dp[k+set2[j]] = j+1;
						if (k + set2[j] > largestSum) {
							largestSum = k + set2[j];
						}
						if (k + set2[j] == sumSet1) {
							break;
						}
					}
				}
			}
			if (dp[sumSet1] != 0)
			{
				bFound = 1;
				for (int j = 0; j < nSet1; j++) {
					if (j) putchar(' ');
					printf ("%d", set1[j]);
				}
				putchar('\n');
				int k = sumSet1;
				int first = 1;
				while(k > 0)
				{
					if (first) first = 0; else putchar(' ');
					printf ("%d", set2[dp[k]-1]);
					k -= set2[dp[k]-1];
				}
				putchar('\n');
				break;
			}
		}
		if (!bFound)
		{
			puts ("Impossible");
		}
	}
    return EXIT_SUCCESS;
}
