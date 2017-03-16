//Author : Jatin Goyal
//codecracker4

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007  //NA
#define N 111111
#define ll long long int
#define dt ll
#define all(c) c.begin(), c.end()
#define dcl(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(dt i=a;i<=(dt)(b);i++)
#define tr(container, it) for(vector<dt> ::iterator it= container.begin(); it!=container.end(); it++)
#define trp(container, it) for(vector<pair<dt,dt> >::iterator it = container.begin(); it!=container.end(); it++)
#define cc1(a)cout<<#a<<": "<<a<<endl;
#define tra(container, it) for(typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
#define cc2(a,b)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<< endl;
#define cc3(a,b,c)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<endl;
#define cc4(a,b,c,d)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<" , "<<#d<<": "<<d<<endl;
#define pr pair<dt,dt>  //NA
#define mp(a,b) make_pair(a,b)
#define pb push_back  //NA
#define gc getchar  //NA
#define F first
#define S second
ll isprime(ll x)
{
    if(x==1) return -1;
    if(x==2) return -1;
    ll cur=sqrt(x);
    for(ll i=2;i<=cur;i++)
    {
        if(x%i==0) return i;
    }

    //if(x==63) cout<<"dsa";
    return -1;
}
int ct=1;
vector<int>vec[501];
int main()
{
	//freopen("##inp.cpp","r",stdin);
    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
	int len=16;
	rep(i,1<<(len-1),(1<<len)-1)
	{
	    vector<ll>dum;
	    if(i%2==0) continue;
	    int fg=0;
	    rep(j,2,10)
	    {
	        ll now=1,ans=0;
	        rep(k,0,len-1)
	        {
	            if((i>>k)&1) ans+=now;
	            now=now*j;
	        }
	        //if(i==63) cout<<ans<<endl;
            ll hh=isprime(ans);
	        if(hh==-1) break;
	        else dum.pb(hh);
	        if(j==10) fg=1;
	    }
	   // cc2(i,fg)
	    if(fg==1)
        {
            vec[ct].pb(i);
            tr(dum,it) vec[ct].pb(*it);
            ct++;
            if(ct==501) break;
        }
        dum.clear();
	}
	cout<<"Case #1:"<<endl;
	rep(i,1,50)
	{
	    int ok=vec[i][0];
	    vector<ll>now;
	    rep(j,0,len-1)
	    {
	        now.pb((ok>>j)&1);
	    }
	    reverse(all(now));
	    tr(now,it) cout<<*it;
	    cout<<' ';
	    rep(j,1,vec[i].size()-1) cout<<vec[i][j]<<' ';
	    cout<<endl;
	}
}
