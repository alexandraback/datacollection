#include <cstdio>

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        int a[101][101];
        int mi[101],mj[101];
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        int ans=1; //yes
        for(int k=0;k<n;k++){
            mi[k]=0;
            for(int j=0;j<m;j++)if(mi[k]<a[k][j])mi[k]=a[k][j];
        }
        for(int k=0;k<m;k++){
            mj[k]=0;
            for(int i=0;i<n;i++)if(mj[k]<a[i][k])mj[k]=a[i][k];
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mi[i]>a[i][j] && mj[j]>a[i][j])ans=0;
        printf("Case #%d: ",C);
        if(ans)puts("YES");
        else puts("NO");

    }
    return 0;
}