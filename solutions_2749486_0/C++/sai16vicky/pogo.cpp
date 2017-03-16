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


int dp[50][50];

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

map< pair<int,int> ,int > f;

map<char,int> c;

int main()
{
          
          c[0]='W';
          c[1]='S';
          c[2]='N';
          c[3]='E';
                    
          int t;
          
          cin>>t;
          
          for(int tt=1;tt<=t;tt++)
          {
                                  int x,y;
                                  cin>>x>>y;
                                  
                                  f.clear();
                                  
                                  
                                  queue<int> q;
                                  queue< vector<int> > q2;
                                  
                                  vector<int> v;
                                  
                                  q.push(0);
                                  q.push(0);
                                  q.push(1);
                                  q2.push(v);
                                  
                                  while(!q.empty())
                                  {
                                                   int tx=q.front();q.pop();
                                                   int ty=q.front();q.pop();
                                                   int jmp=q.front();q.pop();
                                                   
                                                   //cout<<tx<<" "<<ty<<"\n";
                                                   vector<int> res=q2.front();q2.pop();
                                                   
          
                                                   if(tx==x and ty==y and (int)res.size()<=500)
                                                   {
                                                                cout<<"Case #"<<tt<<": ";
                                                                for(int i=0;i<(int)res.size();i++)
                                                                        cout<<(char)c[res[i]];
                                                                
                                                                cout<<"\n";
                                                                break;        
                                                   }                 
                                                   
                                                   for(int i=0;i<4;i++)
                                                           if(/*abs(tx+dx[i]*jmp)<=100 and abs(ty+dy[i]*jmp)<=100 and*/ f.find(make_pair(tx+dx[i]*jmp,ty+dy[i]*jmp))==f.end())
                                                           {
                                                                              f[make_pair(tx+dx[i]*jmp,ty+dy[i]*jmp)]+=1;
                                                                              vector<int> tv=res;
                                                                              q.push(tx+dx[i]*jmp);
                                                                              q.push(ty+dy[i]*jmp);
                                                                              q.push(jmp+1);   
                                                                              tv.push_back(i);                                                    
                                                                              q2.push(tv);
                                                           }      
                                                   
                                  }        
          }
          
          
          return 0;    
}
