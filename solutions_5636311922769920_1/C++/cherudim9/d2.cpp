#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define Add(l) { if (l<k-1) l++; }

int main(){
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=1; tt<=T; tt++){

    printf("Case #%d: ",tt);
    int k,c,s;
    cin>>k>>c>>s;
    
    if (c*s<k){
      cout<<"IMPOSSIBLE"<<endl;
    }else{
      int l=0;

      vector<long long> ans;
      
      for(int s_trial=0; s_trial < s; s_trial++){
        long long now = l;
        Add(l);

        for(int c_i=0; c_i < c-1; c_i++){
          now = now * k + l;
          Add(l);
        }
        
        ans.push_back(now+1);
      }
      
      sort(ans.begin(),ans.end());      

      for(int i=0; i<ans.size(); i++)
        if (i==0 || ans[i]!=ans[i-1]){
          cout<<ans[i]<<" ";
          /*
          cout<<": ----- ";
          ans[i]--;
          for(int j=0; j<c; j++){
            cout<<ans[i]%k<<", ";
            ans[i]/=k;
          }
          cout<<endl;
          */
        }
      cout<<endl;
    }
  }
  
  return 0;
}
