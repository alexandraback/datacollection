#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime> 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;

struct attacks{
  int west;
  int east;
  int s;
};
map<int,vector<attacks> > m;

int wall[600];

int main() 
{
  int T,N;
  cin >> T;
  for(int i=1;i<=T;i++){   
    m.clear();
    cin >> N;
    for(int k=0;k<N;k++){
    int d,n,w,e,s,dd,dp,ds;
    cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
    for(int j=0;j<n;j++){
      attacks a;
      a.west=w;
      a.east=e;
      a.s=s;
      m[d].push_back(a);
      d+=dd;
      w+=dp;
      e+=dp;
      s+=ds;
    }
    }
    int count=0;
    for(int la=0;la<600;la++) wall[la]=0;
    for(auto it=m.begin();it!=m.end();it++){
      
      for(auto it1=(*it).second.begin();it1!=(*it).second.end();it1++){
        bool suc=false;
        for(int x=it1->west;x<it1->east;x++){
          if(wall[300+x]<it1->s){
            suc=true;
            // wall[300+x]=it1->s;
          }
        }
        if(suc) count++;
      }
      for(auto it1=(*it).second.begin();it1!=(*it).second.end();it1++){
        for(int x=it1->west;x<it1->east;x++){
          if(wall[300+x]<it1->s){
            wall[300+x]=it1->s;
          }
        }
      }
    }
    cout << "Case #" << i << ": " << count <<  endl;
  }

}
