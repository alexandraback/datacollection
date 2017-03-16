#include <iostream>
#include <vector>

using namespace std;

const int maxn = 3000;
const int mid = 1500;

char str[maxn];
string s;

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> s;
    str[mid] = s[0];
    int l = mid-1,r = mid+1;
    for(int i = 1; i < s.size(); ++i){
      if(s[i] >= str[l+1]){ str[l] = s[i]; --l; }
      else{ str[r] = s[i]; ++r; }
    }
    cout << "Case #" << cass << ": ";
    for(int i = l+1; i < r; ++i) cout << str[i];
    cout << '\n';
  }
}