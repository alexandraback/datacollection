#include <map>
#include <cstdlib>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <cmath>
using namespace std;

#define MAXN 1000000

int rev (int x) {
    int acc = 0;
    while (x) {
        acc *= 10;
        acc += x % 10;
        x /= 10;
    }
    return acc;
}

int count[MAXN + 1];
int main () {

    for (int i = 1; i <= MAXN; i++)
        count[i] = i;

    for (int i = 1; i <= MAXN - 1; i++) {
        count[i+1] = min(count[i+1], count[i] + 1);
        int r = rev(i);
        if (r > MAXN) continue;
        count[r] = min(count[r], count[i] + 1);
    }

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
        int n; 
        scanf("%d", &n);
		printf("Case #%d: %d\n", i, count[n]);
    }

	return 0;
}
