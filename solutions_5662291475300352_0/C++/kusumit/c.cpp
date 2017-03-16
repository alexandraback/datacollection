#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int> > h[2];

int main()
{
  ios_base::sync_with_stdio(false);
  ifstream in("c.in");
  ofstream out("sol.out");
  int _c;
  in >> _c;

  for(int _cc = 1; _cc <= _c; ++_cc)	{
    out << "Case #" << _cc << ": ";

    int n, encounters = -1;
    in >> n;

    for (int i = 0; i < n; ++i) {
      int start, numHikers, rate;
      in >> start >> numHikers >> rate;
      h[i] = make_pair(start, make_pair(numHikers, rate));
    }

    if (h[0].second.first == 2) {
      encounters = 0;
    } else {
      if (h[0].first < h[1].first) {
	swap(h[0], h[1]);
      }
      if (h[0].second.second == h[1].second.second) {
	encounters = 0;
      } else if (h[0].second.second > h[1].second.second) {
	encounters = (h[0].second.second - h[0].first) / (h[1].second.second);
      } else {
	encounters = (h[1].second.second - h[1].first) / (h[0].second.second);
      }
    }

    out << encounters << '\n';
  }

  return 0;
}

