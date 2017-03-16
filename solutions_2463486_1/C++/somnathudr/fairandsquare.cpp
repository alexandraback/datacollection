#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
 
//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>
 
//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>
 
 
//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#define ll long long
#define ull unsigned long long
using namespace std;
 
 
int ispalin(ll x)
{
    char buf[100];
    sprintf(buf,"%lld",x);
    
    int n=strlen(buf);
    
    for(int i=0;i<n;i++)
            if(buf[i]!=buf[n-i-1])return 0;
           
    return 1;    
}
 
int main()
{
          vector<ll> res;
          
          for(ll i=1;i<=10000000;i++)
          if(ispalin(i) and ispalin(i*i))
          {
                        res.push_back(i*i);                  
                        //cout<<i<<" "<<i*i<<"\n";     
          }
          
          int t;
          cin>>t;
          
          for(int tt=1;tt<=t;tt++)
          {
                        ll a,b;
                        cin>>a>>b;
                        
                        int ans=0;
                        
                        for(int i=0;i<(int)res.size();i++)
                                if(res[i]>=a and res[i]<=b)ans++;
                               
                        cout<<"Case #"<<tt<<": "<<ans<<"\n";          
          }
          
          scanf("\n");
          return 0;    
}
