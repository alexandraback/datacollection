#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int T,L,N;
long long bagi[15];

int main() {
    scanf("%d",&T);
    scanf("%d %d",&L,&N);
    for (int i=2;i<=10;++i) {
        bagi[i] = 1;
        for (int j=1;j<=L/2;++j) bagi[i] *= i;
        ++bagi[i];
    }
    
    printf("Case #1:\n");
    for (int i=0;(i<N) && (i<(1<<(L/2-2)));++i) {
        printf("1");
        for (int j=L/2-3;j>=0;--j) printf("%d",(i & (1<<j))?1:0);
        printf("11");
        for (int j=L/2-3;j>=0;--j) printf("%d",(i & (1<<j))?1:0);
        printf("1");
        
        for (int j=2;j<=10;++j) cout<<" "<<bagi[j];
        printf("\n");
    }
    return 0;
}
