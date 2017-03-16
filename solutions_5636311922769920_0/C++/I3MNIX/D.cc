#include <bits/stdc++.h>

using namespace std;

void solve(){
  int K, C, S; cin >> K >> C >> S;
  if (K == S){
    for (int i = 1; i <= K; i++)
      cout << ' ' << i;
    cout << endl;
    return;
  }
}

int main(){
  int tc; cin >> tc;
  for (int cs = 1; cs <= tc; cs++){
    cout << "Case #" << cs << ":";
    solve();
  }

  return 0;
}
