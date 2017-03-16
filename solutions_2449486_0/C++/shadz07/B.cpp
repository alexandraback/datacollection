#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <algorithm>

#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se seconda
#define ll long long
#define mp make_pair
#define pb push_back
#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c; --a)
using namespace std;

int r, c, ar[105][105];

bool cariPathRow(int x, int bil) {
	FORU(j, 1, c)
		if (ar[x][j] > bil)
			return false;
	
	return true;
}

bool cariPathCol(int y, int bil) {
	FORU(i, 1, r)
		if (ar[i][y] > bil)
			return false;
	
	return true;
}

int main() {
	int T;
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%d %d", &r, &c);
		
		FORU(i, 1, r)
			FORU(j, 1, c)
				scanf("%d", &ar[i][j]);
		
		bool bisa = true;
		
		FORU(i, 1, r) {
			FORU(j, 1, c) {
				if (!(cariPathRow(i, ar[i][j]) || cariPathCol(j, ar[i][j])))
					bisa = false;
			}
		}
		
		printf("Case #%d: %s\n", tc, bisa?"YES":"NO");
	}
	
	return 0;
}
