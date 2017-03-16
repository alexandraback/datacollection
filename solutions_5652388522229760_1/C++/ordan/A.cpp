#include <bits/stdc++.h>

using namespace std;

int qtd[10];

bool lido (long long n){
    while (n){
        qtd[n%10]++;
        n /= 10;
    }
    for (int i = 0; i <= 9; i++)
        if (!qtd[i]) return false;
    return true;
}

int main(){

    int t, c = 1;
    scanf ("%d", &t);
    while (t--){
        memset(qtd, 0, sizeof qtd);
        int k;
        scanf ("%d", &k);
        if (k == 0){
            printf ("Case #%d: INSOMNIA\n", c++);
        } else {
            for (int i = 1; ; i++){
                long long n = 1LL * i * k;

                if (lido (n)){
                    printf ("Case #%d: %lld\n", c++, n);
                    break;
                }
            }
        }
    }

    return 0;
}

