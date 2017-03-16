#include <iostream>
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

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
#define FOREACH(x,y) for(typeof(y.begin()) x = y.begin() ; x != y.end() ; x++)
#define DEB(v) cout << "#v = " << endl;

long long MOD = (long long)1000000007;

int main() {
	int T,tc,n;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int tc = 1 ; tc <= T ; tc++) {
		scanf("%d",&n);
		int c;
		vector <int> v,v1;
		int sum = 0;
		FOR(i,0,n) {
			cin>>c;
			sum = sum + c;
			v.pb(c);
			v1.pb(c);
		}
		sort(v.begin(),v.end());
		double ans = 0;
		int num = 1;
		double s = 0;
		for(num = 1 ; num <= n ; num++) {
			ans = 1.0 / num;
			s = 0;
			for(int i = 0 ; i < num ; i++) {
				s = s + v[i];
			}
			s = (s + sum) * ans;
			if(num <= n) {
				if(s <= v[num]) break;
			} else {
				break;
			}
		}
		cout << "Case #" << tc << ": ";
		FOR(i,0,n) {
			if(v1[i] > s) {
				cout << 0 << " ";
			} else {
				cout << (s-v1[i]) * 100 / sum << " ";
			}
		}
		cout << endl;
	}
	return (0);
}