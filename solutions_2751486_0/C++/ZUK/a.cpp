#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

string str;
int n;

bool isA(char c){
  return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

typedef pair<int,int> P;

set<P> s;
int ans;

int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    int a = 0;
    cin >> str >> n;
    s.clear();
    ans = 0;
    for(int i=0;i<str.size()-n+1;i++){
      bool f = false;
      for(int j=0;j<n;j++){
        if(isA(str[i+j])){
            f = true;
            break;
        }
      }
      if(!f){
        ans += (i - a + 1) * (max(0,(int)str.size() - (i + n)) + 1);
        a = i+1;
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
