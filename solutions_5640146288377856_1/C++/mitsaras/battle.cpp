#include <map>
#include <cstdlib>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <cmath>
using namespace std;

int main () {

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
        int C,R,W; 
        scanf("%d %d %d", &R, &C, &W);
        int res = R * C / W + W;
        if (C % W == 0)
            res--;
        printf("Case #%d: %d\n", i, res);
    }

	return 0;
}
