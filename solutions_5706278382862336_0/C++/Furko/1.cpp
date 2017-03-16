#include <string>
#include <set>
#include <ctime>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define INF 1000000000

long long a, b;
char q;

bool good(long long x) {
	for (int i = 0; i < 50; ++i) {
		if ((1LL << i) == x) return true;
	}
	return false;
}

long long gcd(long long a, long long b) {
	while (a > 0 && b > 0) {
		if (a > b) a %= b; else b %= a;
	}
	return (a + b);
}

int tmp = 0;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int tests = 1; tests <= t; ++tests) {
		cout << "Case #" << tests << ": ";
		cin >> a >> q >> b;
		long long lcm = gcd(a, b);
		a /= lcm;
		b /= lcm;
		if (!good(b)) cout << "impossible" << endl;
		else {
			int tmp = 0;
			while (a < b) {
				a *= 2;
				tmp++;
			}
			cout << tmp << endl;
		}
	}
	return 0;
}