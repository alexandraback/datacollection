#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int N,c[1000][3];
        scanf("%d",&N);
        int stars=0,complete=0,game=0;
        bool change;
        for(int j=0;j<N;j++)
        {
            scanf("%d %d",&c[j][0],&c[j][1]);
            c[j][2]=0;
        }
        while(complete<N)
        {
            if(game==-1)
                break;
            change=false;
            int min=65500;
            int k;
            for(k=0;k<N;k++)
            {
                if(c[k][2]==2)
                    continue;
                if(c[k][1]<=stars)
                {
                    stars=stars+2-c[k][2];
                    c[k][2]=2;
                    change=true;
                    game++;
                    complete++;
                }
                else
                {
                    if(min>c[k][1])
                        min=c[k][1];
                }
            }
            if(change==false)
            {
                for(k=0;k<N;k++)
                {
                    if(c[k][2]>=1)
                        continue;
                    if(c[k][0]<=stars && c[k][1]!=min)
                    {
                        stars=stars+1-c[k][2];
                        c[k][2]=1;
                        game++;
                        change=true;
                        if(stars>=min)
                            break;
                    }
                }
                if(change==false)
                {
                    for(k=0;k<N;k++)
                    {
                        if(c[k][2]>=1)
                            continue;
                        if(c[k][0]<=stars)
                        {
                            stars=stars+1-c[k][2];
                            c[k][2]=1;
                            game++;
                            change=true;
                            if(stars>=min)
                                break;
                        }
                    }
                    if(change==false)
                        game=-1;
                }
            }
        }
        if(game==-1)
            printf("Case #%d: Too Bad\n",i+1);
        else
            printf("Case #%d: %d\n",i+1,game);
    }
    return 0;
}
