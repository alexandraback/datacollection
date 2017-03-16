#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    deque<char> ans;
    cin>>s;
    ans.push_front(s[0]);
    for(int i=1;i<(int)s.size();i++){
      if(ans.front()<=s[i]){
        ans.push_front(s[i]);
      }else{
        ans.push_back(s[i]);
      }
    }
    cout<<"Case #"<<tc<<": ";
    while(!ans.empty()){
      cout<<ans.front();
      ans.pop_front();
    }
    cout<<endl;
  }
  return 0;
}
