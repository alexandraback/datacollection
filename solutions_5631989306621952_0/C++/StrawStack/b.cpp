#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void pv(vector<int> v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

int main(){

  int T;
  cin >> T;
  for(int t=1; t<=T; t++){

    string s;
    cin >> s;
    vector<char> v(s.begin(), s.end());
    vector<char> nv;

    nv.push_back( v[0] );
    for(int i=1; i<v.size(); i++){
      if( static_cast<int>(v[i]) >= static_cast<int>(nv[0]) ){
        nv.insert( nv.begin(), v[i] );

      }else{
        nv.push_back( v[i] );

      }
    }
    string ans(nv.begin(), nv.end());
    cout << "Case #" << t << ": " << ans << endl;
  }


  return 0;
}
/*
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE

*/
