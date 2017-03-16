#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<sstream>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 10000 + 50;

long long E, R, N;
long long v[maxn];
long long a[maxn];
int p[maxn];
bool b[maxn];
int ntest;

bool cmp(const int &a, const int &b) {
	return v[a] > v[b];
}

int main() {
	
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("B-small-attempt4.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%lld%lld%lld", &E, &R, &N);
		for(int i=1; i<=N; i++) {
			scanf("%lld", &v[i]);
		}
		
		if(R > E) R = E;

		for(int i=1; i<=N; i++) p[i] = i;
		sort(p+1, p+N+1, cmp);

		for(int i=1; i<=N; i++) {
			a[i] = R;
		}
		a[1] = E;

		long long answer = 0;

		for(int i=1; i<=N; i++) {
			int pos = p[i];
			long long value = v[pos];
			long long total = 0;
			long long step = E;
			while(pos >= 1 && step > 0) {
				long long spend = min(step, a[pos]);
				total += spend;
				a[pos] -= spend;
				step -= R;
				pos--;
			}
			answer += total * value;
		}

		printf("Case #%d: %lld\n", test, answer);
	}
	return 0;
}
