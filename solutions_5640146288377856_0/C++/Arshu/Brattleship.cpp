#include<bits/stdc++.h>
using namespace std;
int X;
int t,r,c,w,val;

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {X++;
        scanf("%d %d %d",&r,&c,&w);
        if(c%w==0)
        {
            val=r*(c/w)+(w-1);
        }
        else
            val=r*(c/w+1)+(w-1);

        printf("Case #%d: %d\n",X,val);
    }
return 0;
}
