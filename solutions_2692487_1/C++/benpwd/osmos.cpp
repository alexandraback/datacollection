#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
  // ifstream fin("A-small-attempt2.in.txt");
  ifstream fin("A-large-1.in.txt");
  // ifstream fin("input.txt");
  int cases;
  int cnt = 0;

  fin >> cases;
  while (++cnt <= cases) {
    int A, N;
    int x;
    vector<int> V;
    fin >> A >> N;

    for (int i = 0; i < N; ++i) {
      fin >> x;
      V.push_back(x);
    }
    std::sort(V.begin(), V.end());

    int r = 0;
    int i;
    if (A == 1) {
      cout << "Case #" << cnt << ": " << V.size() << endl;
      continue;
    }

    for (i = 0; i < V.size(); ++i) {
      // cout << A << ' ' << V[i] << endl;
      int y = 0;
      while (A <= V[i]) {
	A += (A - 1);
	++y;
      }
      if (y > V.size() - i) {
	break;
      }
      r += y;
      // if (A + A - 1 <= V[i]) {
      // 	break;
      // }

      if (A <= V[i]) {
	A += (A - 1);
	++r;
      } else {
	A = A + V[i];
      }
    }

    r += (V.size() - i);
    cout << "Case #" << cnt << ": " << std::min((size_t)r, V.size()) << endl;
  }
  fin.close();
  return 0;
}
