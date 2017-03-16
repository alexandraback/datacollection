#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;cin>>T;
  for(int t=0;t<T;t++){
    vector<int>v; string s; cin>>s;
    map<char,int>mp;
    for(auto i:s)mp[i]++;
    vector<string>strings={"ZERO", "TWO", "EIGHT", "SIX", "SEVEN", "FIVE", "FOUR", "THREE", "NINE", "ONE"};
    for(int i=0;i<strings.size();i++){
      int mn=10000000;
      for(auto j:strings[i]){
        if((j=='E'&&(strings[i]=="THREE"||strings[i]=="SEVEN"))
          ||(j=='N'&&strings[i]=="NINE"))
          mn=min(mn,mp[j]/2);
        else mn=min(mn,mp[j]);
      }
      for(int j=0;j<mn;j++){
        if(strings[i]=="ZERO") v.push_back(0);
        if(strings[i]=="ONE") v.push_back(1);
        if(strings[i]=="TWO") v.push_back(2);
        if(strings[i]=="THREE") v.push_back(3);
        if(strings[i]=="FOUR") v.push_back(4);
        if(strings[i]=="FIVE") v.push_back(5);
        if(strings[i]=="SIX") v.push_back(6);
        if(strings[i]=="SEVEN") v.push_back(7);
        if(strings[i]=="EIGHT") v.push_back(8);
        if(strings[i]=="NINE") v.push_back(9);
      }
      for(auto j:strings[i]){
        mp[j]-=mn;
      }
    }
    sort(v.begin(),v.end());
    cout<<"Case #"<<t+1<<": ";
    for(auto i:v)cout<<i;
    cout<<endl;
  }
}