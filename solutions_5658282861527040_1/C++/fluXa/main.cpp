#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int highestBit(uint64_t val) {
    int r = 0;
    while (val >>= 1) {
        r++;
    }
    return r;
}

void solve(int count) {
    uint64_t a, b, k;
    scanf("%llu %llu %llu\n", &a, &b, &k);
    
    if (a < b) {
        uint64_t tmp = a;
        a = b;
        b = tmp;
    }
    
    uint64_t res;
    if (k > a) {
        res = a*b;
    } else {
        uint64_t w = k;
        if (b < w) w = b;
    
        res = k*b + (a - k)*w;
        for (uint64_t aa = k; aa < a; ++aa) {
            for (uint64_t bb = w; bb < b; ++bb) {
                if ((aa & bb) < w) res++;
            }
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
