#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

typedef long long lli;

string str;
int n;

bool isA(char c){
  return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

typedef pair<int,int> P;

lli ans;

int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    int a = 0;
    cin >> str >> n;
    ans = 0;
    for(int i=0;i<str.size();i++){
      int jj;
      for(int j=i;j<str.size();j++){
        jj = j;
        if(isA(str[j])){
          i = j;
          break;
        } else if(j - i + 1 >= n){
          ans += (lli)(j-n+1 - a + 1) * (lli)(str.size() - (j+1) + 1);
          //if((j-n+1 - a + 1) < 0) cout << 0 << ' ' << j << ' ' << n << ' ' << a << endl;
          a = j - n + 2;
          // cout << j << endl;
        }
      }
      if(jj == str.size()-1) break;
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
