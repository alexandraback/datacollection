#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include <deque>
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
typedef pair<long long int, pair<int,int> > Pli;
typedef pair<int,string> PS;
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
I ti=1;
vector<int> p1,p2;
ll val=1e18,a1=0,a2=0;
void solve(S a,S b,I n,I ind,I ans1,I ans2)
{
    if(ind==n)
    {
        if(abs(ans1-ans2)<val)
        {
            val=abs(ans1-ans2);
            a1=ans1;
            a2=ans2;
        }
        else if(abs(ans1-ans2)==val && a1>ans1)
        {
            a1=ans1;
        }
        else if(abs(ans1-ans2)==val && a2>ans2)
        {
            a2=ans2;
        }
        return;
    }
    if(a[ind]=='?' && b[ind]=='?')
    {
        f(i,0,10)
        {
          f(j,0,10) 
              solve(a,b,n,ind+1,ans1*10+i,ans2*10+j);
        }
    }
    else if(a[ind]=='?' && b[ind]!='?')
    {
        f(i,0,10)
        {
            solve(a,b,n,ind+1,ans1*10+i,ans2*10+(b[ind]-48));
        }
    }
    else if(a[ind]!='?' && b[ind]=='?')
    {
        f(i,0,10)
        {
            solve(a,b,n,ind+1,ans1*10+(a[ind]-48),ans2*10+i);
        }
    }
    else solve(a,b,n,ind+1,ans1*10+a[ind]-48,ans2*10+b[ind]-48);
}
void printg(I x,S a)
{
    I n=0,temp=x;
    w(temp)
    {
        temp/=10;
        n++;
    }
    while(n<a.length())
    {
        cout<<0;
        n++;
    } 
    if(x!=0)
    cout<<x;
}
I main()
{
    I t;
    cin>>t;
    w(t)
    {
        t--;
        S a,b;
        cin>>a>>b;
        solve(a,b,a.length(),0,0,0);
        val=1e18;
        cout<<"Case #"<<ti<<": ";
        printg(a1,a);
        cout<<" ";
        printg(a2,a);
        cout<<endl;
        a1=0;
        a2=0;
        ti++;
    }
}
///home/anupam/Desktop

