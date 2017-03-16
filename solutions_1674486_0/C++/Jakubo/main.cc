#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector <vector <int> > a;
vector <int> g;
bool t;

void r(int N)
{
  for (int i = 0; i < (int)a[N - 1].size(); ++i) {
    g.push_back(a[N - 1][i]);
    r(a[N - 1][i]);
  }
}

int main()
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; ++i) {
    cout << "Case #" << i + 1 << ": ";
    int N;
    cin >> N;
    a.clear();
    g.clear();
    t = false;
    for (int j = 1; j <= N; ++j) {
      int M;
      cin >> M;
      vector <int> buffer;
      for (int k = 0; k < M; ++k) {
        int b;
        cin >> b;
        buffer.push_back(b);
      }
      a.push_back(buffer);
    }
    for (int j = 1; j <= N; ++j) {
      r(j);
      for (int l = 1; l <= N; ++l) {
        int vyskyty = 0;
        for (int k = 0; k < (int)g.size(); ++k) {
          if (g[k] == l)
            ++vyskyty;
        }
        if (vyskyty > 1) {
          cout << "Yes" << endl;
          goto next;
        }
      }
      g.clear();
    }
    cout << "No" << endl;
    next:;
  }

  return 0;
}
