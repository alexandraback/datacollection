#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
using namespace std;
struct Node
{
    int a,b,t;
}node[1010];
int n;

bool cmp1(const Node &a,const Node &b)
{
    if(a.t != b.t)
    return a.t<b.t;
    if(a.t != 0)
    return true;
    return a.a<b.a;
}
bool cmp2(const Node &a ,const Node &b)
{
    return a.b<b.b;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    for(int ca=1;ca<=cases;ca++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].a,&node[i].b);
            node[i].t=0;
        }
        bool flag=true;
        int num=0;
        int cnt=n;
        int res=0;
        while(flag)
        {
            flag=false;
            for(int i=0;i<n;i++)
            {
                if(node[i].t!=2 && node[i].b<=num)
                {
                    flag=true;
                    num+=2-node[i].t;
                    node[i].t=2;
                    cnt--;
                    res++;
                }
            }
            if(flag) continue;
            sort(node,node+n,cmp1);
            int p=-1;
            for(int i=0;i<n;i++)
            {
                if(node[i].t==0 && node[i].a<=num)
                {
                    continue;
                }
                else
                {
                    p=i;
                    break;
                }
            }
            if(p==0)
            {
                flag = false;
                break;
            }
            if(p==-1)
            {
                p=n;
            }
            sort(node,node+p,cmp2);
            num+=1;
            node[p-1].t=1;
            flag=true;
            res++;
        }
        if(cnt == 0)
        {
            printf("Case #%d: %d\n",ca,res);
        }
        else
        {
            printf("Case #%d: Too Bad\n",ca);
        }
    }
}
