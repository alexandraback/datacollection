#include<iostream>
using namespace std;
int matrix[101][101],n,m;
bool check()
{
    int i,j,k;
    for( i = 1; i <= n; i++)
    {
        for( j = 1; j <= m; j++)
        {
            int flag1=1,flag2=1;
            for( k = 1; k <= n; k++)
            {
                flag1 = ( matrix[k][j] <= matrix[i][j]);
                if(!flag1)
                    break;
            }
            for( k = 1; k <= m; k++)
            {
                flag2 = ( matrix[i][k] <= matrix[i][j]);
                if(!flag2)
                    break;
            }
            if(!( flag1 || flag2))
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int t,i;
    //freopen("a2.in","r",stdin);
    scanf("%d",&t);
    for( i = 1; i <= t; ++i)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
        printf("Case #%d: ",i);
        if(check())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
