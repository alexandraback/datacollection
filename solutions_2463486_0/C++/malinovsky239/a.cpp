#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = int(1e7);

vector<LL> seq;

bool pal(LL a) {
	vector<int> dig;
	while (a) {
		dig.pb(a % 10);		
		a /= 10;
	}
	bool ok = 1;
	for (int i = 0; i < sz(dig); i++) {
		if (dig[i] != dig[sz(dig) - i - 1]) {
			ok = 0;
			break;
		}
	}

	return ok;
}

int main() {
	for (int i = 1; i <= N; i++) {
		if (pal(i) && pal(LL(i) * i)) {
			seq.pb(LL(i) * i);			
			cerr << LL(i) * i << endl;
		}
//		if (i % int(1e5) == 0)
//			cerr << i / int(1e5) << endl;
	}
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		LL a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int j = 0; j < sz(seq); j++)
			if (seq[j] >= a && seq[j] <= b) 
				cnt++;
		printf("Case #%d: %d\n", i + 1, cnt);
	}

	return 0;
}
