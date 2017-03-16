#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  for(int ts=1; ts<=T; ts++) {
    int N;
    cin >> N;
    vector<int> seen(3000);
    for(int i=0; i<2*N-1; i++) {
      for(int j=0; j<N; j++) {
        int x; cin >> x;
        seen[x]=1-seen[x];
      }
    }
    cout << "Case #" << ts << ":";
    for(int i=0; i<3000; i++) if(seen[i]) cout << " " << i;
    cout << endl;
  }
}
