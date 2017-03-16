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
int ans[60];

int main()
{   
    int n,t,b,m;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        cin>>b>>m;
        int aaa=(b*(b-1)/2);
        bool bb=false;
        cout<<"Case #"<<tt+1<<": ";
        for(int i=1;i<(1<<aaa);i++){
            for(int j=0;j<aaa;j++)
                if((i & (1<<j))==0 ){
                    dp[j]=0;
                }else{
                    dp[j]=1;
                }
            int ind=0;
            for(int j=0;j<b-1;j++){
                for(int k=j+1;k<b;k++){
                    d[j][k]=dp[ind];
                    ind++;
                }
            }
            for(int j=1;j<b;j++)ans[j]=0;
            ans[0]=1;
            for(int j=0;j<b-1;j++){
                for(int k=j+1;k<b;k++)
                    if(d[j][k]==1){
                        ans[k]+=ans[j];
                    }
            }
            if(ans[b-1]==m){
                cout<<"POSSIBLE"<<endl;
                for(int j=0;j<b;j++){
                    for(int k=0;k<b;k++){
                        cout<<d[j][k];
                    }
                    cout<<endl;
                }
                bb=true;
                break;
            }
        }
        if(!bb){
            cout<<"IMPOSSIBLE"<<endl;
        }
        cout<<endl;   
    }
    //cout<<fixed<<setprecision(16)<<ans<<endl;
    return 0;
}













    