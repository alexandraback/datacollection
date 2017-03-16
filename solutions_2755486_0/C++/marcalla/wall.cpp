#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct attack {
  int day;
  int strength;
  int west;
  int east;

  attack (int d, int s, int w, int e) : day(d), strength(s), west(w), east(e)  {};
};

struct stone {
  int height;
  int candidate;
};

bool compareAttacks (attack a, attack b) {
  if (a.day != b.day)
    return (a.day < b.day);
  else
    return (a.strength < b.strength);
}

int main () {

  stone heights [1001]; // center: 500
  int center = 500;
  int T;
  scanf ("%d", &T);
  for (int t = 1; t <= T; ++t) {
    vector <attack> attacks;
    for (int i = 0; i < 1001; ++i) {
      heights[i].height = 0;
      heights[i].candidate = 0;
    }
    int ntribes;
    scanf ("%d", &ntribes);
    //printf ("ntribes = %d\n", ntribes);
    for (int j = 0; j < ntribes; ++j) {
      int d, n, w, e, s, deltaD, deltaP, deltaS;
      scanf ("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &deltaD, &deltaP, &deltaS);
      for (int i = 0; i < n; ++i) {
	attacks.push_back(attack(d, s, w, e));
	d += deltaD;
	w += deltaP;
	e += deltaP;
	s += deltaS;
      }
    }
    sort (attacks.begin(), attacks.end(), compareAttacks);
    //for (int i = 0; i < (int)attacks.size(); ++i)
    //printf ("day: %d strength: %d west: %d east: %d\n", attacks[i].day, attacks[i].strength, attacks[i].west, attacks[i].east);

    int successful = 0;
    for (int i = 0; i < (int)attacks.size(); ++i) {
      if (i != 0 && attacks[i].day != attacks[i-1].day) {
	for (int j = 0; j < 1001; ++j)
	  heights[j].height = heights[j].candidate;
      }
      bool tSuc = false;
      for (int j = attacks[i].west*2 + center; j <= attacks[i].east*2+center; ++j) {
	if (attacks[i].strength > heights[j].height) {
	  //printf ("attack #%d succeeds!\n", i);
	  tSuc = true;
	  heights[j].candidate = max(heights[j].candidate, attacks[i].strength);
	}
      }
      if (tSuc)
	++successful;
    }
    printf ("Case #%d: %d\n", t, successful);
  }

  return 0;
}
