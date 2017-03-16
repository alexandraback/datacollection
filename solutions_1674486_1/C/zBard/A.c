# include <stdio.h>


int main(void)
{
    //var
    int t,n,a,b,m;
    //loop
    int i,j,k,l,ans;
    int dig[1001][1001];

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d ",&n);
        for(k=1;k<=n;k++)
        {
            for(j=1;j<=n;j++)
            dig[k][j] = 0;
            
            scanf("%d ",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d ",&b);
                dig[k][b] = 1;
            }
        }
        /*
        for(j=1;j<=n;j++)
        {
        for(k=1;k<=n;k++)
        printf(" %d ",dig[j][k]);
        printf("\n");
        }
*/
        ans = 0;
        for(j=1;j<=n;j++)
        for(k=1;k<=n;k++)
        for(l=1;l<=n;l++)
        {
            dig[k][l] += dig[k][j]* dig[j][l];
            //printf("\n %d %d %d: %d",j,k,l,dig[j][k]);
            if(dig[k][l] > 1)
            {   
                ans =1;
                j = n+1;
                k = n+1;
                l = n+1;
            }
         }
  /*              
        for(j=1;j<=n;j++)
        {
        for(k=1;k<=n;k++)
        printf(" %d ",dig[j][k]);
        printf("\n");
        }
    */    
        if (ans)
        printf("Case #%d: Yes\n",i+1);
        else
        printf("Case #%d: No\n",i+1);

     }
            
    return 1;
}

        
