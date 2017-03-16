#include <cstdio>
#include <vector>

using namespace std;

int A[20];
bool used[20];
bool ans[20];
int sum1, sum2;
bool exit;

void calc2(int n){
    if(n == 20){
        if(sum1 == sum2){
            for(int i = 0; i < 20; ++i){
                if(used[i]){
                    printf("%d ", A[i]);
                }
            }
            printf("\n");
            for(int i = 0; i < 20; ++i){
                if(ans[i]){
                    printf("%d ", A[i]);
                }
            }
            printf("\n");
            exit = true;
        }
        return;
    }
    if(used[n]){
        calc2(n + 1);
        return;
    }
    if(sum2 + A[n] <= sum1){
        ans[n] = true;
        sum2 += A[n];
        calc2(n + 1);
        if(exit) return;
        ans[n] = false;
        sum2 -= A[n];
    }
    calc2(n + 1);
}

void calc(int n){
    if(n == 20){
        calc2(0);
        return;
    }
    used[n] = true;
    sum1 += A[n];
    calc(n + 1);
    if(exit) return;
    sum1 -= A[n];
    used[n] = false;
    calc(n + 1);
}

void newprob(int k){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &A[i]);
    }
    printf("Case #%d:\n", k);
    exit = false;
    for(int i = 0; i < 20; ++i){
        ans[i] = false;
        used[i] = false;
    }
    sum1 = sum2 = 0;
    calc(0);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) newprob(i);
    return 0;
}
