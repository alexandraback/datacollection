#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>
#include <deque>
#include <list>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small.out", "w", stdout);

	cout<<fixed<<setprecision(7);
	int T; cin>>T;
	double d, t[2000], x[2000], a[250];
	int n, na;
	for (int test=1; test<=T; test++) {
		cin>>d>>n>>na;
		for (int i=0; i<n; i++) {
			cin>>t[i]>>x[i];
		}
		for (int i=0; i<na; i++)
			cin>>a[i];

		printf("Case #%d:\n", test);
		if (n==1) {
			for (int i=0; i<na; i++)
				cout<<sqrt( (d+d)/a[i] )<<endl;
		}
		else if (n==2) {
			double v = (x[1]-x[0])/(t[1]-t[0]);
			for (int i=0; i<na; i++) {
				double t1 = sqrt( (d+d)/a[i] );
				double t2 = (d-x[0])/v;
				cout<<max(t1, t2)<<endl;
			}
		}
	}

	return 0;
}
