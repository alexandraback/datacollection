//program : LAWNMOWER
#include<cstdio>
int lawn[101][101];
inline void scan(int *a)
{
    char c = 0;
    while(c<33)
        c = getc(stdin);
    *a = 0;
    while(c>33)
    {
        *a = *a*10 + c - '0';
        c = getc(stdin);

    }
}
int main()
{
    int t,n,m,i,j,flag=1,k=1;
    scan(&t);
    while(k<=t)
    {
        printf("Case #%d: ",k);
        scan(&n);
        scan(&m);
        // scanf("%d",&m);
        //printf("n=%d m=%d\n",n,m);
        for(i=1; i<=n; i++)
            lawn[i][0]=0;
        for(j=1; j<=m; j++)
            lawn[0][j]=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&lawn[i][j]);
                if(lawn[i][j]>lawn[i][0])
                    lawn[i][0]=lawn[i][j];
                if(lawn[0][j]<lawn[i][j])
                    lawn[0][j]=lawn[i][j];
            }
        }
        flag=1;
//printf("n=%d m=%d\n",n,m);
        for(i=1; (i<=n)&&flag; i++)
        {
            for(j=1; j<=m; j++)
            {
                //  printf("i= %d j= %d lawn[i,j]= %d lawn[i][0]= %d lawn[0][j]= %d %d\n",i,j,lawn[i][j],lawn[i][0],lawn[0][j],(lawn[i][j]==lawn[i][0])||(lawn[i][j]==lawn[0][j]));
                if((lawn[i][j]!=lawn[i][0])&&(lawn[i][j]!=lawn[0][j]))
                {
                    flag=0;
                    break;
                    //continue;

                }
            }
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
        //fflush(stdin);
        k++;
    }
    return 0;
}
