#include <iostream>
#include <vector>
using namespace std;

int K, N;

int keys[250];
int type[250];
vector<int> in_chest[210];

int order[250];
bool is_open[250];

void op(int idx) {
  if (idx == N) {
    throw 1;
  }

  for (int c=1; c<=N; c++) {
    if (is_open[c]) {
      continue;
    }
    int t = type[c];
    if (keys[t] > 0) {
      order[idx] = c;
      keys[t]--; // spend on opening of type t
      is_open[c] = true;
      // take keys
      for (int j=0; j<in_chest[c].size();j++) {
        int t2 = in_chest[c][j];
        keys[t2]++;
      }

      op(idx + 1);

      keys[t]++; // restore my spending
      is_open[c] = false;
      // put back the keys
      for (int j=0; j<in_chest[c].size();j++) {
        int t2 = in_chest[c][j];
        keys[t2]--;
      }
    }
  }
}

int main() {
  int T; cin >> T;

  for (int cs=1; cs<=T; cs++) {
    cin >> K >> N;
    for (int i=0;i<250;i++) {
      is_open[i] = false;
      keys[i]=0;
    }
    for (int i=0;i<K;i++) {
      int key; cin >> key;
      keys[key]++;
    }

    for (int i=1;i<=N;i++) {
      cin >> type[i];
      int L; cin >> L;
      for (int j=0;j<L;j++) {
        int inside; cin >>inside;
        in_chest[i].push_back(inside);
      }
    }
    printf("Case #%d:", cs);
    try {
      op(0);
      printf(" IMPOSSIBLE\n");
    } catch (int x) {
      for (int i=0; i<N;i++) {
        printf(" %d", order[i]);
      }
      printf("\n");
    }
  }
}
