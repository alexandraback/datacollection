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
I ti=1;
I main()
{
    char path[100],out_[100];
    cin>>path>>out_;
    FILE *in,*ou;
    in=fopen(path,"r");
    ou=fopen(out_,"a");
    I t;
    fscanf(in,"%d",&t);
    set<ll> temp,st;
    std::set<ll>::iterator it,g;
    w(t)
    {
        fprintf(ou,"Case #%d: ",ti);
        t--;
        I k,c,s;
        fscanf(in,"%d",&k);
        fscanf(in,"%d",&c);
        fscanf(in,"%d",&s);
        if(k==1)fprintf(ou,"1\n");
        else
        {
            f(i,1,k+1)
                st.insert(i);
            f(i,2,c+1)
            {
                I ok=i;
                for(it=st.begin();it!=st.end();++it)
                {
                    ll p=(*it-1)*k+ok;
                    ll u=*it;
                    if(*it%k==0)p=u*k;
                    ok++;
                    temp.insert(p);
                }
                st=temp;
                temp.clear();
            }
            I hm=0,pls=0;
            for(g=st.begin();g!=st.end();++g)
            {
                if(hm>0){hm--;continue;}
                pls++;
                hm=c-1;
            }
            if(pls>s)fprintf(ou,"IMPOSSIBLE\n");
            else
            {
                hm=0;
                for(g=st.begin();g!=st.end();++g)
                {
                    if(hm>0){hm--;continue;}
                    fprintf(ou,"%lld ",*g);
                    hm=c-1;
                }
                fprintf(ou,"\n");
            }
        }
        ti++;
        st.clear();
}
}

