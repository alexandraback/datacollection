#include<bits/stdc++.h>

using namespace std;

int a[2000000];
int q[3000000];
int swp(int x)
{
    int ans=0;
    while(x>0)
    {
        ans=(ans*10)+(x%10);
        x=x/10;
    }
    return ans;
}
int main()
{
    int i,t,n,b,c,f,r,y,x;
    scanf("%d",&t);
    for(i=1;i<=1000000;i++)
        a[i]=-1;
    for(i=1;i<=11;i++)
    a[i]=i;
    f=r=-1;
    r++;
    q[r]=11;
    while(f<r)
    {
        f++;
        x=q[f];
        if(x+1<=1000000)
        {
            if(a[x+1]==-1)
            {
                a[x+1]=a[x]+1;
                r++;
                q[r]=x+1;
            }
        }
        y=swp(x);
        if(y>x)
        {
            if(y<=1000000)
            {
                if(a[y]==-1)
                {
                    a[y]=a[x]+1;
                    r++;
                    q[r]=y;
                }
            }
        }
    }
    c=0;
    while(t--)
    {
        c++;
        scanf("%d",&n);
        printf("Case #%d: %d\n",c,a[n]);
    }
    return 0;
}
