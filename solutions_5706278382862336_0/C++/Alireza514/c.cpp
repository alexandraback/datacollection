                /* In the Name of God */
#include <iostream>
#include <set>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include<cstdio>
#define lch(r) (2*(r)+1)
#define rch(r) (2*(r)+2) 
#define inf (1<<30)
#define F first
#define S second
#define mod 1000000007
using namespace std;
typedef pair<int ,int > pii;
typedef long long ll;
typedef long double ld;
const int  MAXN = 100000+10;
ifstream fin("in.in");
ofstream fout("out.out");
ll bmm( ll a, ll b)
{
        if(b==0)
        return a;
        return bmm(b , a%b);
}
ll check(ll x)
{
        while(x%2==0)
        x/=2;
       if(x==1)
        return 1;
        return 0;
}
int  main()
{
   ios_base::sync_with_stdio(false);
             int t,tt=1;;
             fin>>t;
             while(t)
             {
                        string s;
                        fin>>s;
                      ll p=0, tav[2];
                      tav[1]=tav[0]=1;
                       ll a =0, b=0;
                        for(int i=s.size()-1;i>=0;i--)
                        {
                               if(s[i]=='/')
                               {
                               p=1;
                               continue;                            
                               }
                               if(p)
                               {
                                        a+=tav[p]*(s[i]-'0');
                                        tav[p]*=10;
                               }
                               else
                               {
                                                 b+=tav[p]*(s[i]-'0');
                                                 tav[p]*=10;
                               
                               }
                        }
                        
                  ll k=bmm(a,b);
                  a/=k;
                  b/=k;
                  fout<<"Case #"<<tt<<": ";
                        if(check(b)==0)
                         fout<<"impossible"<<endl;
                        else
                        {
                                ll ans=1;
                                        while(a*2<b)
                                         {
                                                b/=2;
                                                ans++;
                                         }
                                    fout<<ans<<endl;
                        }    
                        tt++;           
                        t--;
             }              
} 
