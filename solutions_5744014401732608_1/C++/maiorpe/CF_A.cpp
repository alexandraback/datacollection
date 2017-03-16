//Шаблон

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <utility>

#define ll long long
#define MAXN 200100

using namespace std;

struct point
{
    ll t;
    ll r;
    ll c;
    ll x;
    point(ll a=0, ll b=0,ll cc=0,ll d=0){
        t=a;
        r=b;
        c=cc;
        x=d;
    }
};

double sqr(double a){return a*a;}

int d[60][60];
int dp[3000];
ll ans[60];

int main()
{   
    ll n,t,b,m;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        cin>>b>>m;
        bool bb=false;
        cout<<"Case #"<<tt+1<<": ";
        ll max=1;
        max=(max<<(b-2));

        if(max>=m){
            cout<<"POSSIBLE"<<endl;
            cout<<0;
            if(m==max){
                for(int i=0;i<b-1;i++){
                    cout<<1;
                }
                cout<<endl;
            }else{
                for(int i=0;i<b-2;i++){
                    max=1;
                    max=(max<<(b-3-i));
                    if((m & max)==0){
                        cout<<0;
                    }else cout<<1;    
                }
                cout<<0<<endl;
            }
            for(int j=1;j<b;j++){
                for(int k=0;k<b;k++){
                    if(j<k)cout<<1;
                    else cout<<0;
                }
                cout<<endl;
            }
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
        cout<<endl;   
    }
    //cout<<fixed<<setprecision(16)<<ans<<endl;
    return 0;
}













    