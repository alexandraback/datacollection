#include <cstdio>
#include <cmath>
using namespace std;
long long int fraction(long long int, long long int);
int main(){
    long long int p, q, f, tmp;
    int t;
    scanf("%d", &t);
    for(int tt=1 ; tt<=t ; tt++){
        scanf("%lld/%lld", &p, &q);
        f=fraction(p, q);
        p=p/f;
        q=q/f;

        tmp=log2(q);

        printf("Case #%d: ", tt);
        if(pow(2, tmp)!=q){
            printf("impossible\n");
            continue;
        }
        if(p==1){
            printf("%d\n", tmp);
            continue;
        }

        tmp=1;
        while(p*2<q){
            q/=2;
            ++tmp;
        }
        printf("%d\n", tmp);
    }
}

long long int fraction(long long int p, long long int q){
    while(p>0 && q>0){
        if(p>q)
            p=p%q;
        else
            q=q%p;
    }
    if(p==0)
        return q;
    else
        return p;
}
