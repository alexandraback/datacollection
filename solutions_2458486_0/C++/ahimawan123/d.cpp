#include <iostream>
#include <exception>
using namespace std;

#define MAXKEY 201
#define MAXCHEST 20

struct KeySet {
  int key[MAXKEY];
  bool operator<(const KeySet & B) {
    for (int i = 0; i < MAXKEY; i++) {
      if (B.key[i] > key[i]) return false;
    }
    return true;
  }
  void operator+=(const KeySet &b) {
    for (int i = 0; i < MAXKEY; i++) key[i] += b.key[i];
  }
  void operator-=(const KeySet &b) {
    for (int i = 0; i < MAXKEY; i++) key[i] -= b.key[i];
  }
  void reset() {
    memset(key, 0, sizeof(key));
  }
};

bool traversed[1050000];
KeySet cur;
int bitset;
int N;
int ans[MAXCHEST];

int req[MAXCHEST];
KeySet obt[MAXCHEST];

void rek(int step) {
  //printf("depth %d bitset 0x%x\n", step, bitset);
  if (step == N) {
    // done
    // cout << "found a solution" << endl;
    throw NULL;
  }
  for (int i = 0; i < N; i++) {
    //printf("i %d\n", i);
    bool tmp1 = ( (bitset & (1<<i)) == 0);
    bool tmp2 = (! traversed[bitset | (1<<i)]);
    bool tmp3 = ( cur.key[req[i]] > 0);
    //cout << i << ' ' << tmp1 << tmp2 << tmp3 << endl;
    if ( ( (bitset & (1<<i)) == 0) &&
	 (! traversed[bitset | (1<<i)]) &&
	 ( cur.key[req[i]] > 0)) {
      //cout << "test\n";
      bitset |= (1<<i);
      traversed[bitset] = true;
      ans[step] = i;
      cur.key[req[i]]--;
      cur += obt[i];
      rek(step+1);
      cur -= obt[i];
      cur.key[req[i]]++;
      bitset &= ~(1<<i);
    }
  }
}

int main() {
  int cases, K, tmp, nk;
  cin >> cases;
  for (int T = 1; T <= cases; T++) {
    memset(traversed, 0, sizeof(traversed));
    cur.reset();
    
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
      cin >> tmp;
      cur.key[tmp]++;
    }
    for (int i = 0; i < N; i++) {
      cin >> req[i] >> nk;
      obt[i].reset();
      for (int j = 0; j < nk; j++) {
	cin >> tmp;
	obt[i].key[tmp]++;
      }
    }
    bitset = 0;
    printf("Case #%d:", T);
    try {
      rek(0);
      cout << " IMPOSSIBLE\n";
    } catch (...) {
      for (int i = 0; i < N; i++) {
	printf(" %d", ans[i] + 1);
      }
      cout << endl;
    }
  }
  return 0;
}
