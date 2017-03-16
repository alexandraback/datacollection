//#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

long long e,r,n;
vector<long long> v;
vector< vector < long long > > w;

long long ries(long long en, long long kde) {
	if (kde == n) return 0;
	if (w[en][kde] != -1) return w[en][kde];
	long long maxi = 0;
	int i = 0;
	if (e == r) i = en;
	for (; i<=en; ++i) {
		long long e1 = en-i+r;
		if (e1>e) e1 = e;
		maxi = max(maxi, ries(e1, kde+1) + v[kde]*i);
	}
	w[en][kde] = maxi;
	return maxi;
} 

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 0; t<T; ++t) {
		v.clear();
		scanf("%lld %lld %lld", &e, &r, &n);
		vector < long long > y (n, -1);
		w.clear();
		w.resize(e+2, y);
		for (int i = 0; i<n; ++i) {
			long long a;
			scanf("%lld", &a);
			v.push_back(a);
		}	
		printf("Case #%d: %lld\n", t+1, ries(e, 0));
	}
	return 0;
}
