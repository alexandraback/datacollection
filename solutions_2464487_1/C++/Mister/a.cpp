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
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		long long r,t;
		scanf("%lld%lld",&r,&t);
		long long lo = 1, hi = 1000000000;
		while(lo < hi) {
			long long b = (lo+hi+1)/2;
			if(2*r+2*b-1 <= t/b) lo = b;
			else hi = b-1;
		}
		printf("Case #%d: %lld\n",cn,lo);
	}
}
