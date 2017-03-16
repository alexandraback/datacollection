#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll             long long
#define ull            unsigned long long
#define all(x)         x.begin(),x.end()
#define vi             vector<int>
#define vvi            vector<vector<int> >
#define gcd            ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
#define INF            2147483647
#define LIMIT          1000
#define mod            1000000007
#define pi             pair<int,int>
#define mp             make_pair
#define pb(v)          v.push_back
#define sz(x)          x.size()

string tostr(ll x)
{ stringstream ss; ss << x; return ss.str(); }
ll toint(string &s)   
{ stringstream ss; ss << s; long long x; ss >> x; return x; }


int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
string dir="NSWE";
int main()

{
      freopen("in.in","r",stdin);
      freopen("c.out","w",stdout);
      map <pair<int,int>,int >h;
        map <pair<int,int>,string >hh;
      h[mp(0,0)]=1; 
     
      queue<pair<pair<int,int>,string > > q;
      q.push(mp(mp(0,0),""));
      
      while(!q.empty())
      {
                 pair<int,int> u=q.front().first;
                 //cout<<u.first<<" "<<u.second<<" ";
                 string par=q.front().second;
                 //cout<<par<<endl;
                 q.pop();
                 int size=par.length()+1;
                 for(int i=0;i<4;i++)
                 {
                           int x=u.first+dx[i]*size;
                         
                           int y=u.second+dy[i]*size;
                          
                           if(abs(x)>100) continue;
                           if(abs(y)>100) continue;
                           if(h.count(mp(x,y))) continue;
                          
                           h[mp(x,y)]=1;
                           hh[mp(x,y)]=par+dir[i];
                           q.push(mp(mp(x,y),par+dir[i]));
                 }
      }    
      int t;
      cin>>t;
      for(int j=1;j<=t;j++)
      {
          int x,y;
          cin>>x>>y;
           cout<<"Case #"<<j<<": "<<hh[mp(x,y)]<<endl;
      }
      return 0;
}
