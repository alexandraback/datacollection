#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;
typedef set< double > tBlocks;
typedef tBlocks::iterator bit;
typedef tBlocks::reverse_iterator brit;

// Naomi: "We're playing War!"
// Ken: "I hope you like to lose!"
// Naomi: "I hate you."
uint war(tBlocks p1, tBlocks p2)
{
  uint wins = 0;

  for ( bit i = p1.begin(); i != p1.end(); i++ ) {
    bit j = p2.lower_bound( *i );
    if ( j == p2.end() ) {
      j = p2.begin();
      wins++;
    } // if
    p2.erase( j );
  } // for i

  return wins;
}

// Ken: "We're playing War!"
// Naomi: "Yes.  Yes we are."
uint badwar(tBlocks p1, tBlocks p2)
{
  uint wins = 0;

  for ( bit i = p1.begin(); i != p1.end(); i++ ) {
    bit j = p2.lower_bound( *i );
    if ( j == p2.begin() ) {
      j = p2.end();
    } else {
      wins++;
    } // else
    p2.erase(--j);
  } // for i

  return wins;
}

int main()
{
  uint t;
  cin >> t;

  for ( uint i = 1; i <= t; i++ ) {
    uint n;
    cin >> n;

    double x;
    tBlocks p1, p2;
    for ( uint j = 0; j < n; j++ ) {
      cin >> x;
      p1.insert(x);
    } // for j
    for ( uint j = 0; j < n; j++ ) {
      cin >> x;
      p2.insert(x);
    }

    printf( "Case #%d: %d %d\n", i, badwar( p1, p2 ), war( p1, p2 ) );
    /*
    for ( bit j = p1.begin(); j != p1.end(); j++ ) {
      cerr << *j << '\t';
    }
    cerr << endl;
    for ( bit j = p2.begin(); j != p2.end(); j++ ) {
      cerr << *j << '\t';
    }
    cerr << endl;
    */
  } // for i

  return 0;
} // main
