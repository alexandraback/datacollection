#include <stdio.h>
#include <string.h>
int map[50][50];
int R,C,M;

int check(int i, int j, int limit, int count)
{
    int a,b,c,d;
    a=map[i][j];
    map[i][j]=1;
    if(a==0)count++;
    if(i+1<R)
    {
        b=map[i+1][j];
        map[i+1][j]=2;
        if(b==0)count++;
    }
    if(j+1<C)
    {
        c=map[i][j+1];
        map[i][j+1]=2;
        if(c==0)count++;
    }
    if(i+1<R&&j+1<C)
    {
        d=map[i+1][j+1];
        map[i+1][j+1]=2;
        if(d==0)count++;
    }
    if(count<R*C-M)
    {
        if(j+1<limit)
        {
            int val = check(i,j+1,limit,count);
            if(val==1)return 1;
        }
        if(i+1<R)
        {
            int val = check(i+1,0,j+1,count);
            if(val==1)return 1;
        }
    }
    if(count==R*C-M)
    {
        return 1;
    }
    map[i][j]=a;
    if(i+1<R)map[i+1][j]=b;
    if(j+1<C)map[i][j+1]=c;
    if(i+1<R&&j+1<C)map[i+1][j+1]=d;
    return 0;
}
int main()
{
    int t, T;
    freopen("C-large.in.txt","r",stdin);
	freopen("C-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(map,0,sizeof(map));
        scanf("%d%d%d",&R,&C,&M);
        int val = check(0,0,C,0);
        printf("Case #%d:\n",t);
        if(R*C-M==1)
        {
            for(int i=0;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    if(i==0&&j==0)
                    {
                        printf("c");
                        continue;
                    }
                    printf("*");
                }
                printf("\n");
            }
        }
        else if(val ==0)
        {
            printf("Impossible\n");
        }
        else
        {
            for(int i=0;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    if(i==0&&j==0)
                    {
                        printf("C");
                        continue;
                    }
                    if(map[i][j]==0)printf("*");
                    else printf(".");
                }
                printf("\n");
            }
        }
    }
    return 0;
}