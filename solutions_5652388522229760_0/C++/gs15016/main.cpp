#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int tc, tcc = 1;
ll n, nn, k;
int chk;

int main(){
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &tc);
    while(tcc <= tc){
        scanf("%lld", &n);
        if(n == 0) nn = -1;
        else{
        chk = 0;
        nn = 0;
        while(chk != (1 << 10) - 1){
            nn += n;
            k = nn;
            while(k) chk |= (1 << (k % 10)), k /= 10;
            /*
            if(nn > n * n){
                nn = -1;
                break;
            }*/
        }
        }
        printf("Case #%d: ", tcc);
        if(nn < 0) puts("INSOMNIA");
        else printf("%lld\n", nn);
        tcc++;
    }
}
