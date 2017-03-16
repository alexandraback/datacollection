#include<iostream>

using namespace std;

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int x, r, c; cin>>x>>r>>c;
    if (r>c){
      int d=c;
      c=r;
      r=d;
    }
    string s1="RICHARD\n";
    string s2="GABRIEL\n";
    cout<<"Case #"<<tc<<": ";
    if (x>6 || x>c || (r*c)%x!=0){
      cout<<s1;
      continue;
    }
    if (x<=r || r>3){
      cout<<s2;
      continue;
    }
    if (r==1){
      if (x==2)
	cout<<s2;
      else
	cout<<s1;
      continue;
    }
    if (r==2){
      if (x>3)
	cout<<s1;
      else
	cout<<s2;
      continue;
    }
    if (x==4)
      cout<<s2;
    if (x==5){
      if (c==5)
	cout<<s1;
      else
	cout<<s2;
    }
    if (x==6)
      cout<<s1;
  }
  return 0;
}
