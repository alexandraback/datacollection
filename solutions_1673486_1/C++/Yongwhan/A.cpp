#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime> 
#define INF 1000000000
using namespace std;

int main() {
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int a,b; cin>>a>>b;
		double ans=b+2;
		vector<double> v(a);
		for (int i=0; i<a; i++) cin>>v[i];

		double p=1;
		for (int i=0; i<=a; i++) {
			int k=a-i;
			int x=(b-a)+2*k+1, y=(b-a)+2*k+1 + (b+1);
			double cur=p*x + (1-p)*y;
			p*=v[i];
			ans=min(ans,cur);
		}


		cout << "Case #" << c << ": " << setprecision(6) << fixed << ans << endl;
	}
	return 0;
}
