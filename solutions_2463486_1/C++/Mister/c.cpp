#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
long long L[100005];
int D[105], li;
bool ispal(long long x) {
	int di = 0;
	while(x) {
		D[di++] = x%10;
		x /= 10;
	}
	for(int i=0;i<di/2;++i)
		if(D[i] != D[di-1-i]) return 0;
	return 1;
}
int count(long long a) {
	a = (long long)sqrt(a);
	int num = upper_bound(L,L+li,a) - L;
	return num;
}
int main() {
	int T;
	scanf("%d",&T);
	for(long long i=1;i<=10000000;++i) {
		if(!ispal(i)) continue;
		long long ii = i*i;
		if(ispal(ii)) L[li++] = i;
	}
	for(int cn=1;cn<=T;++cn) {
		long long a,b;
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: %d\n",cn,count(b) - count(a-1));
	}
}
