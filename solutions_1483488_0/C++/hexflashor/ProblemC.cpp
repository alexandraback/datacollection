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
      int T,A,B,ans,len,x;
      set<int> s;
      string temp;
      cin>>T; 
      for(int t=1;t<=T;t++)
      {
              cin>>A>>B;
              ans=0;
              for(int n=A; n<=B;n++)
              {
                      temp=toString(n);
                      len=temp.length();
                      s.clear();
                      for(int i=0;i<len-1;i++) 
                      {
                              temp=temp[len-1] + temp.substr(0,len-1);
                              int m=toInt(temp);
                              if(m>n && m<=B && s.find(m)==s.end()) 
                              {
                                     s.insert(m);
                                     ans++;
                              }
                      }
              }
              cout<<"Case #"<<t<<": "<<ans<<endl;
      }
      //system("pause");
      return 0;
}
