#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define REP(i, N) for(int i = 0; i < (N); i++)

using namespace std;

int main() {
	int T, testcase=1;
	scanf("%d", &T);
	while(T--) {
		int A,B,K;
		scanf("%d%d%d", &A, &B, &K);
		int ans = 0;
		for(int a = 0; a < A; a++)
			for(int b = 0; b < B; b++)
				if((a&b) < K)
					ans++;

		printf("Case #%d: %d", testcase++, ans);
		printf("\n");
	}
	
	return 0;
}
