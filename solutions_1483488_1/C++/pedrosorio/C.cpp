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
    set<int> done;
    int A,B;
    cin >> A >> B;
    int ct=0;
    int mlts;
    for(mlts=10;A/mlts>9;mlts*=10);      
    for(int n=A;n<B;n++) {
      done.clear();
      int mlt=mlts,dv=10;
      int frt = n/dv, bck = n%dv;
      while(frt) {
        int m = mlt*bck + frt;
        if(m > n && m<=B && done.count(m)==0) {
          done.insert(m);
          ct++;
          //cout << n <<  ' ' << m << endl;
        }
        mlt/=10;
        dv*=10;
        frt/=10;
        bck = n%dv;
      }
    }
		cout << "Case #" << c << ": " << ct  << endl;
	}
	return 0;
}
