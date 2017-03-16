#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>

using namespace std;
/*long long fuck[]={1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,100000000LL,
                  1000000000LL,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL
                 };

set<long long> myset;
set<long long>::iterator iter;
set<long long> myset2;
set<long long>::iterator iter2;

void DFS(int depth, int tot, long long num)
{
    if (depth>tot-depth)
    {
        myset.insert(num);
    }
    else
    {
        if (depth!=0)
        {
            for (int i=0;i<=9;i++)
            {
                long long tmp=(long long)i;
                if(depth!=tot-depth)
                   num+=fuck[depth]*tmp+fuck[tot-depth]*tmp;
                else
                   num+=fuck[depth]*tmp;
                DFS(depth+1,tot,num);
                if(depth!=tot-depth)
                   num-=fuck[depth]*tmp+fuck[tot-depth]*tmp;
                else
                   num-=fuck[depth]*tmp;
            }
        }
        else
        {
            for (int i=1;i<=9;i++)
            {
                long long tmp=(long long)i;
                if(depth!=tot-depth)
                   num+=fuck[depth]*tmp+fuck[tot-depth]*tmp;
                else
                   num+=fuck[depth]*tmp;
                DFS(depth+1,tot,num);
                if(depth!=tot-depth)
                   num-=fuck[depth]*tmp+fuck[tot-depth]*tmp;
                else
                   num-=fuck[depth]*tmp;
            }
        }
    }
}*/
long long ans[]={1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,
           102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,
           10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,
           1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,
           1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};
int find(long long num)
{
    int low=0,high=38,mid,pos=0;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(ans[mid]<=num)
        {
            pos=mid;
            low=mid+1;
        }
        else
           high=mid-1;
    }
    return pos;
}
int main()
{
    int cas,t=1;
    long long a,b;
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    /*for(int i=0;i<=13;i++)
    {
        DFS(0,i,0);
    }
    for(iter=myset.begin();iter!=myset.end();iter++)
    {
        long long num=*iter;
        if(num>10000000LL)
           break;
        long long sq=num*num;
        if(myset.find(sq)!=myset.end())
           printf("%I64d\n",sq);
    }*/
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%I64d%I64d",&a,&b);
        int s=find(a);
        int e=find(b);
        int res=0;
        for(int i=s;i<=e;i++)
           if(ans[i]>=a&&ans[i]<=b)
              res++;
        printf("Case #%d: %d\n",t++,res);
    }
return 0;
}
