#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <functional>
#define X first
#define Y second
#define ll long long
#define PB(x) push_back((x))
#define MP(x,y) make_pair((x),(y))
#define CLR(x) memset((x),0,sizeof((x)))
using namespace std;
const int               Maxn=1000,Maxk=Maxn*Maxn,oo=INT_MAX>>2;
struct Edge {
    int u,v;
};
typedef pair<int, int>  F;
typedef int             Arr[Maxn];

//const int               s[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int                     i,j,n,m,ans;
Arr                     h,h1,d,num,l,r,s,d_d,d_p,d_s;
/*
int ask(int k,int l,int r,int x,int y)
{
    if (y<l||r<x) return 0;
    if (x<=l&&r<=y) return t[k];
    int mid=(l+r)/2;
    return ask(k*2,l,mid,x,y)+ask(k*2+1,mid+1,r,x,y);
    
}
void ins(int k,int l,int r,int pos)
{
    if (pos<l||pos>r) return;
    if (l==r) {
        t[k]++; return;
    }
    int mid=(l+r)/2;
    ins(k*2,l,mid,pos);
    ins(k*2+1,mid+1,r,pos);
    t[k]=t[k*2]+t[k*2+1];
}
bool ck(char ch)
{
    for (int i=0;i<5;i++) if (ch==YU[i]) return 0;
    return 1;
}*/
priority_queue<F,vector<F>,greater<F> > heap;
void work(F a)
{
    int i=a.Y;
    for (j=l[i];j<=r[i];j++)
    if (h[j]<s[i])
    {
//        cout<<a.X<<' '<<a.Y<<" ";
//        cout<<l[i]<<' '<<r[i]<<' '<<s[i]<<endl;
        ans++;
        break;
    }
    for (j=l[i];j<=r[i];j++) h1[j]=max(h1[j],max(h[j],s[i]));
    l[i]+=d_p[i];
    r[i]+=d_p[i];
    s[i]+=d_s[i];
    d[i]+=d_d[i];
    num[i]--;
    if (num[i]) heap.push(MP(d[i],i));
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("/Users/MAC/Desktop/Error202/Error202/1.in","r",stdin);
    freopen("/Users/MAC/Desktop/Error202/Error202/1.out","w",stdout);
    int tt=0,T;
    cin>>T;
    while(T--)
    {
        cout<<"Case #"<<++tt<<": ";
        CLR(h);
        CLR(h1);
        for (i=0;i<=500;i++) h[i]=0;
        ans=0;
        cin>>n;
        int ck=0;
        for (i=1;i<=n;i++)
        {
            cin>>d[i]>>num[i]>>l[i]>>r[i]>>s[i]>>d_d[i]>>d_p[i]>>d_s[i];
            r[i]--;
            if (num[i]) ck++;
            l[i]+=205; r[i]+=205;
            heap.push(MP(d[i],i));
        }
        while(heap.size())
        {
//            for (i=0;i<=450;i++) h1[i]=h[i];
            F p=heap.top();
            work(p);
            heap.pop();
            while (heap.size()&&heap.top().X==p.X)
            {
                p=heap.top();
                heap.pop();
                work(p);
            }
            for (i=0;i<=500;i++) h[i]=h1[i];
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
