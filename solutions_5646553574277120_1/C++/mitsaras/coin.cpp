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
        int C, D, V; 
        scanf("%d %d %d", &C, &D, &V);
        long long sum = 0;
        int add = 0;
        for (int j = 0; j < D; j++) {
            int d;
            scanf("%d", &d);
            while (sum < d - 1) {
                add++;
                sum += C * (sum+1);
            }
            sum += C * (long long) d;
        }
        while (sum < V) {
            add++;
            sum += C * (sum+1);
        }
            
		printf("Case #%d: %d\n", i, add);
    }

	return 0;
}
