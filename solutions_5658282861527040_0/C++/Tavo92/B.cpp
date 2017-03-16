#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

typedef long long tint;

int T;

int main(){
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);

	cin >> T;
	forn(t, T) {
		printf("Case #%i: ", t+1);
		int a, b, k;
		cin >> a >> b >> k;

		int ret = 0;
		forn(i, a) forn(j, b) if((i&j) < k)
			ret++;
		cout << ret << endl;
	}

	return 0;
}
