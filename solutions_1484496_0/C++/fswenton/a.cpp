#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

#define InputVector(v, Type) vector<Type> v; { Type t; int _n; cin >> _n; v.reserve(_n); while (--_n >= 0) { cin >> t; v.push_back(t); } }

bool debug = false;

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    InputVector(x, int);
    
    cout << "Case #" << iTest << ":\n";

    int i;
    map<int, int> sums;
    int flags;
    for (flags = 0; flags < (1 << 20) - 1; ++flags) {
      int sum = 0;
      for (i = 0; i < 20; ++i)
	if (flags & (1 << i))
	  sum += x[i];
      map<int, int>::iterator iSum = sums.find(sum);
      if (iSum!=sums.end()) {
	bool first;

	first = true;
	for (i = 0; i < 20; ++i)
	  if (flags & (1 << i)) {
	    if (!first) cout << " "; else first = false;
	    cout << x[i];
	  }
	cout << "\n";

	first = true;
	for (i = 0; i < 20; ++i)
	  if (iSum->second & (1 << i)) {
	    if (!first) cout << " "; else first = false;
	    cout << x[i];
	  }
	cout << "\n";

	break;
      } else
	sums[sum] = flags;
    }

    if (flags >= (1 << 20) - 1)
      cout << "Impossible\n";
  }

  return 0;
}
