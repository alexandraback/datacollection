#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int comp(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

int n, a[110][110], w, h;
bool ur[110], uc[110];

int arrMin() {
	int m = -1;
	for (int i = 0; i < h; i++) {
		if (ur[i]) 
			continue;
		for (int j = 0; j < w; j++) {
			if (uc[j]) 
				continue;
			if (m == -1 || a[i][j] < m) 
				m = a[i][j];
		}
	}
	return m;
}

bool goodRow(int i, int m) {
	for (int j = 0; j < w; j++) 
		if (!uc[j] && a[i][j] != m) 
			return 0;
	return 1;
}

bool goodCol(int j, int m) {
	for (int i = 0; i < h; i++) 
		if (!ur[i] && a[i][j] != m) 
			return 0;
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {		
		scanf("%d%d", &h, &w);
		for (int i = 0; i < h; i++)		
			for (int j = 0; j < w; j++)
				scanf("%d", &a[i][j]);
		for (int i = 0; i < h; i++)
			ur[i] = 0;
		for (int i = 0; i < w; i++)
			uc[i] = 0;

		//for (int i = 0; i < h; i++) {			
		//	for (int j = 0; j < w; j++)
		//		printf("%d ", a[i][j]);
		//	printf("\n");
		//}

		printf("Case #%d: ", t);
		while (1) {			
			int m = arrMin(), res = 0;
			if (m == -1) {
				printf("YES\n");
				break;
			}
			for (int i = 0; i < h; i++)
				if (!ur[i])
					res |= ur[i] = goodRow(i, m);
			for (int i = 0; i < w; i++)
				if (!uc[i])
					res |= uc[i] = goodCol(i, m);
			if (!res) {
				printf("NO\n");
				break;
			}
		}		
	}
	return 0;
}