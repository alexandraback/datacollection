#include<bits/stdc++.h>
using namespace std;

int n,a;
map<int,int> mp;

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    mp.clear();
    cin>>n;
    for(int i=0;i<n*2-1;i++){
      for(int j=0;j<n;j++){
        cin>>a;
        mp[a]++;
      }
    }
    cout<<"Case #"<<tc<<":";
    vector<int> ans;
    map<int,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
      if(it->second%2==1){
        ans.push_back(it->first);
      }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
      cout<<' '<<ans[i];
    }
    cout<<endl;
  }
  return 0;
}
