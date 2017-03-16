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


int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
    int N,S,p;
    cin >> N >> S >> p;
    int t,tot=0;
    for(int i=0;i<N;i++) {
      cin >> t;
      int mx = (t-1)/3 + 1;
      if(t==0)
        mx=0;
      if(mx>=p)
        tot++;
      if(t<2)
        continue;
      if(mx==p-1 && t%3!=1 && S>0) {
        tot++; S--;
      }
    }
		cout << "Case #" << c << ": " << tot << endl;
	}
	return 0;
}
