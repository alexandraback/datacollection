#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct STAR
{
    int a,b;
};
int n;
STAR da[100];
struct NOO
{
    int num;
    bool issmall;
    int pos;
};
bool cmp(NOO a,NOO b)
{
    return a.num<b.num;
}
int test( int x)
{
    bool is[100]={false};
    vector<NOO> list;
    int i;
    NOO t;
    for(i=0;i<n;i++)
    {
        if((1<<i)&x)
        {
            t.num=da[i].a;
            t.issmall=true;
            t.pos=i;
            is[i]=true;
            list.push_back(t);
        }
    }
    for(i=0;i<n;i++)
    {
        t.num=da[i].b;
        t.issmall=false;
        t.pos=i;
        list.push_back(t);
    }
    sort(list.begin(),list.end(),cmp);
    int now=0;
    int ans=0;
    for(vector<NOO>::iterator it=list.begin();it!=list.end();it++)
    {
        t=*it;
        if(t.num>now) return 1000;
        if(t.issmall)
        {
            now++;
            ans++;
        }
        else
        {
            now++;
            if(!is[t.pos]) now++;
            ans++;
        }
    }
    return ans;

}
void put(int ans,int cas)
{
    if(ans==2*n+1) printf("Case #%d: Too Bad\n",cas);
    else printf("Case #%d: %d\n",cas,ans);
}
void input()
{
    int tcas;
    scanf("%d",&tcas);
    int i;
    int cas;
    for(cas=1;cas<=tcas;cas++)
    {
        scanf("%d",&n);
//        cout << "--" << n << endl;
        for(i=0;i<n;i++)
            scanf("%d%d",&da[i].a,&da[i].b);
        int l=(1<<n)-1;
        int ans=2*n+1;
        for(i=0;i<=l;i++)
        {
            ans=min(ans,test(i));
        }
        put(ans,cas);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    input();
    return 0;
}
