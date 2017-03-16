#include <cstdio>

void backtracking (int *coins, int index, int nc, int acum, bool *possible, int V) {
  if (acum > V)
    return;
  possible[acum] = true;
  for (int i = index + 1; i < nc; ++i) {
    backtracking (coins, i, nc, acum + coins[i], possible, V);
    backtracking (coins, i, nc, acum, possible, V);
  }
}

void generateAllValues (int *coins, int nc, bool *possible, int V) {
  for (int i = 0; i < nc; ++i) {
    backtracking (coins, i, nc, coins[i], possible, V);
  }
}

int main () {

  int T;
  scanf ("%d", &T);

  for (int t = 1; t <= T; ++t) {
    int C, D, V;
    scanf ("%d%d%d", &C, &D, &V);
    int denom [1000];
    bool possible [50]; //For the small dataset
    for (int i = 1; i <= V; ++i)
      possible[i] = false;
    for (int d = 0; d < D; ++d) {
      scanf ("%d", &denom[d]);
      possible[denom[d]] = true;
    }
    // C will always be 1 in the small dataset
    generateAllValues (denom, D, possible, V);
    
    // Make all the V possible
    int added = 0;
    for (int i = 1; i <= V; ++i) {
      if (!possible[i]) {
	denom[D+added] = i;
	generateAllValues (denom, D+added+1, possible, V);
	++added;
      }
    }

    printf ("Case #%d: %d\n", t, added);
  }

  return 0;
}
