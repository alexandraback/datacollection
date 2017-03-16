#include <iostream>
#include <cstring>
using namespace std;

char s[1001];
bool b[1001];

int main() {

  int t, n, last;
  cin>>t;
  for (int cas=1; cas<=t; cas++) {
    cout<<"Case #"<<cas<<": ";
    cin>>s;
    n=strlen(s); last=n-1;
    for(int i=0; i<n; i++) b[i]=true;

    for(char c='Z'; c>='A'; c--) {
      for(int i=last; i>=0; i--) {
        if(s[i]==c) {
          b[i]=false;
          cout<<c;
          last=i-1;
        }
      }
    }

    for(int i=0; i<n; i++)
      if(b[i]==true) cout<<s[i];
    cout<<endl;

  }

  return 0;
}
