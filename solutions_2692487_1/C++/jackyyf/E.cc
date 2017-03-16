#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<climits>
#include<ciso646>
#include<cctype>
#include<ctime>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<numeric>
#include<complex>
#include<vector>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<list>
#include<stack>

using namespace std;

typedef map<int, int> mii;
typedef set<int> si;
typedef queue<int> qi;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace Solve {
	template<class T> bool _min(T &data, const T &comp) {
		if(data > comp) {
			data = comp;
			return true;
		}
		return false;
	}

	template<class T> bool _max(T &data, const T &comp) {
		if(data < comp) {
			data = comp;
			return true;
		}
		return false;
	}

	int data[1048576];

	void main() {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		register int i, j, t;
		ios_base::sync_with_stdio(false);
		int T;
		cin >> T;
		for(t = 1; t <= T; ++ t) {
			cout << "Case #" << t << ": ";
			long long a; int n;
			cin >> a >> n;
			for(i = 0; i < n; ++ i) {
				cin >> data[i];
			}
			sort(data, data + i);
			int ans = n;
			int cur = 0;
			if(a < 2) { cout << n << endl; continue; }
			for(i = 0; i < n; ++ i) {
				if(a > data[i]) a += data[i];
				else {
					while(a <= data[i]) {
						a += (a - 1);
						++ cur;
					}
					a += data[i];
				}
				_min(ans, cur + n - i - 1);
			}
			cout << ans << endl;
		}
	}

}

int main() {
	Solve::main();
	return 0;
}
