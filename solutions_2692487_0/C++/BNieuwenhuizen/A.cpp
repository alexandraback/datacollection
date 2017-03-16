
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;



void doit (int casenum) {
  int A, N;
  cin >> A >> N;
  vector<int> v(N);
  for(int i = 0; i < N; ++i)
    cin >> v[i];
  int m = N;
  int c = 0;
  sort(v.begin(), v.end());
  for(int i = 0; i < N; ++i) {
    m = min(m, c + N-i);
    if(A <= v[i] && A <= 1) break;
    while(A <= v[i]) { c++; A = 2*A-1; }
    m = min(m, c+ N-i-1);
    A += v[i];
  }
  cout << "Case #"  << casenum << ": " << m << endl;
}

int main () {
	int t;
	cin >> t; //scanf ("%d ", &t);
	for (int i = 0; i < t; i++) {
		doit (i+1);
	}
	return 0;
}
