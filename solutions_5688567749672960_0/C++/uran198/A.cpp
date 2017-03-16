#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

long long reverse(long long N) {
	vector<int> ns;
	while(N){
		ns.push_back(N%10);
		N /=10;
	}
	for(int i=0; i<(int)ns.size();++i) {
		N = N*10 + ns[i];
	}
	return N;
}

long long r[20];
long long tn[20];

long long c(vector<int> ns) {
	int n = ns.size();
	int t = n/2;
	long long res = 0;
	for(int i=t-1; i >= 0; --i) {
		res = res*10 + ns[i];
	}
	long long tmp = 0;
	for(int i=t; i< n; ++i) {
		tmp = tmp*10 + ns[i];
	}
	if (res == 1) {
		res = 0;
	}
	return tmp+res;
}

long long c1(vector<int> ns) {
	int n = ns.size();
	int t = n/2;
	long long res = 0;
}

int main() {
	tn[0] = 1;
	for(int i=1; i < 18; ++i) {
		tn[i] = 10*tn[i-1];
	}

	r[1] = 10;
	for(int i=2; i < 18; ++i) {
		int t = i+1;
		r[i] = r[i-1] + tn[(t-1)/2] + tn[t/2] - 1;
	}

	int t;cin>>t;
	for(int K=1;K<=t;++K){
		long long n, tmp; cin>>n;
		long long cnt = 0;
		if (n % 10 == 0) {
			n--;
			cnt++;
		}
		tmp = n;
		int st = 0;
		vector<int> ns;
		while(tmp) {
			st++;
			ns.push_back(tmp%10);
			tmp /= 10;
		}
		st--;
		reverse(ns.begin(), ns.end());
		cnt += r[st] + c(ns);
		printf("Case #%d: %lld\n", K, cnt);
	}
}
