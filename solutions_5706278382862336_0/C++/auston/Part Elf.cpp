#include<cstdio>
#include<cmath>
using namespace std;

long long root = 1, p, q;
double d = 1;

int main(){

    int t, ca=1;
    scanf("%d", &t);

    for(int i=0; i<40; i++){
        root *= 2;
        d /= 10;
    }
    for(; t>0; t--){
        printf("Case #%d: ", ca++);
        scanf("%lld%*c%lld", &p, &q);
        if(((double)root/q)*p-floor(((double)root/q)*p)>d)
            puts("impossible");
        else{
            long long k = ((double)root/q)*p;
            int g = 40;
            while(k>=2){
                k /= 2;
                g--;
            }
            printf("%d\n", g);
        }
    }
    return 0;
}
