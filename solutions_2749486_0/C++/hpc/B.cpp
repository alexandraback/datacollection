#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 105
#define MAXL 505
using namespace std;
int X,Y;
int ans[MAXL];   //1==N 2==E  3==S  4==W
/*void process(int x,int y,int cnt)
{
    if(x<X)
    {
        ans[cnt++]=0;
    }
}*/
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T,Case;
    scanf("%d",&T);
    Case=T;
    int x,y;
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d%d",&X,&Y);
        printf("Case #%d: ",Case-T);
        x=0,y=0;
        for(int i=1;i<=500;++i)
        {
            //cout<<x<<" "<<y<<"\n";
            if(x<X)
            {
                ans[i]=4;
                ans[i+1]=2;
                x+=i+1;
                x-=i;
                i++;
            }
            else if(x>X)
            {
                ans[i]=2;
                ans[i+1]=4;
                x-=i+1;
                x+=i;
                i++;
            }
            else if(y<Y)
            {
                ans[i]=3;
                ans[i+1]=1;
                y-=i;
                y+=i+1;
                i++;
            }
            else if(y>Y)
            {
                ans[i]=1;
                ans[i+1]=3;
                y+=i;
                y-=i+1;
                i++;
            }
            else if(x==X&&y==Y)
            {
                for(int j=1;j<=i;++j)
                {
                    if(ans[j]==1) putchar('N');
                    else if(ans[j]==2) putchar('E');
                    else if(ans[j]==3) putchar('S');
                    else if(ans[j]==4) putchar('W');
                }
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}
