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
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#define ull unsigned long long
#define mp make_pair
#define ld long double
using namespace std;
long long int e,r,n,max1;
long long int v[10000000];
void doit(long long int pos,long long int en,long long int gain)
{
                   if(pos==n)
                   {
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


