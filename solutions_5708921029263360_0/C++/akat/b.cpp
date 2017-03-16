#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
map<pair<int,int>,int>jp,ps,js;
void solve()
{
    int k,j,p,s,ij,ip,is,o=0,x;
    cin>>j>>p>>s>>k;
    is=-1;
    for(ij=0;ij<j;++ij)
        for(ip=0;ip<p;++ip)
        {
            x=is;
            for(is=is+1;is<=x+s;++is)
            {
                if(jp[{ij,ip}]==k)continue;
                if(js[{ij,is%s}]==k)continue;
                if(ps[{ip,is%s}]==k)continue;
                o++;
                ++jp[{ij,ip}];
                ++js[{ij,is%s}];
                ++ps[{ip,is%s}];
            }
        }
    cout<<o<<endl;
    jp.clear();
    ps.clear();
    js.clear();
    is=-1;
    for(ij=0;ij<j;++ij)
        for(ip=0;ip<p;++ip)
        {
            x=is;
            for(is=is+1;is<=x+s;++is)
            {
                if(jp[{ij,ip}]==k)continue;
                if(js[{ij,is%s}]==k)continue;
                if(ps[{ip,is%s}]==k)continue;
                cout<<ij+1<<" "<<ip+1<<" "<<(is%s)+1<<endl;
                ++jp[{ij,ip}];
                ++js[{ij,is%s}];
                ++ps[{ip,is%s}];
            }
        }
    jp.clear();
    ps.clear();
    js.clear();
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
