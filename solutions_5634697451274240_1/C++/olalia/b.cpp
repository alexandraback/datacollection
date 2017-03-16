#include<iostream>
#include<vector>
#include<set>
#include<algorithm>




using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    string s; cin>>s;
    int a=(s[s.size()-1]=='-');
    for (int i=0; i+1<s.size(); ++i)
      a+=(s[i]!=s[i+1]);



    cout<<"Case #"<<tc<<": "<<a<<endl;

  }
  return 0;
}
