#include<cstdio>
#include<cstdlib>


using namespace std;


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/



long long N;
long long MAX_N;
int t = 0;
int X, J;

int divisor[11];

int primes[10000000];
int p_n = 1;

void init() {
    N = 1;
    for(int i = 0; i < X-1; ++i) {
        N *= 2;
    }
    ++N;

    MAX_N = 1;
    for(int i = 0; i < X; ++i) {
        MAX_N *= 2;
    }

    primes[0] = 2;

    // i < 33333333
    for(int i = 3; p_n < 10000000 && i < 333333; i+=2) {
        int j = 0;
        for(; j < p_n; ++j) {
            if(i % primes[j] == 0) break;
        }
        if(j == p_n) {
            primes[p_n] = i;
            ++p_n;
        }
    }
}

long long base(int b, long long x) {
    if(x < 2) return x;
    return base(b, x / 2) * b + (x % 2);
}

int prime(int b, long long x) {
    for(int i = 0; i < p_n && primes[i] < x; ++i) {
        if(x % primes[i] == 0) {
            divisor[b] = primes[i];
            return 0;
        }
    }
    return 1;
}


void solve() {
    int i = 2;
    while(i <= 10) {
        if(prime(i, base(i, N))) {
            i = 2;
            N += 2;
            continue;
        }
        ++i;
        if(N >= MAX_N) {
            fprintf(stderr, "UNSOLVABLE\n");
            exit(1);
        }
    }
    return;
}

void print_bin(long long x) {
    if(x == 1) putchar('1');
    else {
        print_bin(x / 2);
        putchar('0'+(x%2));
    }
}

void print() {
    print_bin(N);
    for(int i = 2; i <= 10; ++i) {
        printf(" %d", divisor[i]);
        //printf(" %d\n", base(i, N));
    }
    printf("\n");

}


void solve_and_print() {
    int i = 0;

    scanf("%d %d", &X, &J);
    init();
    while(i < J) {
        solve();
        print();
        ++i;
        N += 2;
    }
}


int main() {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d:\n", case_num);

        solve_and_print();
    }

    return 0;
}
