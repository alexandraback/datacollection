using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const double EPS = 1e-7;
const int MAXN = 2001010;
int memo[MAXN];

bool is_fair(long long a){
	vector <int> digits, digits_rev;
	while (a > 0){
		digits.push_back(a % 10);
		a /= 10;
	}
	digits_rev = digits;
	reverse(digits_rev.begin(), digits_rev.end());
	return digits == digits_rev;
}

int main(){
	int count = 0;
	memo[0] = 0;
	for (int a = 1; a < MAXN; ++a){
		if (is_fair(a) and is_fair(1LL * a * a)){
			//printf("%d * %d = %lld is fair and square\n", a, a, 1LL * a * a);
			count++;
		}
		memo[a] = count;
	}
	
	int cases;
	cin >> cases;
	for (int run = 1; run <= cases; ++run){
		long long a, b;
		cin >> a >> b;
		int first = ceil(sqrt(a - EPS));
		int last = floor(sqrt(b + EPS));
		assert( 1LL * (first-1) * (first-1) < a and a <= 1LL * first * first );
		assert( 1LL * last * last <= b and b < 1LL * (last+1) * (last+1) );
		
		if (last >= MAXN) last = MAXN - 1;
		
		printf("Case #%d: %d\n", run, memo[last] - memo[first-1]);
		
	}
    return 0;
}
