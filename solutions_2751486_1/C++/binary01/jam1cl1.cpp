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
              char ch[1000005];
              in>>ch;
              in>>p;
              int x=strlen(ch);
              int ok=0;
              int prev=0;
              f(i,0,x)
              {
                       ok++;
                                f(w,0,5)
                                {
                                        if(ch[i]==t[w]) ok=0;
                                }
                                if(ok==p)
                                {
                                         int en=(x-i);
                                         int st=(i-p+2)-prev;
                                         ans+=st*en;
                                         prev=i-p+2;
                                         
                                        // cout<<ans<<"\n";
                                         ok--;
                                }        
              }


   out<<"Case #"<<cas<<": "<<ans<<"\n";
   cas++;

   }
   
return 0;
}
