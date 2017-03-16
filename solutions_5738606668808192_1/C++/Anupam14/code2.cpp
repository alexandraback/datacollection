#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<string>
#include <sstream>
#include<set>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define ff(i,a,b,c) for(int i=a;i<b;i+=c)
#define w(n) while(n>0)
#define vi vector<int>
#define vll vector<long long int>
typedef pair<pair<int,int> ,int> PII;
typedef pair<long long int,long long int> PI;
typedef long long int ll;
typedef int I;
typedef string S;
ll mod_pow(ll a,ll n,ll b){ll res = 1;while(n){if(n&1) {res = (res*a)%b;}a = (a*a)%b;n >>= 1;}return res%b;}
ll mod_div(ll a,ll b,ll md){ll ans = (a*mod_pow(b,md-2,md))%md; return ans;}
ll mul(ll a,ll b,ll md){ return (ll)(a*b)%md;}
ll gcd(ll n,ll m){if(m<=n && n%m==0)return m;if(n<m)return gcd(m,n);else return gcd(m,n%m);}
ll add(ll a,ll b,ll md){a=((a%md)+(b%md))%md;return a;}
ll sub(ll a,ll b,ll md){return add(a,md-b,md);}
ll bC(int n,int r){ll ans=1;if(r>n-r)r=n-r;f(i,1,r+1)ans=(ans*(n-i+1))/(i);return ans;}
bool solve(ll x,I n)
{
    vll G;
    f(i,2,11)
    {
        bool check=false;
        f(j,2,1000)
            {
               ll ans=0;
               f(k,0,n)
               {
                   if(x&(1<<k))
                        ans=add(ans,mod_pow(i,k,j),j);            
               }
               if(ans==0)
               {
                   check=true;
                   G.push_back(j);
                   break;
               }
            }
        if(!check)return false;
    }
    fr(i,n-1,0)
    {
        if(x&(1<<i))cout<<1;
        else cout<<0;
    }
    cout<<" ";
    f(i,0,G.size())cout<<G[i]<<" ";
    cout<<endl;
    return true;
}
I main()
{
    I t,n,k;
    cin>>t>>n>>k;
    cout<<"Case #"<<1<<":"<<endl;
    f(i,pow(2,n-1),pow(2,n))
    {
        if((i&(1<<(n-1)))>0 && (i&(1<<0))>0)
            if(solve(i,n))k--;
        if(k==0)break;
    } 
}

