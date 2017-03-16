#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;cin>>T;
  for(int t=0;t<T;t++){
    int n;cin>>n;
    vector<string>v1,v2;
    string s1,s2;
    for(int i=0;i<n;i++)cin>>s1>>s2,v1.push_back(s1),v2.push_back(s2);
    set<string>st1,st2,st3,st4;
      set<string>mustadd1,mustadd2;
    int ans=0;
    for(int i=0;i<n;i++){
      string t1=v1[i];
      string t2=v2[i];
      bool f1=0,f2=0;
      for(int j=0;j<n;j++){
        if(j!=i&&v1[j]==t1) f1=1;
        if(j!=i&&v2[j]==t2) f2=1;
        if(f1&&f2)break;
      }
      if(f1&&f2){
        // cout<<v1[i]<<" "<<v2[i]<<endl;
        // may have been copied
        st1.insert(v1[i]),st2.insert(v2[i]);
        ans++;
      }else{
        st3.insert(v1[i]),st4.insert(v2[i]);
        // original
      }
      for(auto i:st1) if(st3.find(i)==st3.end())mustadd1.insert(i);
      for(auto i:st2) if(st4.find(i)==st4.end())mustadd2.insert(i);
    }
    // for(auto i:mustadd1)cout<<i<<endl;cout<<endl;
    // for(auto i:mustadd2)cout<<i<<endl;cout<<endl;

    ans-=mustadd1.size();
    for(auto i:mustadd1) for(int j=0;j<v1.size();j++) if(v1[j]==i) if(mustadd2.find(v2[j])!=mustadd2.end())mustadd2.erase(v2[j]);
    ans-=mustadd2.size();
    cout<<"Case #"<<t+1<<": "; cout<<ans<<endl;;
  }
}