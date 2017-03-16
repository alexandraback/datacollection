#include<iostream>

using namespace std;

int main(){
  int T; 
  cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int n; cin>>n;
    string s; cin>>s;
    int c=0, d=0;
    for (int i=0; i<=n; ++i){
      if (c<i){
	d+=i-c;
	c=i;
      }
      c+=s[i]-'0';
    }
    cout<<"Case #"<<tc<<": "<<d<<endl;
  }
  return 0;
}
