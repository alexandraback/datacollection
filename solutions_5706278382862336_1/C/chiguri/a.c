#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long P, Q;

long long gcd(long long p1, long long p2) {
    long long t;
    while(p1 % p2) {
        t = p2;
        p2 = p1 % p2;
        p1 = t;
    }
    return p2;
}


int solve(long long p1, long long q1) {
    int t = 0;
    long long g = gcd(p1, q1);
    p1 /= g; q1 /= g;

    for(t = 0, g = 1; t < 40; ++t) {
        if(q1 == g) break;
        g *= 2;
    }
    if(t == 40) return -1;

    t = 0;
    while(t <= 40) {
        p1 *= 2; // 0/1¢‘ã‚ÆŠ|‚¯‡‚í‚¹
        ++t;
        if(p1 >= q1) return t;
    }
    return -1; // impossible
}


int main(void) {
    int dataset_num, case_num;
    int i, j, k;


    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%lld/%lld", &P, &Q);

        printf("Case #%d:", case_num);
        if((i = solve(P, Q)) > 0) {
            printf(" %d\n", i);
        }
        else {
            printf(" impossible\n");
        }
    }

    return 0;
}
