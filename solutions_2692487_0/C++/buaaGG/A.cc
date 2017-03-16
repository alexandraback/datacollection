#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void solve(int ri) {
	int A, n; cin >> A >> n;
	vector<int> v(n);
	for ( int i = 0; i < n; ++i ) {
		cin >> v[i];
	}
	sort( v.begin(), v.end() );
	int ans = n;
	for ( int i = 0, j = 0; i < n && j < n; ++i ) {
		while ( A <= v[i] && j < n ) {
			j++;
			A += A - 1;
		}
		A += v[i];
		ans = min( ans, j + (n-i-1) );
	}
	printf("Case #%d: %d\n", ri, ans);

}

int main() {
	int re; cin >> re;
	for ( int ri = 1; ri <= re; ++ri ) solve(ri);
}
