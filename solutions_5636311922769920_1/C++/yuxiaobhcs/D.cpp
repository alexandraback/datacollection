#include<stdio.h>
#include<algorithm>
using namespace std;
//a^b
long long power(int a,int b) {
    long long res=1;
    for (int i=0; i<b; i++) {
        res*=a;
    }
    return res;
}
int main() {
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);

    int T,K,C,S;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d%d%d",&K,&C,&S);
        if (C*S<K) {
            printf("Case #%d: IMPOSSIBLE\n",cas);
            continue;
        }
        C=min(K,C);
        printf("Case #%d:",cas);
        int dep=1,x=0;
        long long pos=1;
        while (x<K || dep>1) {
            if (x<K) pos+=(long long)(x++)*power(K,C-dep);
            else pos+=(long long)(x-1)*power(K,C-dep);
            dep++;
            if (dep>C) {
                printf(" %lld",pos);
                pos=1;
                dep=1;
            }
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
