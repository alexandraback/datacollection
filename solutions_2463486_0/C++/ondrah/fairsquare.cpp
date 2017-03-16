#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

bool ispalin(long long x)
{
	vector<int> v;
	while(x > 0) {
		v.push_back(x%10);
		x /= 10;
	}

	REP(i, v.size()) {
		if(v[i] != v[v.size()-i-1]) return false;
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(t, T) {
		long long a,b;
		scanf("%lld %lld", &a, &b);
		long long lim = sqrt(b)+1;
		int ans = 0;	
		for(long long i = 1; i <= lim; i++) {
			if(i*i >= a && i*i <= b && ispalin(i*i) && ispalin(i)) {
				ans++;	
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
