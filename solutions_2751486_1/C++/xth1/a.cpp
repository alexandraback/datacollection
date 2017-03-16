#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#define ll long long int
using namespace std;

int main() {
  
  int T;
  int i, j, k;
  
  cin>>T;
  map<char,bool> vog;
  
  vog['a'] = true;
  vog['e'] = true;
  vog['i'] = true;
  vog['o'] = true;
  vog['u'] = true;
  
  for (k = 0; k < T; k++) {
    ll sum = 0;
    int n;
    int begin = 0;
    string s;
    
    cin>>s>>n;
    int con = 0;
    bool has = false;
    int last = 0;
    for (i = 0; i < s.size(); i++) {
      if (vog[s[i]]) {
        con = 0;

      }
      else{
          con++;
          if (con >= n) {
            last = i;
            has = true;
          }
      }
      
      if(has)
        sum += (ll)(last + 1 - n) + 1;
    }

    
    cout<<"Case #"<<(k+1)<<": "<<sum<<endl;
    
  }
  return 0;
}
