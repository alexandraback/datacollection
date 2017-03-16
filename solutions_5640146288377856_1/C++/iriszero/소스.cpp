#define _CRT_SECURE_NO_WARNINGS
#define FOR(i, n) for (int i=0; i<n; i++)

#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;
int main(void) {

	//freopen("c:\\input.txt", "r", stdin);
	//freopen("c:\\output.txt", "w", stdout);
	int t; scanf("%d", &t);
	FOR(i, t) {
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		int ret = r * ((int)(c / w)) + w;
		if (c % w == 0) ret--;
		printf("Case #%d: %d\n", i+1, ret);
	}




	return 0;
}