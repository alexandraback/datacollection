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

int main()
{
      freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
      int testcase,n,t=1,cnt;
      double s[210], a[210], T,x,A;
      bool visited[210];
      cin>>testcase;
      while(testcase--)
      {
                       memset(visited,0,sizeof(visited));
                       cin>>n; cnt=n;
                       T=0;
                       for(int i=0;i<n;i++) 
                       {
                               cin>>s[i];
                               T+=s[i];
                       }
                       A=0;
                       for(int i=0;i<n;i++) 
                       {
                                          a[i]=s[i]/T;
                                          if(a[i]*double(n)>2.0) 
                                          {
                                                                 cnt--;
                                                                 visited[i]=1;
                                          }
                                          else A+=a[i];
                       }

                      //cout<<A<<endl; 
                       printf("Case #%d: ",t++);
                       //double sum=0;
                       for(int i=0;i<n;i++)
                       {
                               if(visited[i]) x=0;
                               else
                               {
                                   x=(A+1.0 - double(cnt) * a[i])/double(cnt);
                                   x*=100.0;
                               }
                               printf("%.6lf ",x);
                               //sum+=x;
                       }
                       printf("\n");
                       //cout<<sum<<endl;
      }
      //system("pause");
      return 0;
}
