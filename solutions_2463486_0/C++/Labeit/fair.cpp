#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

vector<ull> fairsqr;
const ull SIZE = 2500000;

bool isPalin(ull x) {
	stack<ull> s;
	queue<ull> q;
	while( x != 0 ) {
		s.push(x%10);
		q.push(x%10);
		x /= 10;
	}
	while(!s.empty() ) {
		if( s.top() != q.front() ) {
			return false;
		}
		s.pop();
		q.pop();
	}
	return true;
}

int T;
int A,B;

int main() {
	for( ull i = 1; i < SIZE; i++) {
		if( isPalin(i) ) {
			if( isPalin(i*i) ) {
				fairsqr.push_back(i*i);
			}
		}
	}
	cin>>T;
	for( int t = 0; t < T; t++) {
		cin>>A>>B;
		cout<<"Case #"<<t+1<<": "<< upper_bound(fairsqr.begin(), fairsqr.end(), B) - lower_bound(fairsqr.begin(), fairsqr.end(), A)<<endl;
	}
	return 0;
}
