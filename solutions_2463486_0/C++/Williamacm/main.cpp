#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
const int N=1e7+1;
vector<ll> a;
bool check(ll i)
{
    vector<int> b;
    while(i)
    {
        b.push_back(i%10);
        i/=10;
    }
    for(int i=0;i<(b.size()>>1);i++)
    if(b[i]!=b[b.size()-1-i]) return 0;
    return 1;
}
void pre()
{
    for(ll i=0;i<N;i++)
    if(check(i))
    {
        ll k=i*i;
        if(check(k)) a.push_back(k);
    }
//    for(int i=0;i<a.size();i++)printf("%lld\n",a[i]);
}
int get(ll x)
{
    int s=0,t=a.size()-1;
    while(s<=t)
    {
        int mid=(s+t)>>1;
        if(a[mid]>x) t=mid-1;
        else s=mid+1;
    }
    return t;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    pre();
    int w,cnt=1;cin>>w;
    while(w--)
    {
        printf("Case #%d: ",cnt++);
        ll s,t;scanf("%lld%lld\n",&s,&t);
        s--;
        printf("%d\n",get(t)-get(s));
    }
    return 0;
}
