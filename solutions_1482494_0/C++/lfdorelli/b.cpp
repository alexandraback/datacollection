#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <queue>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

std::vector<pii> A;
int t, n;

int solve(int m) {
	int accumul = 0;
	int myStars = 0;

	int non_two = m-n;
	int n2 = 0;

	int usedOne[n+1];
	memset(usedOne, 0, sizeof usedOne);

	for(int i = 0; n2 != non_two && i < n; i++) {
		if(A[n-1-i].S <= myStars) { 
			myStars++, n2++;
			usedOne[n-1-i] = 1;
		}
	}

	if(n2 != non_two) return 0;

	for(int i = 0; i < n; i++) {
		if(A[i].F <= myStars) {
			if(usedOne[i]) myStars++;
			else myStars += 2;
		} else return 0;
	}
	return 1;
}

int main (void)
{
	
	int caso = 1;

	cin >> t;
	while(t--) {
		cin >> n;

		printf("Case #%d: ", caso++);
		
		int a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			A.pb( mp(b, a));
		}

		sort(A.begin(), A.end());
		
		int lo = n, hi = 2*n; 

		while(hi - lo > 1 ) {
			int mid = (hi + lo) / 2;
			if(solve(mid)) hi = mid;
			else lo = mid;
		}

		int pode = 0;
		if(solve(lo)) pode = lo;
		else if(solve(hi)) pode = hi;
	
		if(pode) printf("%d\n", pode);
		else printf("Too Bad\n");

		A.clear();
	}

	return 0;
}