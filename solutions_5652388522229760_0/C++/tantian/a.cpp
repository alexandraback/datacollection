#include <cstdio>

int a;

void solve( int x ){
    if (x==0) a|=1;
    while (x>0){
        a|=1<<(x%10);
        x/=10;
    }
}

int main(){
    int T=0;
    scanf("%d", &T);
    for (int t=1; t<=T; ++t){
        printf("Case #%d: ", t);
        int n;
        scanf("%d", &n);
        a=0;
        for (int i=1; i<10000; ++i){
            solve(n*i);
            if ( a==1023 ){
                printf("%d\n", n*i);
                break;
            }
        }
        if ( a!=1023 )
            printf("INSOMNIA\n");
    }
}

