#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

char a[20], b[20];
ll err;
ll p10[18];
int tc, len, cnt, ai, aj;
ll mm;
int mi, mj;

bool acceptable(int x, char *s){
    for(int i = len - 1; i >= 0; i--){
        if((s[i] != '?') && ((s[i] - '0') != (x % 10))) return false;
        x /= 10;
    }
    return true;
}

int main(){
    freopen("Bs.in", "r", stdin);
    freopen("Bs.out", "w", stdout);
    p10[0] = 1; p10[1] = 10; p10[2] = 100; p10[3] = 1000;
    scanf("%d", &tc);
    for(int ttc = 1; ttc <= tc; ttc++){
        mm = 1e5;
        scanf("%s%s", a, b);
        len = strlen(a);
        for(int i = 0; i < p10[len]; i++){
            for(int j = 0; j < p10[len]; j++){
                if(acceptable(i, a) && acceptable(j, b) && mm > abs(i - j)){
                    mm = abs(i - j);
                    ai = i; aj = j;
                }
            }
        }
        for(int i = len - 1; i >= 0; i--){
            a[i] = (ai % 10) + '0';
            ai /= 10;
            b[i] = (aj % 10) + '0';
            aj /= 10;
        }
        printf("Case #%d: %s %s\n", ttc, a, b);
    }
}
