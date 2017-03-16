#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <complex>
#include <cassert>

using namespace std;
typedef long long ll;
typedef double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int heights[1<<16];
vector<int> ans;

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		int n; cin >> n;
		for (int i = 0; i < n*(2*n-1); i++){
			cin >> heights[i];
		}
		sort(heights,heights+n*(2*n-1));
		ans.clear();
		int cnt = 0;
		for (int i = 0; i < n*(2*n-1); i++){
			cnt++;
			//cout << "i = " << i << ", h[i] = " << heights[i] << ", cnt = " << cnt << endl;
			if (i == n*(2*n-1)-1 || heights[i] != heights[i+1]){
				if (cnt % 2) ans.push_back(heights[i]);
				cnt=0;
			}
		}
		//cout << "ans.size() == " << ans.size() << endl;
		assert(ans.size() == n);
		cout << "Case #" << zz << ":";
		for (int i = 0; i < n; i++)
			cout << " " << ans[i];
		cout << endl;
	}
	
	return 0;
}
