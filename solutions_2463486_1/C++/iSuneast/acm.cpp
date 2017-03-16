#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define LOWBIT(v) ((v)&(-(v)))
#define KTH_BIT(v, k) ((v) & (1<<(k)))
#define MERGE_BIT(v, k) ((v) | (1<<(k)))

#define MAXN 10000000
#define MOD 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

LL num[MAXN];
int n;
char buf[30];

bool pa(LL v) {
	sprintf(buf, "%lld", v);
	for(int i=0, j=strlen(buf)-1; i<j; ++i, --j) {
		if(buf[i] != buf[j]) {
			return false;
		}
	}
	return true;
}

void Init() {
	n = 0;
	for(LL i=1; i<=MAXN; ++i) {
		if(pa(i) && pa(i*i)) {
			num[n++] = i*i;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-large-1.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-large-1.out", "w", stdout);
#endif
	
	Init();
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		LL a, b;
		scanf("%lld %lld", &a, &b);
		printf("Case #%d: %lld\n", cas, upper_bound(num, num+n, b) - lower_bound(num, num+n, a));
	}

	return 0;
}
