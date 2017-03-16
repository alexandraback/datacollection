#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cassert>
#include <set>
#include <iomanip>
using namespace std;

#include "gmpxx.h"
typedef mpz_class big;

#define REP(i,n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MP make_pair
#define PB push_back

const int N = 1000005;
char s[N];
int n, sum[N];

int main() {
	/* big x, y;
	cin >> x >> y;
	cout << (x+y) << endl; */
	
	int T;
	cin >> T;
	REP(qqq,T) {
		//logic start
		cin >> s >> n;
		int l = strlen(s), c = 0;
		REP(i,l) {
			if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
				c++;
			else
				c = 0;
			
			sum[i] = (i ? sum[i-1] : 0) + (c >= n);
			//cout << sum[i] << " ";
		}
		sum[l] = l+100;
		//cout << endl;
		
		ll ans = 0;
		REP(i,l) {
			if (i+n-1 <= l-1) {
				int prev = (i+n-2>=0 ? sum[i+n-2] : 0);
				int low = i + n-1, high = l;
				while (low < high) {
					int mid = (low+high)/2;
					//cout << mid << " ";
					if (sum[mid] > prev)
						high = mid;
					else
						low = mid+1;
				}
				ans += l - low;
				
				/*cout << "!" << low << " " << ans << endl;
				for (int e = low; e < l; e++) {
					for (int z = i; z <= e; z++)
						cout << s[z];
					cout << endl;
				}*/
			}
		}
		
		//logic end
		cout << "Case #" << (qqq+1) << ": " << ans << endl;
	}
}
