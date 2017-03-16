#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct blq
{
    int x,y,i;
};
int cmp(blq t,blq t1)
{
    if(t.x==t1.x)return t.y<t1.y;
    return t.x<t1.x;
}
int cmp2(blq t,blq t1)
{
    if(t.y==t1.y)return t.x<t1.x;
    return t.y<t1.y;
}
int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        int n,i,br=0,brt=0,st=0,used[1024];
        memset(used,0,sizeof(used));
        blq a[1024],b[1024];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            blq p;
            scanf("%d%d",&p.x,&p.y);
            p.i=i;
            a[i]=p;
            b[i]=p;
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp2);
        int l=0,tp=0;
        while(brt<n)
        {
            if(st>=b[brt].y)
            {
                if(used[b[brt].i]==1)st++;
                else
                if(used[b[brt].i]==0)st+=2;
                used[b[brt].i]=2;
                brt++;
                br++;
                continue;
            }
            int i=tp,ti=-1;
            for(i=n-1;i>=0;i--)
            {
                if(st>=b[brt].y){break;}
                if(a[i].x<=st)
                {
                    if(!used[a[i].i])
                    {
                        used[a[i].i]=1;
                        st++;
                        br++;
                    }
                }
                if(st>=b[brt].y){break;}
            }
            if(i==-1&st<b[brt].y)
            {
                 printf("Case #%d: Too Bad\n",t,br);
                 l=1;
                 break;
            }
            if(l)break;
        }
        if(!l)
        printf("Case #%d: %d\n",t,br);
    }
    return 0;
}

