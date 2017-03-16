#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> J;
int S;

double howm(double sc, int j) {
  double r=0;
  for(int i=0;i<J.size();i++) {
    if(i==j)
      continue;
    if(J[i] < sc)
      r+=(sc-J[i])/S;
  }
  return r;
}

double bins(int j) {
  double mn=0,mx=1,md,v;
  while(mx-mn > 1e-12) {
    md=(mx+mn)/2;
    v = howm(J[j]+S*md,j);
    if(v+md > 1)
      mx = md;
    else
      mn = md;
  }
  if(md < 1e-7)
    return 0;
  if(md > 99.9999999)
    return 100;
  return md;
}

int main() {
	int T;
	cin >> T;

	for(int c=1;c<=T;c++) {
    int N;
    cin >> N;
    S=0;
    int s;
    for(int i=0;i<N;i++) {
      cin >> s;
      S+=s;
      J.push_back(s);
    }

		cout << "Case #" << c << ":";
    
    for(int i=0;i<N;i++)
      cout << ' ' << setprecision(12) << 100*bins(i);
    cout << endl;
    
    J.clear();
    
	}
	return 0;
}
