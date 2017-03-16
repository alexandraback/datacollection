#include<stdio.h>
int n;
int flag=0;
int dfs(int par,int a[][n+1],int known[],int global)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[par][i]==1 && known[i]==0)
        {
            known[i]=1;
            dfs(i,a,known,global);
        }
        else if(a[par][i]==1 && known[i]==1)
        {
            flag=1;
            if(i==global)
                flag=0;
        }

    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    int f;
    for(f=0;f<t;f++)
    {
        scanf("%d",&n);
        int a[n+1][n+1];
        int i;
        int j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j]=0;
            }
        }
        for(i=1;i<=n;i++)
        {
            int no;
            scanf("%d",&no);
            for(j=0;j<no;j++)
            {
                int ans;
                scanf("%d",&ans);
                a[i][ans]=1;
            }
        }
        for(i=1;i<n;i++)
        {
            flag=0;
            int known[51]={0};
            known[i]=1;
            dfs(i,a,known,i);
            if(flag==1)
            {
                printf("Case #%d: Yes\n",f+1);
                break;
            }
        }
        if(flag==0)
                printf("Case #%d: No\n",f+1);

    }
    return 0;
}


