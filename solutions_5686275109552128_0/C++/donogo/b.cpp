#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>

int debug = 0;

using namespace std;

struct classcomp {
  bool operator() (const int&lhs, const int& rhs) const
  {return lhs > rhs;}
};


void show(multiset <int, classcomp> S) {
  multiset <int, classcomp> :: iterator it;
  cout << "{";
  for (it = S.begin(); it != S.end(); it++) {
    cout << *it << "," ;
  }
  cout << "}" << endl;
}

void indent( int d, string st) {
  cout << st << " ";
}

int evaluate( multiset <int, classcomp> S) {
  int maxheight = *S.begin();
  int best = 100000;
  int cost;
  int elast; // the length of eat phase
  int best_elast;
  multiset <int, classcomp> :: iterator it;

  for (elast = 1; elast <= maxheight; elast++) {
    cost = elast;
    for (it = S.begin(); it != S.end(); it++) {
      if ( *it > elast ) {
	cost += ((*it) - elast) / elast;
	if ((*it) % elast)
	  cost++;
      }
    }
    if (cost < best) {
      best = cost;
      best_elast = elast;
    }
  }

  if (debug) {
    multiset <int, classcomp> T;
    int x;
    for (it = S.begin(); it != S.end(); it++) {
      x = *it;
      if ( x > best_elast ) {
	while ( x >= best_elast) {
	  T.insert( best_elast);
	  x -= best_elast;
	}
      } 
      T.insert(x);
    }
    cout << "best_elast=" << best_elast << endl;
    show(T);
  }
  return best;
}


int main(void) {
  int T, t;
  int D, d, p;
  int res;


  cin >> T;

  for (t = 1; t <= T; t++) {
    multiset <int, classcomp> S;
    cin >> D;
    for (d = 0; d < D; d++) {
      cin >> p;
      S.insert(p);
    }

    if (debug) {
      indent(0, "");
      cout << 0 << "*";
      show(S);
    }

    res = evaluate(S);

    cout << "Case #" << t << ": " << res << endl;

  }
  return 0;
}
