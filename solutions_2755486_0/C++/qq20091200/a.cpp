#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define L(x) ((x)<<1)
#define R(x) (L(x)|1)

#define readFile

using namespace std;

const int MAX = 1000010;

typedef long long LL;

int N;

int posLen;
int pos[MAX];

int tot;
struct In
{
    int wi,ei,di;
    int v;
}s[MAX];

bool cmp(In a, In b)
{
    return a.di<b.di;
}

int pre[MAX],now[MAX];

int find_pos(int x)
{
    int first=0,last=posLen-1,mid;
    while(first<=last)
    {
        mid=(first+last)>>1;
        if(pos[mid]==x) return mid*2+1;
        else if(pos[mid]>x) last=mid-1;
        else first=mid+1;
    }
}

int doit()
{
    int res=0;
    int i,j;
    for(i=1;i<=2*posLen;i++)
    {
        pre[i]=now[i]=0;
    }
    int k=-1;
    for(i=0;i<tot;i++)
    {
        if(s[i].di!=k)
        {
            k=s[i].di;
            for(j=1;j<=2*posLen;j++)
            pre[j]=now[j];
        }
        int l=find_pos(s[i].wi), r=find_pos(s[i].ei);
        bool z=false;
        for(j=l;j<=r;j++)
        if(pre[j]<s[i].v)
        {
            now[j]=max(now[j],s[i].v);
            z=true;
        }
        if(z) res++;
    }
    return res;
}

int main()
{
    #ifdef readFile
        freopen("C-small-attempt0.in","r",stdin);
        freopen("C-small-attempt0.out", "w", stdout);
    #endif
    int T,cas;
    scanf("%d",&T);
    for(cas = 1;cas <= T;cas++)
    {
        scanf("%d",&N);
        tot=posLen=0;
        for(int i=0;i<N;i++)
        {
            int di, ni, wi, ei, si,
            delta_di, delta_pi, delta_si;
            scanf("%d%d%d%d%d%d%d%d",&di,&ni,&wi,&ei,&si,
                  &delta_di,&delta_pi,&delta_si);
            for(int j=0;j<ni;j++)
            {
                pos[posLen++]=wi;
                pos[posLen++]=ei;
                s[tot].wi = wi;
                s[tot].ei = ei;
                s[tot].di = di;
                s[tot].v = si;
                tot++;
                di += delta_di;
                wi += delta_pi;
                ei += delta_pi;
                si += delta_si;
            }
        }
        sort(pos,pos+posLen);
        int i,j;
        for(j=i=1;i<posLen;i++)
        if(pos[i]!=pos[i-1])
        {
            pos[j++]=pos[i];
        }
        posLen=j;
        sort(s,s+tot,cmp);
        printf("Case #%d: %d\n", cas, doit());
    }
    return 0;
}
