#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 10000005
using namespace std;
int m, n;
bool isp(long long n) {
	vector<int> d;
	while(n > 0) {
		d.push_back(n % 10);
		n /= 10;
	}
	for(int i = 0, j = d.size() - 1; i < j; ++i, --j) {
		if(d[i] != d[j])
			return false;
	}
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	vector<long long> v;
	for(int i = 1; i < MAXN; ++i) {
		if(isp(i) && isp((long long)i * i)) { 
			//printf("%d->%I64d\n", i, (long long)i * i);
			v.push_back((long long)i * i);
		}
	}
	for(int cs = 1; cs <= T; ++cs) {
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		int begin = lower_bound(v.begin(), v.end(), a) - v.begin() - 1;
		int end = upper_bound(v.begin(), v.end(), b) - v.begin() - 1;
		//printf("%d %d\n", begin, end);
		printf("Case #%d: %d\n", cs, end - begin);
	}
	return 0;
}
