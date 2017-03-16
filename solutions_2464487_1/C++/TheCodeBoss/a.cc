/*
  Google Code Jam 2013
  Round 1A, Problem A
  Coded by Michael Oliver
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

int main() {
	int num_cases;
	cin >> num_cases;
	for (int i=1; i <= num_cases; i++) {
		ll r, t;
		cin >> r >> t;
		ll n = 0;
		while (n*(2*n+2*r-1) <= t) {
			n+=10000;
		}
		n-=10000;
		while (n*(2*n+2*r-1) <= t) {
			n++;
		}
		n--;
		cout << "Case #" << i << ": " << n << endl;
	}
	return 0;
}
