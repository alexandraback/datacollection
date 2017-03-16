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
using namespace std;


map< pair< int ,int> , int> fil;

int isvowel(char c)
{
    return ((c=='a') or (c=='o') or (c=='e') or (c=='i') or (c=='u'));     
}
int iscal(string t,int x)
{
                 int n=t.size(),ans=0;
                 
                 string tmp;
                 
                 for(int i=0;i<n;i++)
                 {
                                int j=i,cnt=0;
                                  
                                while(j<n and !isvowel(t[j]))
                                {
                                          cnt++;
                                          if(cnt>=x and fil.find(mp(i,j))==fil.end())fil[mp(i,j)]+=1,ans++;
                                          j++;
                                }
                                
                                if(cnt>=x)
                                {
                                          while(j<n)
                                          {
                                                    if(fil.find(mp(i,j))==fil.end())fil[mp(i,j)]+=1,ans++;
                                                    j++;
                                          }
                                          
                                          j=i;
                                
                                }
                 }    
                 //if(ans>0)cout<<t<<" "<<ans<<"\n";
                 return ans;
                 
}
int main()
{
          int t;
          
          cin>>t;
          
          
          for(int tt=1;tt<=t;tt++)
          {
                  string s;
                  
                  int x;
                  
                  cin>>s>>x;
                  
                  fil.clear();
                  
                  vector<string> v;
                  
                  int n=s.size(),res=0;
                  
                  for(int i=0;i<n;i++)
                  {
                          string t;
                  
                          for(int j=i;j<n;j++)
                          {
                                  t+=s[j];
                                  //cout<<t<<" ";
                                  res+=iscal(t,x);
                                  
                          }
                  }
                  
                  cout<<"Case #"<<tt<<": "<<res<<"\n";
                          
          }         
          scanf("\n");
          return 0;    
}
