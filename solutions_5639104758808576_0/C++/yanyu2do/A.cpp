#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main(){
  int T;
  cin >> T;

  for(int x = 1; x <= T; x++){
    int smax;
    cin >> smax;
    string s;
    cin >> s;

    int cnt = 0, ans = 0;
    for(int i = 0; i < s.size(); i++){
      int ci = s[i] - '0';
      if(i <= cnt){
        cnt += ci;
      }else{
        ans += i- cnt;
        cnt = i + ci;
      }
    }
    cout << "Case #" << x << ": " << ans << endl;
  }
}

