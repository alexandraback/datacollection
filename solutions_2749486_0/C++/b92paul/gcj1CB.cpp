#include<cstdio>
#include<string>
char move[4]={'E','W','N','S'};
char stmp[500];
int abs(int a){if(a<0)a=-a;return a;}
int main()
{
    int T,index=0;
    scanf("%d",&T);
    while(T--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        index++;

        int i=0;
        int a,b,c,d;
        if(x<=0)a=0,b=1;
        else a=1,b=0;
        for(int j=0;j<abs(x);j++)
        {
            stmp[i]=move[a];
            stmp[i+1]=move[b];
            i+=2;
        }
        if(y<=0)a=2,b=3;
        else a=3,b=2;
        for(int j=0;j<abs(y);j++)
        {
            stmp[i]=move[a];
            stmp[i+1]=move[b];
            i+=2;
        }
        stmp[i]='\0';
        printf("Case #%d: %s\n",index,stmp);
    }
}
