#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

bool palindrome(string a){
	for(size_t i = 0; i < a.size()/2; ++i) {
		if (a[i] != a[a.size()-1-i]) return false;
	}
	return true;
}

int main(){
	int tcase;
	char in[102];
	
	std::vector<long long> V;
	for(long long i = 1; i*i <= 100000000000000LL; ++i) {
		sprintf(in,"%lld", i);
		if (palindrome(in)){
			long long sqr = i*i;
			sprintf(in,"%lld", sqr);
			if (palindrome(in)){
				// cout << i << " " << sqr << endl;	
				V.push_back(sqr);
			}			
		}
	}
	cin >> tcase;	
	
	for(size_t casen = 0; casen < tcase; ++casen) {
		long long A, B;
		cin >> A >> B;
		// cout << A << " " << B << endl;		
		size_t toA = (std::lower_bound(V.begin(), V.end(), A) - V.begin());
		size_t toB = (std::lower_bound(V.begin(), V.end(), B+1) - V.begin());	
		// cout << toA << " " << toB << endl;
		cout << "Case #" << casen + 1 << ": ";
		cout << toB - toA << endl;
		
	}
	

	return 0;
}