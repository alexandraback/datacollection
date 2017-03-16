#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <functional>

using namespace std;

int maap[55][55];
int biit[55];

int main()
{
	int T;
	int B;
	long long int M;
	scanf("%d", &T);
	for (int t = 1;t <= T;t++) {
		scanf("%d %lld", &B, &M);
		long long int isp = (long long int)pow((double)2, (double)B - 2);
		printf("Case #%d: ", t);
		if (M > isp) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("POSSIBLE\n");
			for (int i = 1;i <= B;i++) {
				for (int j = 1;j <= B;j++) {
					maap[i][j] = 0;
				}
			}
			for (int i = 1;i <= B;i++) {
				for (int j = i + 1;j <= B;j++) {
					maap[i][j] = 1;
				}
			}
			long long int obit = isp - M;
			int cnt = 0;
			while (obit != 0) {
				biit[cnt] = obit % 2;
				obit /= 2;
				cnt++;
			}
			for (int i = 0;i < cnt;i++) {
				if (biit[i] == 1) {
					maap[2 + i][B] = 0;
				}
			}
			for (int i = 1;i <= B;i++) {
				for (int j = 1;j <= B;j++) {
					printf("%d", maap[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}