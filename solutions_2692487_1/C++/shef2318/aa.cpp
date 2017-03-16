#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <iomanip>

#define X first
#define Y second
#define ll long long

using namespace std;

ll mas[1010];
void solve(int nt)
{
    
     ll n, a;
     cin>>a>>n;
      ll ans=n;
     for (int i=1; i<=n; i++)
         cin>>mas[i];
     sort(mas+1, mas+n+1);
     ll q=0;
     for (int i=1; i<=n; i++)
     {
         if ( mas[i]<a )
            a+=mas[i];
         else
         {
             ans=min(ans, q+n-i+1);   
             if (a<=1)
             {
                q=n;      
                break; 
             }
             while ( mas[i]>=a )
                   a+=a-1, q++;
             a+=mas[i];
         } 
     }
     ans=min(ans, q);
     cout<<"Case #"<<nt<<": "<<ans<<endl;
}
int main ()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
        solve(i);
    return 0;    
}
