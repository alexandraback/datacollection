#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int N;
int num[505];

vector<int> st1, st2;

void dump(const vector<int> &st) {
  for (int i=0; i<(int)st.size(); ++i) {
    if (i > 0) cout << ' ';
    cout << st[i];
  }
  cout << '\n';
}

void rek(int pos, int a, int b) {
  if (pos == N) {
    return;
  }

  if (a == b && a > 0) {
    dump(st1);
    dump(st2);
    throw 1;
  }

  rek(pos+1, a, b);

  int x = num[pos];
  st1.push_back(x);
  rek(pos+1, a+x, b);
  st1.pop_back();

  if (a > 0 || b > 0) {
    st2.push_back(x);
    rek(pos+1, a, b+x);
    st2.pop_back();
  }
}

int main() {
  cin.sync_with_stdio(0);
 
  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    cin >> N;
    for (int i=0; i<N; ++i) {
      cin >> num[i];
    }
    cout << "Case #" << tt << ":\n";
    try {
      st1.clear();
      st2.clear();
      rek(0, 0, 0);
      cout << "Impossible\n";
    } catch (int x) {
    }
  }  
  
  return 0;
}
