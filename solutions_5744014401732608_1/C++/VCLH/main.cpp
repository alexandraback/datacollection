#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, b;
    long long m;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        printf("Case #%d: ", i);
        scanf("%d %lld", &b, &m);
        long long x=1<<(b-2);
        if(m>1<<(b-2)) printf("IMPOSSIBLE\n");
        else{
            printf("POSSIBLE\n");
            m--;
            printf("0");
            for(int j=b-3; j>=0; j--){
                x=1<<j;
                printf("%d", (m&x)>0);
            }
            printf("1\n");
            for(int j=2; j<=b; j++) for(int k=1; k<=b; k++) printf("%d%c", j<k, (k==b)?'\n':0);
        }
    }
    return 0;
}