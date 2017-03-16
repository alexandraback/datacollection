#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){
  int aux;
  int T, N;
  string s;
  string resp;

  cin >> T;
  for( int i=0; i<T; i++ ){
    cin >> s;
    cout << "Case #" << i+1 << ": ";

    resp = s[0];
    for( int j=1; j<s.size(); j++ ){
      if( resp[0] > s[j] ){
	resp += s[j];
      }else{
	resp = s[j]+resp;
      }
    }
    cout << resp << endl;
  }
  return 0;
}
