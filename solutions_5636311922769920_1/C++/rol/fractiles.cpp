#include<cstdio>
using namespace std;

typedef unsigned long long ull;

ull K;

ull pow(ull base, ull exp){
    if(exp == 0) return 1;
    else return base*pow(base, exp-1);
}

/*
ull strike(ull C){
    if(C == 1) return 1;
    else return K*(strike(C-1)-1) + C;
}
*/
ull strike(ull start, ull end, ull C){
    ull acc = 0;
    for(ull offset = start - 1, i = 1; offset < end; ++offset, ++i){
        acc += offset*pow(K, C-i);
    }
    return acc + 1;
}

int main(){
    ull T, S, C, CaseNo = 1, s;
    scanf("%llu", &T);
    while(T--){
        scanf("%llu %llu %llu", &K, &C, &S);
        if(K > S*C){
            printf("Case #%llu: IMPOSSIBLE\n", CaseNo++);
            continue;
        }
        if(C >= K){
            printf("Case #%llu: %llu\n", CaseNo++, strike(1, K, C));
        } else {
            printf("Case #%llu:", CaseNo++);
            ull start = 1, end = start + C - 1;
            while(end < K){
                printf(" %llu", strike(start, end, C));
                start = end + 1; end = start + C - 1;
            }
            if(end != K){
                printf(" %llu", strike(start, K, C));
                /*
                if(start+1 == K){
                    printf(" %llu", start*pow(K, C-1) + 1);
                } else {
                    printf(" %llu", strike(start+1, K, C));
                }
                */
            } else {
                printf(" %llu", strike(start, end, C));
            }
            printf("\n");
        }
        /*
        if(K == 1){
            printf("Case #%llu: 1\n", CaseNo++);
            continue;
        }
        printf("Case #%llu:", CaseNo++);
        s = 1;
        while(C*(s-1) < K){
            printf(" %llu", C*(s-1)*pow(K, C-1) + strike(C));
            ++s;
        }
        printf("\n");
        */
    }
}
