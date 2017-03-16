#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#define L(x) ((x)<<1)
#define R(x) (L(x)|1)

#define readFile

using namespace std;

const int MAX = 2000010;

typedef long long LL;

int N;

int posLen;
LL pos[MAX];

int tot;
struct In
{
    int wi,ei,di;
    int v;
}s[MAX];

vector <In> vi;

bool cmp(In a, In b)
{
    return a.di<b.di;
}

int mins[MAX*8];

void build(int x,int y,int z)
{
    mins[z] = 0;
    if(x != y)
    {
        int mid=(x+y)>>1;
        build(x,mid,L(z));
        build(mid+1,y,R(z));
    }
}

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

void push_down(int z,int l,int r)
{
    mins[l]=max(mins[l],mins[z]);
    mins[r]=max(mins[r],mins[z]);
}

void push_up(int z,int l,int r)
{
    mins[z]=min(mins[l],mins[r]);
}

void update(int x,int y,int l,int r,int z,int v)
{
    if(x==l && y==r)
    {
        mins[z]=max(mins[z],v);
        return;
    }
    int ll=L(z),rr=R(z);
    push_down(z,ll,rr);
    int mid=(l+r)>>1;
    if(y<=mid) update(x,y,l,mid,ll,v);
    else if(x>mid) update(x,y,mid+1,r,rr,v);
    else
    {
        update(x,mid,l,mid,ll,v);
        update(mid+1,y,mid+1,r,rr,v);
    }
    push_up(z,ll,rr);
}

int find_mins(int x,int y,int l,int r,int z)
{
    if(x==l && y==r)
    {
        return mins[z];
    }
    int ll=L(z),rr=R(z);
    push_down(z,ll,rr);
    int mid=(l+r)>>1;
    int k;
    if(y<=mid) k=find_mins(x,y,l,mid,ll);
    else if(x>mid) k=find_mins(x,y,mid+1,r,rr);
    else
    {
        k=min(find_mins(x,mid,l,mid,ll),
        find_mins(mid+1,y,mid+1,r,rr));
    }
    push_up(z,ll,rr);
    return k;
}

void update_mins()
{
    int i,j,len=vi.size();
    for(i=0;i<len;i++)
    {
        int l = find_pos(vi[i].wi),
        r = find_pos(vi[i].ei);
        update(l,r,1,2*posLen-1,1,vi[i].v);
    }
    vi.clear();
}

int doit()
{
    build(1, 2*posLen-1, 1);
    vi.clear();
    int i,j;
    int pre=-1;
    int res=0;
    for(i=0;i<tot;i++)
    {
        if(s[i].di!=pre)
        {
            update_mins();
            pre=s[i].di;
        }
        int l=find_pos(s[i].wi),r=find_pos(s[i].ei);
        if(find_mins(l,r,1,2*posLen-1,1) < s[i].v)
        res++;
        In a;
        a=s[i];
        vi.push_back(a);
    }
    return res;
}

int main()
{
    #ifdef readFile
        freopen("C-large.in","r",stdin);
        freopen("C-large.out", "w", stdout);
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
