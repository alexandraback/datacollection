#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int mar[55][55];

int T, B;
long long M;

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        cin >> B >> M;
        printf("Case #%d: ", cas);
        if(M > (1LL << (B - 2))) {
            puts("IMPOSSIBLE");
        }
        else {
            puts("POSSIBLE");
            memset(mar, 0, sizeof(mar));
            mar[1][B] = 1;
            for(int i = 2; i <= B - 1; i++) {
                mar[1][i] = 1;
                mar[i][B] = 1;
                for(int j = i + 1; j < B; j++) {
                    mar[i][j] = 1;
                }
            }
            long long res = (1LL << (B - 2)) - M;
            int now = 2;
            while(res > 0) {
                if(res & 1) {
                    mar[now][B] = 0;
                }
                res >>= 1;
                now++;
            }
            for(int i = 1; i <= B; i++) {
                for(int j = 1; j <= B; j++) {
                    printf("%d", mar[i][j]);
                }
                puts("");
            }
        }
        
    }
    return 0;
}