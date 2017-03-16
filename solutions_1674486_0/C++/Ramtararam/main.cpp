#include <stdio.h>

inline int min(int a,int b){
    if(!a || !b) return 0;
    return a<b?a:b;
}

int main(){

    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);

    int n,m,b,t;
    int mtr[1000][1000];
    scanf("%d",&n);
    for(int h=0;h<n;++h){
        scanf("%d",&m);
        for(int k=0;k<m;++k){
            for(int j=0;j<m;++j)
                mtr[k][j] = 0;
            scanf("%d",&b);
            for(int j=0;j<b;++j){
                scanf("%d",&t);
                if(t>0)
                mtr[k][t-1] = 1;
            }
        }
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j)
                for(int k=0;k<m;++k)
                    mtr[j][k] += min(mtr[j][i],mtr[i][k]);

        bool ok = false;
        for(int k=0;k<m;++k){
            for(int j=0;j<m;++j)
                if(mtr[k][j] > 1){
                    ok = true;
                    break;
                }
            if(ok)break;
        }
        if(ok)
            printf("Case #%d: Yes\n",h+1);
        else
            printf("Case #%d: No\n",h+1);
    }
    return 0;
}
