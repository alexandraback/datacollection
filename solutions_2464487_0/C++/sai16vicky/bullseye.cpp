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
#define mp make_pair
#define ld long double
using namespace std;


int main()
{
          
          int t;
          
          cin>>t;
          
          for(int tt=1;tt<=t;tt++)
          {
                  ll r,t;
                  
                  cin>>r>>t;
                  
                  ll st=0,f=r+1;
                  
                  ll cnt=0;
                  
                  while(1)
                  {
                              st+=(f*f) - (f-1)*(f-1);
                              if(st>t)break;
                              cnt++;
                              f+=2;           
                  }
                  
                  cout<<"Case #"<<tt<<": "<<cnt<<"\n";
                  
                  
          }
          scanf("\n");
          return 0;    
}
