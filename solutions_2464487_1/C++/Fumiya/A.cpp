#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = acos(-1.0);

bool valid(long long r, long long c, long long n){
	// sum 2r-1+4*i = (2r-1)*n + 2*n*(n+1) = n*(2r+2n+1)
	// (r+2*i+1)^2 - (r+2*i)^2 = 2*r+4*i+1 = (2*r+1)*n+2*n*(n-1) 
	return n*(2*r+2*n-1) <= c;
}

int main(){
	int TEST; cin >> TEST;
	for(int test=1;test<=TEST;test++){
		long long r, c; cin >> r >> c;
		long long L = 1, R = 2;
		while(valid(r, c, R)) L *= 2, R *= 2;
		while(R-L > 1){
			long long mid = (L+R)/2;
			if(valid(r, c, mid)) L = mid;
			else                 R = mid;
		}
		printf("Case #%d: %lld\n", test, L);
	}
}
