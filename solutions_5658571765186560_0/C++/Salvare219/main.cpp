#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int ti=1,t;scanf("%d",&t);
    while(t--)
    {
        int x,r,c,f;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c)swap(r,c);
        if(x>=7)f=0;
        else
        {
            if((r*c)%x==0)
            {
                if(x>c)f=0;
                if(x>=2*r+1)f=0;
                else if(2*r-1>x)f=1;
                else
                {
                    int res=x-r;
                    f=1;
                    for(int i=0;i<=res;i++)
                    {
                        int j=res-i;
                        int can=0;
                        for(int k=i;k<=c-j-1;k++)
                        {
                            int lef=k*r-i,rig=(c-k-1)*r-j;
                            if(lef%x==0&&rig%x==0)
                                can=1;
                        }
                        if(can==0)
                            f=0;
                    }
                }
            }
            else f=0;
        }
        printf("Case #%d: %s\n",ti++,f?"GABRIEL":"RICHARD");
    }
    return 0;
}
