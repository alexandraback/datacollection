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
#include <unordered_set>
#include <unordered_map>

using namespace std;
unordered_map<int, unordered_set<int> > M;
unordered_set<int> S;
vector<int> v;
int c;
int N;

bool add(int sum, int i) {
  S.insert(v[i]);
  sum+=v[i];
  if(M.count(sum)) {
    cout << "Case #" << c << ":" << endl;
    unordered_set<int>::iterator it;
    for(it = S.begin(); it!=S.end();it++) {
      if(it!=S.begin())
        cout << ' ';
      cout << *it;
    }
    cout << endl;
    S = M[sum];
    for(it = S.begin(); it!=S.end();it++) {
      if(it!=S.begin())
        cout << ' ';
      cout << *it;
    }
    cout << endl;
    return true;
  }
  
  M[sum] = S;
  
  for(int j=i+1;j<N;j++) {
    if(add(sum,j))
      return true;
  }
  
  S.erase(v[i]);
  
  return false;
}
  
int main() {
	int T;
	cin >> T;

	for(c=1;c<=T;c++) {
    S.clear();
    M.clear();
    cin >> N;
    v.assign(N,0);
    for(int i=0;i<N;i++)
      cin >> v[i];
    bool flag=false;
    for(int i=0;i<N && !flag;i++) {
      if(add(0,i))
        flag=true;
    }
    if(flag)
      continue;
		cout << "Case #" << c << ":" << endl << "Impossible" <<endl;
	}
	return 0;
}
