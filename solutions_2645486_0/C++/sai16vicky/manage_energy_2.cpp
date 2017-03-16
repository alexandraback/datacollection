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


int e,r,n,max1;
int v[100];

int dp[11][11];

void doit(int pos,int en,int gain)
{
                   if(pos==n)
                   {
                             
                                   //cout<<en<<"\n";
                             max1=max(max1,gain);
                             return ;          
                   }
                   
                   
                   for(int i=0;i<=en;i++)
                   {
                                         if((en-i+r)<=e)
                                         doit(pos+1,(en-i)+r,gain+v[pos]*i);        
                                         else
                                         doit(pos+1,e,gain+v[pos]*i);
                   }
                   
                   return ;
}
int main()
{
                 
                    int t;
                    
                    cin>>t;
                    
                    for(int tt=1;tt<=t;tt++)
                    {
                            
                            cin>>e>>r>>n;
                    
                            for(int i=0;i<n;i++)
                                    cin>>v[i];
                            

                            max1=0;
                            
                            doit(0,e,0);  

                            
                            cout<<"Case #"<<tt<<": "<<max1<<"\n";
                    }
                    scanf("\n");
                    return 0;    
}

