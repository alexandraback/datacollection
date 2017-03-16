#include<bits/stdc++.h>
using namespace std;
#define     mp              make_pair
#define     fs              first
#define     inf             (0x7f7f7f7f)//>2e9
#define     For(i,a,b)      for(int i=a;i<=b;++i)
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
int K,TL,SL;
string keys;
string tword;

pair<int,int> sol(int idx,string s)
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
    pair<int,int> ans = mp(0,-inf);
    For(i,0,K-1)
    {
        pair<int,int> tmp = sol(idx+1,s+keys[i]);
        ans.second = max(ans.second,tmp.second);
        ans.fs += tmp.fs;
    }
    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int T,t=1;
    cin>>T;
    for(int t=1;t<=T;t++)
    {

        cin>>K>>TL>>SL;
        cin>>keys;
        cin>>tword;
        pair<int,int> ans = sol(0,"");
        double ok = (double)ans.second-double(ans.fs)/double(pwr(K,SL));
        cout<<"Case #"<<t<<": "<<setprecision(8)<<ok<<endl;
    }
    return 0;
}
