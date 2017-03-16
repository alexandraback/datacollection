#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;

void print_grid(uint r, uint c, uint m, vector< vector< char > > g) {
  g.resize(r);
  for (uint i = 0; i < r; i++) {
    g[i].resize(c);
    for (uint j = 0; j < c; j++) {
      g[i][j] = '.';
    }
  }

  // special case: max mines
  if (m >= r * c - 1) {
    for (uint i = 0; i < r; i++) {
      for (uint j = 0; j < c; j++) {
	g[i][j] = '*';
      }
    }
    m = 0;
  }

  g[0][0] = 'c';

  // special case: 1 row
  if (r == 1 && m > 0) {
    for (uint j = c-1; j > 0; j--) {
      if (!m) { break; }
      g[0][j] = '*';
      m--;
    } // for j
  } // if

  // special case: 1 col
  if (c == 1 && m > 0) {
    for (uint i = r-1; i > 0; i--) {
      if (!m) { break; }
      g[i][0] = '*';
      m--;
    } // for i
  } // if

  // fill safe area
  for (uint i = r-1; i > 1; i--) {
    if (!m) { break; }
    for (uint j = c-1; j > 1; j--) {
      if (!m) { break; }
      g[i][j] = '*';
      m--;
    } // for j
  } // for i

  if ( (m % 2 != 0) && (r > 2) && (c > 2) ) {
    g[2][2] = '.';
    m++;
  } // if

  // fill top cols
  for (uint i = r-1; i > 1; i--) {
    if (m < 2) { break; }
    if (i == 2 && c > 2 && g[2][2] == '.') { break; }
    g[i][0] = '*';
    g[i][1] = '*';
    m -= 2;
  } // for i

  // fill top rows
  for (uint j = c-1; j > 1; j--) {
    if (m < 2) { break; }
    if (j == 2 && r > 2 && g[2][2] == '.') { break; }
    g[0][j] = '*';
    g[1][j] = '*';
    m -= 2;
  } // for j

  if (m > 0) {
    cout << "Impossible\n";
    return;
  } // if

  for (uint i = 0; i < r; i++) {
    for (uint j = 0; j < c; j++) {
      cout << g[i][j];
    } // for j
    cout << endl;
  } // for i
}

int main()
{
  uint t = 0;
  cin >> t;

  for (uint i = 1; i <= t; i++) {
    vector< vector< char > > g;
    uint r, c, m;
    cin >> r >> c >> m;

    printf("Case #%d:\n", i);
    //printf("%d %d %d\n", r, c, m);
    print_grid(r, c, m, g);

    /*
      // this should no longer be necessary
    uint f = r * c - m;
    if (r == 1 || c == 1 || m == 0) {
      print_grid(r, c, m);
    } else switch(f) {
    case 2:
    case 3:
    case 5:
    case 7:
      printf("Impossible\n");
      break;
    default:
      print_grid(r, c, m);
    }
    */
  } // for i

  return 0;
} // main
