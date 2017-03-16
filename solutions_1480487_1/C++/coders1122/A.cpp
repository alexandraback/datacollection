#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 210
int A[MAXN];
int sum;
int N;
#define eps 1e-8
inline bool check(int idx, double val)
{
	// cout << "Checking " << idx << " with val " << val << endl;
	double score = A[idx] + val * sum;
	double csum = val;
	for(int i=1;i<=N;i++) {
		if(i == idx) continue;
		double f = (score - A[i]) / sum;
		f = max(f, 0.0);
		csum += f;
	}
	if(csum > 1.0) return false;
	else return true;
}
inline double search(int idx)
{
	double lo = 0, hi = 1.0;
	double mid;
	int iters = 5000;
	
	while(iters--)
	{
		// if(fabs(lo - hi) < eps) break;
		mid = (lo + hi) / 2.0;
		// cout << "lo: " << lo << " mid: " << mid << " hi: " << hi << endl;
		if(check(idx, mid)) lo = mid;
		else hi = mid;
	}
	if(check(idx, lo)) return lo;
	if(check(idx, mid)) return mid;
	return hi;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out2", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int cases=1;cases<=T;cases++) {
		scanf("%d", &N);
		sum = 0;
		for(int i=1;i<=N;i++) {
			scanf("%d", &A[i]);
			sum += A[i];
		}
		printf("Case #%d:", cases);
		for(int i=1;i<=N;i++) {
			double f = search(i);
			printf(" %.6lf", f*100);
		}
		printf("\n");
	}
	return 0;
}
