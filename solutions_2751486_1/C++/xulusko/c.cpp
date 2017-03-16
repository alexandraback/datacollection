#include <iostream>
#include <string>
using namespace std;

int T, n;
long long res;
string s;

bool is_consonant(char x){
  if (x == 'a')
    return false;
  if (x == 'e')
    return false;
  if (x == 'i')
    return false;
  if (x == 'o')
    return false;
  if (x == 'u')
    return false;
  return true;
}

int main(){
  cin >> T;
  for (int i = 1; i <= T; i++){
    res = 0;
    cin >> s >> n;
    int cons = 0, last = 0, len = int(s.length());
    for (int j = 0; j < len; j++){
      if(is_consonant(s[j]))
        cons++;
      else 
        cons = 0;
      if(cons >= n){
        res += (long long)(j-n-last+2)*(long long)(len-j);
        last = j-n+2;
      }
    }
    cout << "Case #" << i << ": " << res << endl;
  }
}
