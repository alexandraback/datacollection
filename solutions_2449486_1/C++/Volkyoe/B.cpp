#include"stdio.h"
#include"math.h"
#include"stdlib.h"
#include"string.h"
int a[105][105],m,n,i,j,t,T,row[105],col[105];
int OK = 1;
int main(){
    if(OK){
        freopen("1.in","r",stdin);
        freopen("1.txt","w",stdout);
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) row[i]=0;
        for(i=0;i<m;i++) col[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>row[i]) row[i]=a[i][j];
                if(a[i][j]>col[j]) col[j]=a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++) if(a[i][j]!=row[i] && a[i][j]!=col[j]) break;
            if(j<m) break;
        }
        printf("Case #%d: ",t);
        if(i<n) printf("NO\n");
        else printf("YES\n");
    }
    scanf(" ");
}
