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
map<char,I> mp;
vector<int> ans;
char s[2005];
I main()
{
    char path[100],outpath[100];
    cin>>path>>outpath;
    FILE *in=fopen(path,"r");
    FILE *ou=fopen(outpath,"a");
    I t;
    fscanf(in,"%d",&t);
    w(t)
    {
        t--;
        fscanf(in,"%s",&s);
            I n=0;
        f(i,0,2005)
        {
            n++;
            if(s[i]>=65 && s[i]<=90)
                mp[s[i]]++;
            else break;
        }
        while(true)
        {
            bool check=false;
            f(i,0,26)
            {
                if(mp[(char)(65+i)]!=0){check=true;break;}
            }
            if(!check)break;
            if(mp['Z']>0)
            {
                mp['Z']--;
                mp['E']--;
                mp['R']--;
                mp['O']--;
                ans.push_back(0);
            }
            else if(mp['W']>0)
            {
                mp['T']--;
                mp['W']--;
                mp['O']--;
                ans.push_back(2);
            }
            else if(mp['U']>0)
            {
                mp['F']--;
                mp['U']--;
                mp['O']--;
                mp['R']--;
                ans.push_back(4);
            }
           else if(mp['X']>0)
            {
                mp['S']--;
                mp['I']--;
                mp['X']--;
                ans.push_back(6);
            }
           else if(mp['G']>0)
            {
                mp['T']--;
                mp['E']--;
                mp['I']--;
                mp['G']--;
                mp['H']--;
                ans.push_back(8);
            }
         else if(mp['O']>0)
            {
                mp['O']--;
                mp['N']--;
                mp['E']--;
                ans.push_back(1);
            }
       else if(mp['R']>0)
            {
                mp['T']--;
                mp['H']--;
                mp['R']--;
                mp['E']-=2;
                ans.push_back(3);
            }
       else if(mp['F']>0)
            {
                mp['F']--;
                mp['E']--;
                mp['I']--;
                mp['V']--;
                ans.push_back(5);
            }
      else if(mp['V']>0)
            {
                mp['S']--;
                mp['E']--;
                mp['V']--;
                mp['E']--;
                mp['N']--;
                ans.push_back(7);
            }
       else if(mp['N']>1)
            {
                mp['N']-=2;
                mp['I']--;
                mp['E']--;
                ans.push_back(9);
            }
        }
        fprintf(ou,"Case #%d: ",ti);
        sort(ans.begin(),ans.end());
        f(i,0,ans.size())fprintf(ou,"%d",ans[i]);
        fprintf(ou,"\n");
        ans.clear();
        mp.clear();
        ti++;
    }
}
///home/anupam/Desktop

