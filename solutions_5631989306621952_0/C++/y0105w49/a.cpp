#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string S;

string solve(string s) {
  if(!s.size()) return s;
  int i=0;
  for(int j=1;j<s.size();j++) if(s[j]>=s[i]) i=j;
  int j=i;
  string pre=solve(s.substr(0,j));
  string post=s.substr(j+1,3000);
  return s[j]+pre+post;
}

int main() {
  cin>>T; for(int zz=1;zz<=T;zz++) {
    cin>>S;
    printf("Case #%d: ",zz); cout<<solve(S)<<endl;
  }
}
