#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
   int te;
   in>>te;
   char t[5]={'a','e','i','o','u'};
   int cas=1;
   while(te--)
   {
              int ans=0,p;
              
              char ch[100];
              in>>ch;
              in>>p;
              int x=strlen(ch);
              f(i,0,x)
              f(j,0,x)
              {
                      int ok=0;
                      f(k,i,j+1)
                      {
                                ok++;
                                f(w,0,5)
                                {
                                        if(ch[k]==t[w]) ok=0;
                                        
                                }
                                if(ok==p) 
                                {
                                          ans++;
                                          break;                                          
                                }
                             //   cout<<ch[k];             
                      }
                      //cout<<"\n";
              }
              out<<"Case #"<<cas<<": "<<ans<<"\n";

cas++;


   }
  
   out.close();
return 0;
}
