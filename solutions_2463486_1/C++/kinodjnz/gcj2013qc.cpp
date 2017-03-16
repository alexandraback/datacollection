#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

bool ispalindrome(ll x) {
	char b[100];
	sprintf(b, "%lld", x);
	int n = strlen(b);
	for (int i = 0; i < n/2; i++) {
		if (b[i] != b[n-1-i])
			return false;
	}
	return true;
}

int main() {
	vector<ll> v;
	for (int i = 1; i <= 10000000; i++) {
		if (ispalindrome(i) && ispalindrome((ll)i*i)) {
			//printf("%d ", i);
			v.push_back((ll)i*i);
		}
	}
	//printf("\n");
	int n = v.size();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll A, B;
		cin >> A >> B;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			if (A <= v[j] && v[j] <= B)
				ans++;
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
