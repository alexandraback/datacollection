#include <cmath>
#include <cstdio>

using namespace std;

#define SMALL_CASE

int main() {
    #ifdef SMALL_CASE
        FILE *inp = fopen("A-small-attempt0.in", "r");
        FILE *oup = fopen("A-small-attempt0.out", "w");
    #else
        FILE *inp = fopen("A-large.in");
        FILE *oup = fopen("A-large.out");
    #endif

    int T;
    long long r, t;

    fscanf(inp, "%d", &T);
    for(int i = 0; i < T; ++i) {
        fscanf(inp, "%lld %lld", &r, &t);

        long long k = 0;
        while(++k)
            if((2*k*k)+(k*(2*r-1)) > t)
                break;

        fprintf(oup, "Case #%d: %lld\n", i+1, k-1);
    }

    fclose(oup);
    fclose(inp);

    return 0;
}
