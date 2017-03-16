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
    int cas=1;
   int te;
   in>>te;
   while(te--)
   {
              int x,y;
              in>>x>>y;
              string s="";
              if(x>0) 
              {s="E";
              f(i,0,x-1)
              {
                        s=s+"WE";
              }
              }
              else
              { 
                  if(x!=0) s="W";
              x=x*(-1);
              f(i,0,x-1)
              {
                        s=s+"EW";
              }
              
              }
              string q="";
              if(y>0)
              {
                     f(i,0,y)
                     {
                             q=q+"SN";
                     }
               }
               else
               {
                   y=y*(-1);
                   f(i,0,y)
                     {
                             q=q+"NS";
                     }
               }
s=s+q;

out<<"Case #"<<cas<<": "<<s<<"\n";
cas++;
   }
return 0;
}
