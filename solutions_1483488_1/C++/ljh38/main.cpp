#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t = 0; t != T; ++t) {
    int A, B;
    cin >> A >> B;

    char str[10];

    int total = 0;
    for (int n1 = A; n1 <= B; ++n1) {
      sprintf(str, "%d", n1);

      set<int> pairs;
      string s = str;
      for (int j = 0; j != s.length(); ++j) {
	std::rotate(s.begin(), s.begin() + 1, s.end());

	if (s[0] != '0') {
	  int n2 = atoi(s.c_str());

	  // have to check if n2 is already here in this rotation
	  
	  if (n2 <= B && n2 > n1 && (pairs.find(n2) == pairs.end())) {
	    ++total;
	    pairs.insert(n2);
	  }
	}
      }
    }

    cout << "Case #" << t + 1 << ": " << total << endl;
  }
  return 0;
}
