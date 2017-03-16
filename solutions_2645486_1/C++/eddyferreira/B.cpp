#include <algorithm>
#include <iostream>
#include <utility>
#include <list>
using namespace std;

int V[20000];

int main(void) {
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    cout << "Case #" << tt << ": ";
    int64_t E, R, N, pos;
    cin >> E >> R >> N;
    for (int i = 0; i < N; ++i) cin >> V[i];
    typedef list<pair<int,int> > lii;
    lii fn;
    int64_t sc = 0;
    fn.push_back(make_pair(E, V[0]));
    for (int i = 1; i < N; ++i) {
      lii::iterator it;
      pos = 0;
      for (it = fn.begin(); it != fn.end(); ++it) {
        //cout << "Moving " << it->first << "," << it->second << endl;
        it->first += R;
        if (it->first > E) {
          sc += (it->first - E) * it->second;
          //cout << "New sc " << sc << endl;
          if (pos == E) {
            //cout << "Pruning this" << endl;
            pos = it->first - R;
            fn.erase(it++);
          } else {
            pos = it->first - R;
            it->first = E;
            //cout << "Pruning after this" << endl;
            it++;
          }
          for (; it != fn.end(); ) {
            sc += (it->first - pos) * it->second;
            pos = it->first;
            fn.erase(it++);
          }
          fn.erase(it, fn.end());
          break;
        }
        pos = it->first;
      }
      pos = R;
      for (it = fn.begin(); it != fn.end(); ++it) {
        if (it->second > V[i])
          break;
        //cout << "New pt " << V[i] << " supercedes " << it->first << "," << it->second << endl;
        pos = it->first;
      }
      it = fn.insert(it, make_pair(pos, V[i]));
      fn.erase(fn.begin(), it);
      //for (it = fn.begin(); it != fn.end(); ++it) {
      //  cout << "(" << it->first << "," << it->second << ") ";
      //}
      //cout << endl;
    }
    pos = 0;
    for (lii::iterator it = fn.begin(); it != fn.end(); ++it) {
      sc += (it->first - pos) * it->second;
      pos = it->first;
    }
    cout << sc << endl;
  }
}
