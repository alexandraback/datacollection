#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> pii;

int memo[1000001];

int main() {
	memo[1] = 1;
	for(int i=2; i<=1000000; i++) {
		if(i%10 == 0) {
			memo[i] = memo[i-1]+1;
		} else {
			int j = i;
			int rev = 0;
			while(j>0) {
				rev = rev*10 + (j%10);
				j /= 10;
			}
			if(rev < i) {
				memo[i] = min(memo[i-1], memo[rev]) + 1;
			} else {
				memo[i] = memo[i-1] + 1;
			}
		}
	}
	int t;
	cin >> t;
	rep(dt, t) {
		ll n;
		cin >> n;
		cout << "Case #" << (dt+1) << ": " << memo[n] << endl;
	}
	return 0;
}
