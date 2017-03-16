#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int dojudge(int);
struct Pt
{
    int a,b;
}PtData[100];
int n;
struct STR
{
    int num;
    bool shixiaode;
    int pos;
};
bool cmp(STR a,STR b)
{
    return a.num<b.num;
}
int main()
{
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    int l,ans;
    for(int cases = 1;cases <= t;cases ++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&PtData[i].a,&PtData[i].b);
        l=(1<<n);
        ans=2*n+1;
        l--;
        for(int i=0;i<=l;i++)
        {
            int tem = dojudge(i);
            if(ans>tem) ans = tem;
        }
        if(ans==2*n+1) printf("Case #%d: Too Bad\n",cases);
        else printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
int dojudge(int x)
{
    int FakeAns=0;
    int ans=0;
    bool is[100];
    memset(is,0,sizeof(is));
    vector <STR> VecListAns;
    STR t;
    for(int i=0;i<n;i++)
    {
        if((1<<i)&x)
        {
            t.num=PtData[i].a;
            t.shixiaode=true;
            t.pos=i;
            is[i]=true;
            VecListAns.push_back(t);
        }
    }
    for(int i=0;i<n;i++)
    {
        t.num=PtData[i].b;
        t.shixiaode=false;
        t.pos=i;
        VecListAns.push_back(t);
    }
    sort(VecListAns.begin(),VecListAns.end(),cmp);
    for(vector<STR>::iterator it=VecListAns.begin();it!=VecListAns.end();it++)
    {
        t=*it;
        if(t.num>FakeAns) return 1000;
        if(t.shixiaode)
        {
            FakeAns = FakeAns + 1;ans = ans + 1;
        }
        else{
            FakeAns++;
            if(!is[t.pos]) FakeAns++;
            ans++;
        }
    }
    return ans;

}
