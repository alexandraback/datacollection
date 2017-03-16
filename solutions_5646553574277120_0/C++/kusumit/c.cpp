#include <bits/stdc++.h>

using namespace std;

int de[999999];

int main()
{
  ios_base::sync_with_stdio(false);
  ifstream in("c.in");
  ofstream out("sol.out");
  int _c;
  in >> _c;

  for(int _cc = 1; _cc <= _c; ++_cc) {
    out << "Case #" << _cc << ": ";

    int c, d , v;
    in >> c >> d >> v;

    for (int i = 0; i < d; ++i) {
      in >> de[i];
    }

    out << v - d << '\n';
  }

  return 0;
}

