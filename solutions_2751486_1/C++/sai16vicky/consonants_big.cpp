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

int vis[1000010];

int isvowel(char c)
{
    return ((c=='a') or (c=='o') or (c=='e') or (c=='i') or (c=='u'));     
}

int main()
{
          int t;
          
          cin>>t;
          
          for(int tt=1;tt<=t;tt++)
          {
                                  char s[1000010];
                                  
                                  int x;
                                  
                                  scanf("%s",s);
                                  scanf("%d",&x);
                                  
                                  int n=strlen(s);
                                  
                                  ll res=0,cnt=0,st=(int)1e7;
                                  
                                  int scan=0;
                                  
                                  memset(vis,0,sizeof vis);
                                  
                                  for(int i=0;i<n;i++)
                                  {
                                          if(!isvowel(s[i]))
                                          {
                                                     st=min(st,(ll)i);
                                                     
                                                     if(cnt+1==x)
                                                     {
                                                                //cout<<st<<" "<<i<<" "<<res<<"\n";
                                                     
                                                     if(scan==0)
                                                     res+=(n-(i+1)+1)*(st+1);
                                                     else 
                                                     res+=(n-(i+1)+1)*st;
                                                     
                                                     scan++;
                                                     //res-=1;
                                                     vis[st]=1;
                                                     vis[i]=1;
                                                     cnt=x-1;
                                                     }
                                                     else cnt++;
                                          }        
                                          else cnt=0,st=(int)1e7;
                                  }
                                  
          
                                  
                                  cout<<"Case #"<<tt<<": "<<res<<"\n";
          }
          scanf("\n");
          return 0;
}
