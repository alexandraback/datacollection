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
      int T,N,S,p,x,ans,maxm;
      cin>>T;
      for(int t=1;t<=T;t++)
      {
              cin>>N>>S>>p;
              ans=0;
              vector<int> v;
              for(int i=0;i<N;i++) {
                      cin>>x;
                      v.push_back(x);
              }
              sort(v.begin(), v.end(), greater<int>());
              
              for(int i=0;i<N;i++) 
              {
                      x=v[i];
                      maxm=-1;
                      if(x%3 == 0) maxm=max(maxm,x/3);
                      if((x-1)>=0 && (x-1)%3 == 0) maxm=max(maxm,(x-1)/3 + 1);
                      if((x-2)>=0 && (x-2)%3 == 0) maxm=max(maxm,(x-2)/3 + 1);
                      
                      if(maxm<p && S>0)
                      {
                                if((x-2)>=0 && (x-2)%3 == 0) maxm=max(maxm,(x-2)/3 + 2);
                                if((x-3)>=0 && (x-3)%3 == 0) maxm=max(maxm,(x-3)/3 + 2);
                                if((x-4)>=0 && (x-4)%3 == 0) maxm=max(maxm,(x-4)/3 + 2);
                                S--;
                      }
                      
                      if(maxm>=p) ans++;
              }
             cout<<"Case #"<<t<<": "<<ans<<endl;
      }
      //system("pause");
      return 0;
}
