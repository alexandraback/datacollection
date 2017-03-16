#include<stdio.h>
typedef long long ll;
float a[100][100];
ll pw(int t)
{
    return 1<<t;
}
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);

    int t,cs,i,j,k,n,x,y,t1,t2,t3,t4,t5;
    a[1][0]=0.5;
    for(i=2;i<90;i++)
    {
        a[i][0]=(a[i-1][0]+1.0)/2.0;
        for(j=1;j<i;j++)
        a[i][j]=(a[i-1][j]+a[i-1][j-1])/2.0;
    }
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        scanf("%d %d %d",&n,&x,&y);
        if(x<0)x=-x;
        k=x+y;
        t1=k*(k-1)/2;
        t2=(k+1)*(k+2)/2;
        if(n<=t1)
        printf("0\n");
        else
        if(n>=t2)
        printf("1\n");
        else
        {
            t3=n-t1;
            if(y==k)
            printf("0\n");
            else
            if(t3<=k)
            printf("%f\n",a[t3][y]);
            else
            {
                t3-=k;
                if(y<t3)
                printf("1\n");
                else
                {
                    float d1,d2,d3,d4;
                    d1=1.0/pw(k);
                    d1=d1+(y-t3)/pw(t3+k);
                    d1=1.0-d1;
                    printf("%f\n",d1);
                }
            }
        }
    }
    return 0;
}
