#include <stdio.h>

    int get_ceil(int a, int b) {
        if (a%b==0) 
            return a/b;
        return a/b+1;
    }
int main()
{
    int T;
    int K,C,S;
    scanf("%d", &T);
    for (int i=1;i<=T;i++) {
        scanf("%d %d %d", &K,&C,&S);
        printf("Case #%d: ", i);
        int num = get_ceil(K,C);
        if (S<num) {
            printf("IMPOSSIBLE\n");
            continue;
        }
//        printf("IMPOSSIBLE\n");
/*
        for (int j=0;j<num;j++) {
            int ans =0;
            for (int k=0;k<C && j*C+k<K ;k++) {
                ans *= K;
                ans += j*C+k;
            }
            printf("%d ", ans+1);
        }
*/
        for (int j=1;j<=S;j++) {
            printf("%d ", j);
        }
        printf("\n");
        

    }
    return 0;
}


