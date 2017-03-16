#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
long long coinVar(int x,int base) {
    long long res=0;
    for (long long i=1; x>0; i*=base) {
        if (x & 1) res+=i;
        x/=2;
    }
    return res;
}
int main() {
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);

    int T,N,J,n;
    long long ds[20];
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d%d",&N,&J);
        printf("Case #%d:\n",cas);
        n=N;
        if (N>16) N/=2;
        int x=1;
        long long coin;
        for (int i=1; i<N; i++) x<<=1;
        x++;
        bool flag;
        while (J>0) {
            flag=true;
            for (int i=2; i<=10; i++) {
                coin=coinVar(x,i);
                long long sc=sqrt(coin);
                bool prime=true;
                for (long long j=2; j<=sc; j++) {
                    if (coin%j==0) {
                        prime=false;
                        ds[i]=j;
                        break;
                    }
                }
                if (prime) {
                    flag=false;
                    break;
                }
            }
            if (flag) {
                if (n>N) printf("%lld%lld",coinVar(x,10),coinVar(x,10));
                else printf("%lld",coinVar(x,10));
                for (int i=2; i<=10; i++)
                    printf(" %lld",ds[i]);
                printf("\n");
                J--;
            }
            x+=2;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
