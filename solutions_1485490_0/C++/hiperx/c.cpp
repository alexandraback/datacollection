#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int64;

int nt0, nt;
int n, m;

int64 a[8], a_[8], b[128], b_[128];
int ta[8], tb[128];

int64 simulate(int x1, int x2) {
	for(int i=0 ; i<n ; i++)
		a_[i] = a[i];
	for(int i=0 ; i<m ; i++)
		b_[i] = b[i];

	int64 sum = 0LL;
	for(int i=0, j=0 ; j<m ; j++) {
		if(ta[i] == tb[j]) {
			int64 aux = min(a_[i], b_[j]);
			a_[i] -= aux;
			b_[j] -= aux;
			sum += aux;
		}
		if(j == x1) i=1;
		else {
			if(j == x2) i=2;
			else continue;
			if(i >= n) return sum;
			if(ta[i] == tb[j]) {
				int64 aux = min(a_[i], b_[j]);
				a_[i] -= aux;
				b_[j] -= aux;
				sum += aux;
			}
		}
		if(i >= n) return sum;
		if(ta[i] == tb[j]) {
			int64 aux = min(a_[i], b_[j]);
			a_[i] -= aux;
			b_[j] -= aux;
			sum += aux;
		}
		if(j == x2) i=2;
		else continue;
		if(i >= n) return sum;
		if(ta[i] == tb[j]) {
			int64 aux = min(a_[i], b_[j]);
			a_[i] -= aux;
			b_[j] -= aux;
			sum += aux;
		}
	}
	return sum;
}

int main() {
	scanf(" %d", &nt0);
	for(nt = 1 ; nt <= nt0 ; nt++) {
		printf("Case #%d: ", nt);

		scanf(" %d %d", &n, &m);
		for(int i=0 ; i<n ; i++)
			scanf(" %lld %d", &a[i], &ta[i]);

		for(int i=0 ; i<m ; i++)
			scanf(" %lld %d", &b[i], &tb[i]);
			
		int64 ans = 0LL;
		for(int i=0 ; i<=m ; i++)
			for(int j=i ; j<=m ; j++) {
				int64 k = simulate(i,j);
				if(k > ans) ans = k;
			}
		
		printf("%lld\n", ans);
	}

	return 0;
}
