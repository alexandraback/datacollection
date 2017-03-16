#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[111][111],n,m,t,tot,mxx;
bool b[111][111];
int main(){
    int i,j;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&t);
    for (int r=1;r<=t;r++){
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        tot=0;
        memset(b,0,sizeof(b));
        for (i=0;i<n;i++){
            mxx=0;
            for (j=0;j<m;j++)
                if (a[i][j]>mxx)
                   mxx=a[i][j];
            for (j=0;j<m;j++)
                if (!b[i][j]&&a[i][j]==mxx){
                    b[i][j]=1;
                    tot++;                            
                }      
        }
        for (j=0;j<m;j++){
            mxx=0;
            for (i=0;i<n;i++)
                if (a[i][j]>mxx)
                   mxx=a[i][j];
            for (i=0;i<n;i++)
                if (!b[i][j]&&a[i][j]==mxx){
                    b[i][j]=1;
                    tot++;                            
                }      
        }
        printf("Case #%d: ",r);
        if (tot==n*m)
           printf("YES\n");
        else
           printf("NO\n");
    }
    return 0;   
}
