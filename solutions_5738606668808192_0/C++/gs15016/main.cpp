#include <cstdio>
#include <algorithm>
using namespace std;

int n = 16, j = 50;

int pow(int a, int k){
    if(k == 0) return 1;
    return a * pow(a, k - 1);
}

int main(){
    freopen("C_small.out", "w", stdout);
    puts("Case #1:");
    for(int t = 0; t < 50; t++){
        for(int i = 0; i < 2; i++){
            printf("1");
            for(int j = 5; j >= 0; j--) printf("%c", (t & (1 << j))? '1' : '0');
            printf("1");
        }
        int k;
        for(int i = 2; i <= 10; i++){
            k = 0;
            k += pow(i, 0) + pow(i, 7);
            for(int j = 0; j < 6; j++) if(t & (1 << j)) k += pow(i, j + 1);
            printf(" %d", k);
        }
        puts("");
    }
}
