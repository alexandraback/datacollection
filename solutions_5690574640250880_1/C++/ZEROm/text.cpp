#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        int r,c,m;
        scanf("%d%d%d",&r,&c,&m);
        m=r*c-m;
        int minn=min(r,c);
        printf("Case #%d:\n",++Case);
        if(m==1)
        {
            for(int i=0;i<r;++i)
            {
                for(int j=0;j<c;++j)
                if(m)
                {
                    if(i==0&&j==0)printf("c");
                    else printf(".");
                    --m;
                }
                else printf("*");
                printf("\n");
            }
        }
        else if(minn==1)
        {
            if(m>1)
            {
                for(int i=0;i<r;++i)
                {
                    for(int j=0;j<c;++j)
                    if(m)
                    {
                        if(i==0&&j==0)printf("c");
                        else printf(".");
                        --m;
                    }
                    else printf("*");
                    printf("\n");
                }
            }
            else printf("Impossible\n");
        }
        else if(minn==2)
        {
            if(m>=4&&m%2==0)
            {
                if(r==2)
                {
                    for(int i=0;i<r;++i)
                    {
                        for(int j=0;j<c;++j)
                        if(j<m/2)
                        {
                            if(i==0&&j==0)printf("c");
                            else printf(".");
                        }
                        else printf("*");
                        printf("\n");
                    }
                }
                else
                {
                    for(int i=0;i<r;++i)
                    {
                        for(int j=0;j<c;++j)
                        if(m)
                        {
                            if(i==0&&j==0)printf("c");
                            else printf(".");
                            --m;
                        }
                        else printf("*");
                        printf("\n");
                    }
                }
            }
            else printf("Impossible\n");
        }
        else
        {
            if((m>=4&&m%2==0)||m>=9)
            {
                char M[55][55];
                for(int i=0;i<r;++i)
                    for(int j=0;j<c;++j)
                    M[i][j]='*';
                for(int i=0;i<3;++i)
                    if(m)M[i][0]=M[i][1]='.',m-=2;
                if(m)M[0][2]=M[1][2]='.',m-=2;
                for(int i=3;i<c;++i)
                    if(m>1)M[0][i]=M[1][i]='.',m-=2;
                for(int i=3;i<r;++i)
                    if(m>1)M[i][0]=M[i][1]='.',m-=2;
                for(int i=2;i<r;++i)
                    for(int j=2;j<c;++j)
                    if(m)M[i][j]='.',--m;
                M[0][0]='c';
                for(int i=0;i<r;++i)
                {
                    for(int j=0;j<c;++j)
                        printf("%c",M[i][j]);
                    printf("\n");
                }
            }
            else printf("Impossible\n");
        }
    }
    return 0;
}
