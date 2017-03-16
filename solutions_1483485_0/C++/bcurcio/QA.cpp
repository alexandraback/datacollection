#include <iostream>
#include <cstdio>

using namespace std;
const char* map="yhesocvxduiglbkrztnwjpfmaq";

int main(){
  freopen("tin","r",stdin);
  freopen("ton","w",stdout);
  int N,i,j;
  string s;
  cin>>N; cin.ignore();
  for(i=1;i<=N;i++){
    getline(cin,s);
    for(j=0;j<s.size();j++) if(s[j]!=' ') s[j]=map[s[j]-'a'];
    cout << "Case #"<<i<<": "<<s<< endl;
  }
}
