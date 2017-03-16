#include <cstdio>

const int L = 16;
bool jc[16];

void step() {
    int i = 1;
    while(jc[i]) {
        jc[i] = 0;
        ++i;
    }
    jc[i] = 1;
}

long long pow(long long k) {
    long long r = 0;
    long long a = 1;
    for(int i = 0; i < L; ++i) {
        r += jc[i] * a;
        a *= k;
    }
    return r;
}

long long mod[20];

long long smod(long long k) {
    for(long long i = 2; i*i <= k; ++i) {
        if(k%i==0) return i;
    }
    return 0;
}

int main() {
    printf("Case #1:\n");
    jc[0] = jc[L-1] = 1;
    int db = 0;
    while(db < 50) {
        for(int i = 2; i <= 10; ++i) {
            if(!(mod[i] = smod(pow(i)))) goto st;
        }
        for(int i = L-1; i >= 0; --i) {
            printf("%d", jc[i]);
        }
        for(int i = 2; i <= 10; ++i) printf(" %lld", mod[i]);
        printf("\n");
        ++db;
        st:
        step();
    }
}
