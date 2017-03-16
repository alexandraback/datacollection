#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        int K,C,S;
        scanf("%d%d%d",&K,&C,&S);
        printf("Case #%d: ",_);
        long long p=1;
        for(int i=1;i<C;i++){
            p*=K;
        }
        for(int i=0;i<S;i++){
            if(i)printf(" ");
            printf("%I64d",i*p+1);
        }
        puts("");
    }
    return 0;
}
