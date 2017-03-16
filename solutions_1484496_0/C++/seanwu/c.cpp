#include <stdio.h>

int c[1000];
int a[100];
int b[100];

int dfs(int d,int s1,int s2,int n,int m){
    if(d==20){
        if(s1==s2 && n>0 && m>0){
            for(int i=0; i<n;i++){
                if(i) printf(" ");
                printf("%d",a[i]);
            }
            puts("");
            for(int i=0; i<m;i++){
                if(i) printf(" ");
                printf("%d",b[i]);
            }
            puts("");
            return 1;
        }
    }else{
        int t=a[n];
        a[n]=c[d];
        if(dfs(d+1,s1+c[d],s2,n+1,m)) return 1;
        a[n]=t;
        t=b[m];
        b[m]=c[d];
        if(dfs(d+1,s1,s2+c[d],n,m+1)) return 1;
        b[m]=t;
        if(dfs(d+1,s1,s2,n,m)) return 1;
    }
    return 0;
}

int main(){
    int tt,TT,i,n,s;
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ) {
        scanf("%d",&n);
        for( i=0; i<n; i++ ){
            scanf("%d",&c[i]);
        }
        printf("Case #%d:\n",tt+1);
        if(!dfs(0,0,0,0,0)){
            puts("Impossible");
        }
    }
    return 0;
}
