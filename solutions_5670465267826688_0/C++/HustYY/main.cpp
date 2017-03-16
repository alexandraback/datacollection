#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int table[5][5]=
{
    {0,0,0,0,0},
    {0,1,2,3,4},
    {0,-2,-1,4,-3},
    {0,3,-4,-1,2},
    {0,4,3,-2,-1}
};

char s[11111];
int num[11111];

int calc(int x,int y)
{
    int neg=1;
    if (x<0) neg*=-1,x=-x;
    if (y<0) neg*=-1,y=-y;
    return neg*table[x][y];
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,l,x,product;
    bool flag;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%s",&l,&x,s);
        flag=1;
        for (int i=0;i<l;++i)
            if (s[i]=='1')
                num[i]=1;
            else if (s[i]=='i')
                num[i]=2;
            else if (s[i]=='j')
                num[i]=3;
            else num[i]=4;
        product=1;
        for (int i=0;i<l;++i) product=calc(product,num[i]);
        if (x%4==0||product==1||(product==-1&&x%2!=1)||(product!=-1&&x%2!=0)) flag=0;
        if (flag)
        {
            int l1=999999,l2=-1,tmp=1;
            for (int i=0;i<l&&l1>=l2;++i)
            {
                tmp=calc(tmp,num[i]);
                for (int j=0,tmp2=tmp,p=product;j<4&&j<x;++j,tmp2=calc(p,tmp),p=calc(p,product))
                {
                    if (tmp2==2) l1=min(l1,i+j*l);
                    if (tmp2==4)
                    {
                        l2=max(l2,i+j*l);
                        if (j+4<x) l2=max(l2,i+(j+4)*l);
                    }
                }
            }
            if (l1>=l2) flag=0;
        }
        printf("Case #%d: %s\n",cas,flag?"YES":"NO");
    }
    return 0;
}
