#include <iostream>
#include <string>
using namespace std;
int mp[26]={24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};
int main(){
  int n=0;
  string txt;
  getline(cin,txt);
  for(int i=0;i<txt.size();i++){
    n*=10;
    n+=txt[i]-'0';
  }
  for(int i=0;i<n;i++){
    string txt;
    getline(cin,txt);
    for(int j=0;j<txt.size();j++){
      if(txt[j]!=' ') txt[j]='a'+mp[(txt[j]-'a')];
    }
    cout<<"Case #"<<i+1<<": "<<txt<<"\n";
  }
  return 0;
}
