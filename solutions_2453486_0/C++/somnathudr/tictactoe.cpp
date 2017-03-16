#include<stdio.h>
#include<iostream>
using namespace std;
#define dec(a) int a[4]
#define f(x,y,z) for(x=y;x<z;x++)
#define winx(c) printf("Case #%d: X won\n",c)
#define wino(c) printf("Case #%d: O won\n",c)
#define draw(c) printf("Case #%d: Draw\n",c)
#define no(c) printf("Case #%d: Game has not completed\n",c)
int main()
{
    int i,t,j;
    char a[4][4];
    cin>>t;
    int cas=1;
    while(t--)
    {
        int x1[4]={0},x2[4]={0},o1[4]={0},o2[4]={0},t1[4]={0},t2[4]={0},dot1[4]={0},dot2[4]={0},d1[4]={0},d2[4]={0};
        for(i=0;i<4;i++)
                scanf("%s",a[i]);
        for(i=0;i<4;i++)
        {
            if(a[i][i]=='X')
                d1[0]++;
            else if(a[i][i]=='O')
                d1[1]++;
            else if(a[i][i]=='T')
                d1[2]++;
            else
                d1[3]++;
        }
        int j=3;
        for(i=0;i<4;i++)
        {
            if(a[i][j]=='X')
                d2[0]++;
            else if(a[i][j]=='O')
                d2[1]++;
            else if(a[i][j]=='T')
                d2[2]++;
            else
                d2[3]++;
            j--;
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[i][j]=='X')
                {
                    x1[i]++;
                    x2[j]++;
                }
                else if(a[i][j]=='O')
                {
                    o1[i]++;
                    o2[j]++;
                }
                else if(a[i][j]=='T')
                {
                    t1[i]++;
                    t2[j]++;
                }
                else if(a[i][j]=='.')
                {
                    dot1[i]++;
                    dot2[j]++;
                }
            }
        }
        int over=0;
        if(d1[0]==4 || (d1[0]+d1[2])==4 || d2[0]==4 || (d2[0]+d2[2])==4)
        {
            winx(cas);
            over=1;
        }
        else if(d1[1]==4 || (d1[1]+d1[2])==4 || d2[1]==4 || (d2[1]+d2[2])==4)
        {
            wino(cas);
            over=1;
        }
        if(over==0)
        {
        for(i=0;i<4;i++)
        {
            if(x1[i]==4 || (x1[i] + t1[i])==4 || x2[i]==4 || (x2[i]+t2[i])==4)
            {
                winx(cas);
                over=1;
                break;
            }
            else if(o1[i]==4 || (o1[i]+t1[i])==4 || o2[i]==4 || (o2[i]+t2[i]==4))
            {
                wino(cas);
                over=1;
                break;
            }
        }}
        int f=0;
        if(over==0)
        {
            for(i=0;i<4;i++)
            {
                if(dot1[i]>0 || dot2[i]>0)
                {
                    no(cas);
                    f=1;
                    break;
                }
            }
            if(f==0)
                draw(cas);
        }
        cas++;
    }
    return 0;
}
