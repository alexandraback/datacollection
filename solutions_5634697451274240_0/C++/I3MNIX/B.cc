#include <bits/stdc++.h>

using namespace std;

int solve(){
  string str; cin >> str;
  int n = (int) str.size();
  int res = 0;
  for (int i = n-1; i >= 0; i--){
    if (res & 1){
      if (str[i] == '+'){
	res++;
      }
    } else {
      if (str[i] == '-'){
	res++;
      }
    }
  }
  return res;
}

int main(){
  int tc; cin >> tc;
  for (int cs = 1; cs <= tc; cs++){
    cout << "Case #" << cs << ": ";
    cout << solve() << endl;
  }

  return 0;
}
