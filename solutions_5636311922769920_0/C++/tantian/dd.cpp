#include <cstdio>

int a[200][200];

void prepare(){
    a[1][0]=1;
    for (int i=2; i<=100; ++i){
        a[i][0]=2;
        if (i%2==0) a[i][i/2-1]=i*(i-1); else a[i][i/2]=i;
        for (int j=1; j<(i+1)/2-1; ++j)
           a[i][j]=a[i-1][j]+j*2; 
    }
}

int main(){
    prepare();
    int T=0;
    scanf("%d", &T);
    for (int t=1;t<=T;++t){
        printf("Case #%d:",t);
        int K,C,S;
        scanf("%d%d%d", &K,&C,&S);
        if (C==1){
            if (K==S){
                for (int i=1;i<=K;++i)
                    printf(" %d", i);
                printf("\n");
            } else
                printf(" IMPOSSIBLE\n");
        } else {
            int n=(K+1)/2;
            if (S<n)
                printf(" IMPOSSIBLE\n");
            else {
                for (int i=0; i<n; ++i)
                    printf(" %d", a[K][i]);
                printf("\n");
            }
        }
    }
}

