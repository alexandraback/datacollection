#include <iostream>
#include <cstring>
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

#define LL long long

LL MOD = 1000000007;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	cin >> tc;
	for(int t = 1 ; t <= tc ; t++) {
		int a,n;
		cin >> a >> n;
		vector <int> v(n);
		for(int i = 0 ; i < n ; i++) {
			cin>> v[i];
		}
		sort(v.begin(), v.end());
		int rem = n;
		int ans = 0;
		for(int i = 0 ; i < n ; ) {
			if(a > v[i]) {
				a = a + v[i];
				i++;
			} else {
				rem = min(rem,ans + n - i);
				ans++;
				if(a == 1) {
					ans = n;
					break;
				}
				a = 2*a - 1;
			}
		}
		cout << "Case #" << t << ": " << min(ans,rem) << endl;
	}
	return (0);
}