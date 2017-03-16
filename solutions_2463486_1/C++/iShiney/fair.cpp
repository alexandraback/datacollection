#include <cstdio>
#include <cstring>
#include <iterator>

using namespace std;

char mynum[100];
int T;
int ftree[10000010];
long long a, b;

int getsum(long long i) {
	int sum =0;
	for(;i;i-=i&-i) {
		sum += ftree[i];
	}
	return sum;
}

long long bsearch_lower() {
	long long low = 1, high = 10000010;
	while(low < high) {
		long long mid = (low+high)/2;
		if (mid*mid >= a) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

long long bsearch_upper() {
	long long low = 1, high = 10000010;
	while(low < high) {
		long long mid = (low+high)/2;
		if (mid*mid <= b) {
			low = mid + 1;
		} else {
			high = mid; 
		}
	}
	return low - 1;
}

int calcme() {
	long long lower = bsearch_lower(), upper = bsearch_upper();
	return getsum(upper) - getsum(lower-1);
}

void addval(long long i) {
	for(;i<=10000000;i+=i&-i)
		ftree[i]++;
	return;
}

bool is_pali(long long i) {
	sprintf(mynum, "%lld", i);
	int len = strlen(mynum);
	for(int i=0; i<len/2; i++) {
		if (mynum[i] != mynum[len-1-i])
			return false;
	}
	return true;
}

int main() {
	freopen("fair.in", "r", stdin);
	for(long long i=1; i<=10000000; i++) {
		if (is_pali(i) && is_pali(i*i)) {	
			addval(i);
		}
	}
	scanf("%d", &T);
	for(int asdf=1; asdf<=T; asdf++) {	
		scanf("%lld%lld", &a, &b);
		printf("Case #%d: %d\n", asdf, calcme());
	}

	return 0;
}
