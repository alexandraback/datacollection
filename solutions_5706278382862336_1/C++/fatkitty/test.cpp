#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>

using namespace std;

void getNums(string s, long long& p, long long& q) {
	int index = s.find('/');
	p = atol(s.substr(0,index).c_str());
	q = atol(s.substr(index+1,s.size()-index-1).c_str());
}

long long gcd(double num, double den){
    if(den == 0){
       return num;
    }
	return gcd(den, fmod(num, den));
}

bool poss(int years, long long P, long long Q) {
	return 1.0 <= pow(2,years)*1.0*P/Q;
}

int main(int argc, char **argv) 
{ 
	long long T, P, Q;
	cin >> T;

	string frac;
	for(long long i=0; i<T; i++) {
		cin >> frac;
		getNums(frac, P, Q);

		if(P==1 && Q==1) {
			cout << "Case #" << i+1 << ": 0" << endl;
			continue;
		}

		long long temp = gcd(P, Q);
		long long p = Q/temp;
		if((p&(p-1))!=0) {
			cout << "Case #" << i+1 << ": impossible" << endl;
			continue;
		}
		P = P/temp;
		Q = Q/temp;

		// binary search between 1 and 40
		int ans = INT_MAX;
		int hi, lo, mid;
		hi = 40; lo = 1;
		while(lo<=hi) {
			mid = (hi+lo)/2;
			if(poss(mid,P,Q)) {
				ans = mid;
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		if(ans == INT_MAX) cout << "Case #" << i+1 << ": impossible" << endl;
		else cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
