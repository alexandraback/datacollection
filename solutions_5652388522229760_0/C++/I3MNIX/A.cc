#include <bits/stdc++.h>

using namespace std;

string solve(){
  int n;  cin >> n;
  int ori = n;
  if (n == 0) return "INSOMNIA";
  vector<int> seen(10, 0);
  int tot = 0;
  while (1){
    string str = to_string(n);
    for (char c : str){
      if (!seen[(int) c - '0']) {
	tot++;
	seen[(int) c - '0'] = 1;
      }
    }
    if (tot == 10) return to_string(n);
    n += ori;
  }
}

int main(){
  int tc; cin >> tc;
  for (int cs = 1; cs <= tc; cs++){
    cout << "Case #" << cs << ": ";
    cout << solve() << endl;
  }

  return 0;
}
