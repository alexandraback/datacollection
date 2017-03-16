#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

string s;

string solve(int len){
  string ret;
  if(len == 0) return ret;

  int pos = 0;

  for(int i = 0;i < len;++i){
    if(s[i] >= s[pos]){
      pos = i;
    }
  }

  ret = s[pos] + solve(pos) + s.substr(pos + 1,len - pos - 1);

  return ret;
}

int main(){
  int T;

  cin >> T;
  
  for(int tc = 1;tc <= T;++tc){
    cin >> s;

    cout << "Case #" << tc << ": " << solve(s.size());
    
    cout << "\n";
  }
  
  return 0;
}
