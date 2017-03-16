#include <iostream>
#include <cstdio>
#include <cmath>
#define ui unsigned int
#define ull unsigned long long

using namespace std;

const int N = 16, J = 50;
int cnt = 0;

ull prime(ull n){
    if (n <= 1) return -1;
    if (n <= 3) return -1;
    if (n%2==0) return 2;
    if (n%3==0) return 3;
    for (ull i = 5; i*i <= n; i += 6){
        if (n%i==0) return i;
        if (n%(i+2)==0) return i+2;
    }
    return -1;
}

ull toBase10(ull n, int base){
    ull num = 0;
    int p = 0;
    while(n){
        num += (ull)(n%2)*pow(base,p++);
        n >>= 1;
    }
    return num;
}

int main(){
    freopen("data.out","w",stdout);
    printf("Case #1:\n");
    for (ui i = 1<<(N-1); i <= 1<<N; i++){
        if (!(i%2)) continue;
        bool flag = 1;
        for (int j = 2; j <= 10; j++){
            ull num = toBase10(i,j);
            if (prime(num) == -1){
                flag = 0;
                break;
            }
        }
        if (flag){
            for (int j = N-1; j >= 0; j--){
                printf("%d",(bool)(i&(1<<j)));
            }
            for (int j = 2; j <= 10; j++){
                printf(" %lld",prime(toBase10(i,j)));
            }
            printf("\n");
            cnt++;
        }
        if (cnt >= J) break;
    }
    return 0;
}
