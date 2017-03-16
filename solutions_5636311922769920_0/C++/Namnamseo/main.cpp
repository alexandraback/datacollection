#include <cstdio>

typedef long long ll;

void read(int& a){ scanf("%d",&a); }
void read(ll& a){ scanf("%lld",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

ll pow(ll a,ll b){
    ll ret=1, tmp=a;
    for(int i=0;i<=30;++i){
        if(1&(b>>i)){
            ret *= tmp;
        }
        tmp=tmp*tmp;
    }
    return ret;
}

ll powk[110];

void work(){
    ll k,c,s;
    read(k,c,s);
    int i;
    powk[0]=1;
    for(i=1;i<=c;++i) powk[i]=powk[i-1]*k;
    ll mintry = (k+c-1)/c;
    if(mintry > s){
        puts("IMPOSSIBLE");
        return;
    }
    mintry *= c;
    ll cur=0;
    i=1;
    for(;mintry--;){
        cur=cur*k + i-1;
        if(i<k) ++i;
        if(mintry%c == 0){
            printf("%lld ",cur+1);
            cur=0;
        }
    }
    putchar(10);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    read(t);
    for(int tc=1;tc<=t;++tc){
        printf("Case #%d: ",tc); work();
    }
    return 0;
}
