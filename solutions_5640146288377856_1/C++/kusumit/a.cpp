#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  ifstream in("a.in");
  ofstream out("sol.out");
  int _c;
  in >> _c;

  for(int _cc = 1; _cc <= _c; ++_cc) {
    out << "Case #" << _cc << ": ";

    int r, c, w, n = 0;
    in >> r >> c >> w;

    n = c / w * r;

    if (c % w != 0) {
      ++n;
    }
    n += w - 1;

    out << n << '\n';
  }

  return 0;
}

