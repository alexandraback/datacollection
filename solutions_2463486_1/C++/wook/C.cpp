#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define all(v) v.begin(), v.end()

int n,m;
int a[103][103];

#define REP(i, n) for(int i=0; i<(int)(n); ++ i) 
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

bool ispal(long long n) {
	static int s[20] = {0,};
	int k = 0;
	while(n > 0) {
		s[k++] = n % 10;
		n /= 10;
	}
	for(int i = 0, j = k - 1; i < j; i ++, j -- ) {
		if(s[i] != s[j])
			return false;
	}
	return true;
}

vector<long long> P;

long long go(long long A, long long B) {
	return upper_bound(P.begin(), P.end(), B) - lower_bound(P.begin(), P.end(), A);
}

int main () {
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	for(long long i = 1; i <= 10000000; ++ i) {
		if(!ispal(i)) continue;

		long long sq = i * i;
		if(ispal(sq))
			P.push_back(sq);
	}
	int T;
	cin >> T;
	for(int t=1;t<=T;++t) {
		long long A,B;
		cin >> A >> B;
		cout << "Case #" << t << ": " << go(A,B) << endl;
	}
	return 0;
}