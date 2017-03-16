#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;


void solve(int count) {
    uint64_t a, b, k;
    scanf("%llu %llu %llu\n", &a, &b, &k);
    
    uint64_t res = 0;
    for (uint64_t aa = 0; aa < a; ++aa) {
        for (uint64_t bb = 0; bb < b; ++bb) {
            if ((aa & bb) < k) res++;
        }
    }
    
    printf("Case #%d: ", count);
    printf("%llu\n", res);
}

int main(int argc, const char * argv[]) {
	int numCases = 0;
  	scanf("%d\n", &numCases);
    
    for (int count = 1; count <= numCases; ++count) {
        solve(count);
    }
    return 0;
}


/*
 uint64_t res = k*b;
 for (uint64_t aa = k; aa < a; ++aa) {
 if (aa < k) {
 res += b;
 } else {
 res += k;
 for (uint64_t bb = k; bb < b; ++bb) {
 if ((aa & bb) < k) res++;
 }
 }
 }
*/
