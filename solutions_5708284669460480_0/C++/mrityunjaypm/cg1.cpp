#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define mp  make_pair
#define pii pair<int,int>
#define fs  first
#define sc  second
#define     For(i,a,b)  for(int i=a;i<=b;++i)
#define     inf    (0x7f7f7f7f)//>2e9

template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
int K,TL,SL;
string keys;
string tword;
 
pii sol(int idx,string s)
{
    if(idx==SL)
    {
        int ans = 0;
        For(i,0,SL-TL)
        {
            if(!s.compare(i,TL,tword))ans++;
        }
        return mp(ans,ans);
    }
    pii ans = mp(0,-inf);
    For(i,0,K-1)
    {
        pii tmp = sol(idx+1,s+keys[i]);
        ans.sc = max(ans.sc,tmp.sc);
        ans.fs += tmp.fs;
    }
    return ans;
}
 
int main()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        cin>>K>>TL>>SL;
        cin>>keys;
        cin>>tword;
        pii ans = sol(0,"");
        double ok = (double)ans.sc-double(ans.fs)/double(pwr(K,SL));
        cout<<"Case #"<<t++<<": "<<setprecision(8)<<ok<<endl;
    }
    return 0;
}
