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

double p[100010],mp[100010];

int main() {
	int T;
	cin >> T;

	for(int c=1;c<=T;c++) {
    int A,B;
    cin >> A >> B;
    mp[0]=1;
    for(int i=0;i<A;i++) {
      cin >> p[i];
      mp[i+1] = p[i]*mp[i];
      //cout << i << ' ' << mp[i+1] << endl;
    }
    int left=B-A;
    double mn=B+2;
    for(int i=0;i<=A;i++) {
      double prob = mp[i]*(B-i+A-i+1) + (1-mp[i])*(B-i+A-i+B+2);
      //cout <<prob << ' ';
      if(prob < mn)
        mn = prob;
    }
    
		cout << "Case #" << c << ": " << setprecision(10) << mn  << endl;
	}
	return 0;
}
