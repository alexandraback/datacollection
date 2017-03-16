#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int T;
int K,C,S;

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        scanf("%d%d%d",&K,&C,&S);
        //small data set woop woop
        unsigned long long num = 1;
        printf("Case #%d: ",z);
        for (int i = 0; i < S; i++){
            printf("%lld ",num);
            num += (unsigned long long)pow(K,C-1);
        }
        printf("\n");
    }
    return 0;
}
