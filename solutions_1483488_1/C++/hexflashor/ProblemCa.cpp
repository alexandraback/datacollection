#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>

#define INF (1<<30)
using namespace std;
typedef long long LL;

int flag[2000000+100];

string toString(int n)
{
       stringstream ss;
       ss<<n;
       return ss.str();
}

int toInt(string s)
{
       stringstream ss(s);
       int n;
       ss>>n;
       return n;
}

int main()
{
      freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
      int T,A,B,ans,len,x, pos;
      char ch;
      string temp1, temp2;
      cin>>T; 
      for(int t=1;t<=T;t++)
      {
              memset(flag, 0, sizeof(flag));
              cin>>A>>B;
              ans=0;
              temp1=toString(B);
              len=temp1.length();
              ch=temp1[0];
              
              for(int n=A; n<=B;n++)
              {
                      temp1=toString(n);
                      pos=len-1;
                      while(1)
                      {
                              while(pos>0 && (temp1[pos]<temp1[0] || temp1[pos]>ch)) pos--;
                              if(pos==0) break;
                              temp2=temp1.substr(pos,len-pos)+ temp1.substr(0,pos); pos--;
                              int m=toInt(temp2);
                              if(m<=B && flag[m]==n) break;
                              if(m>n && m<=B) 
                              {
                                     flag[m]=n;
                                     ans++;
                              }
                      }
              }
              cout<<"Case #"<<t<<": "<<ans<<endl;
      }
      //system("pause");
      return 0;
}
