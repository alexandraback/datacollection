#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#include<limits.h>
#include<cmath>
#include<set>
#include<stack>
#include<deque>

using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t,r,c,w,x,y;

    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&r,&c,&w);
        x=1;
        y=0;
        while(x<=c)
        {
            y++;
            x+=w;
        }
        y=r*y;
        y+=(w-1);
        printf("Case #%d: %d\n",t,y);
    }
    return 0;
}
