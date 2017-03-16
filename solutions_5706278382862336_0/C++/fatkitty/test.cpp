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

void getNums(string s, int& p, int& q) {
	int index = s.find('/');
	p = atoi(s.substr(0,index).c_str());
	q = atoi(s.substr(index+1,s.size()-index-1).c_str());
}

int gcd(double num, double den){
    if(den == 0){
       return num;
    }
	return gcd(den, fmod(num, den));
}

bool poss(int years, int P, int Q) {
	return 1 <= pow(2,years)*1.0*P/Q;
}

int main(int argc, char **argv) 
{ 
	int T, P, Q;
	cin >> T;

	string frac;
	for(int i=0; i<T; i++) {
		cin >> frac;
		getNums(frac, P, Q);

		int temp = gcd(P, Q);
//		cout << "Fraction in lowest terms: " << P/ temp << "/" << Q/ temp << endl;
		int p = Q/temp;
		if((p&(p-1))!=0) {
			cout << "Case #" << i+1 << ": impossible" << endl;
			continue;
		}

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
