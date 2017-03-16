#include <iostream>
#include <algorithm>

using namespace std;

int calc(){
  int i,ans=0;
  int T,S,P,t;
  cin >> T >> S >> P;
  for(i=0; i<T; i++){
    cin >> t;
    if(t<P)continue;
    if((t+2) / 3 >= P)
      ans++;
    else if(S && ((t+4) / 3 >= P)){
      ans++; S--;
    }
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  for(int i=1; i<=N; i++){
    cout << "Case #" << i << ": " << calc() << endl;
  }
  return 0;
}
