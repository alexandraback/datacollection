#include <iostream>
using namespace std;

#define LIM
#define MOD
#define INF

typedef long long int ll;

ll N;

int setBit(int no, int pos) {
  int ret = (no | (1 << pos));
  return ret;
}


ll getAns(ll no, int coeff, int bitmask) {
  if(coeff > 100) return -1;
  ll cons = no * coeff;
  ll save = cons;
  int digit;
  while(cons > 0) {
    digit = cons % 10;
    bitmask = setBit(bitmask, digit);
    cons /= 10;
  }
  if(bitmask == 0b01111111111) {
    return save;
  }
  else {
    return getAns(no, coeff + 1, bitmask);
  }
}

void work(int index) {
  cin >> N;
  ll ans = getAns(N, 1, 0);
  
  cout << "Case #" << index << ": ";
  if(ans == -1) {
    cout << "INSOMNIA";
  }
  else {
    cout << ans;
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}

// int main() {
//   int i;
//   for(i = 0; i < 1E6 + 3; i++) {
//     int ans = getAns(i, 1, 0);
//     //cout << i << ": " <<  ans << endl;
//     if(ans == -1) cout << i << " Aiyo raama\n";
//   }
// }
