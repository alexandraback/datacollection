#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, b, m;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        printf("Case #%d: ", i);
        scanf("%d %d", &b, &m);
        if(m>1<<(b-2)) printf("IMPOSSIBLE\n");
        else{
            printf("POSSIBLE\n");
            m--;
            printf("0");
            for(int j=b-3; j>=0; j--) printf("%d", (m&(1<<j))>0);
            printf("1\n");
            for(int j=2; j<=b; j++) for(int k=1; k<=b; k++) printf("%d%c", j<k, (k==b)?'\n':0);
        }
    }
    return 0;
}