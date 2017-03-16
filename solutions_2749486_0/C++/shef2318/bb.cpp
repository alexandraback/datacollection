#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define ll long long

using namespace std;

string ans;
void solve(int test)
{
     int x, y, xt=0, yt=0;
     cin>>x>>y;
     ans="";
     int it=1;
     if ( x<0 )
     {
        while ( xt!=x )
        {
              ans+="E";
              xt+=it;
              it++;
              ans+="W";
              xt-=it;
              it++;      
        }
     }
     if ( x>0 )
     {
          while ( xt!=x )
          {
              ans+="W";
              xt-=it;
              it++;
              ans+="E";
              xt+=it;
              it++;      
          }
     }
     
     if ( y<0 )
     {
        while ( yt!=y )
        {
              ans+="N";
              yt+=it;
              it++;
              ans+="S";
              yt-=it;
              it++;      
        }
     }
     if ( y>0 )
     {
          while ( yt!=y )
          {
              ans+="S";
              yt-=it;
              it++;
              ans+="N";
              yt+=it;
              it++;      
          }
     }
     printf("Case #%d: ", test);
     cout<<ans<<endl;
}
int main ()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
        solve(i);   
    cin>>t;
    return 0;
}
