#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

typedef long long LL;

typedef pair<LL,LL> PI;
typedef pair<int, char> Q;

const char* mult_table[4] = { "1ijk", "i1kj", "jk1i", "kji1" };

int sign_table[4][4] = { { 1, 1, 1, 1 }, { 1, -1, 1, -1 }, { 1, -1, -1, 1 }, {
		1, 1, -1, -1 } };

int ind(char x) {
	switch (x) {
	case '1':
		return 0;
	case 'i':
		return 1;
	case 'j':
		return 2;
	case 'k':
		return 3;
	}
	assert(0);
	return -1;
}

Q operator*(const Q& a, const Q& b) {
	Q x; // = a*b
	x.first = a.first * b.first * sign_table[ind(a.second)][ind(b.second)];
	x.second = mult_table[ind(a.second)][ind(b.second)];
	return x;
}

Q inv(const Q& a) {
	if (a.second == '1')
		return a;
	return Q(-a.first, a.second);
}

Q ppow( Q a, LL exp ) {
	if( exp == 0 ) return Q(1,'1');

	Q acc = Q(1,'1');
	while( exp > 1 ) {
		if( (exp % 2) == 1 ) {
			acc = acc * a;
		}
		a = a*a;
		exp /= 2;
	}
	return a * acc;
}

bool possible(const string& s, LL X ) {
	int n = s.size();

	Q s_prod = Q(1,'1');
	for( int i = 0; i < n; ++i ) {
		s_prod = s_prod * Q(1,s[i]);
	}

	Q s_prodX = ppow( s_prod, X );
	if( s_prodX.first != -1 || s_prodX.second != '1' ) return false;

	Q qi = Q(1,'i');
	Q qk = Q(1,'k');
	Q x;
	set<Q> iter_start;
	PI ipos = PI(-1,-1);
	PI kpos = PI(-1,-1);

	// find i
	x = Q(1,'1');
	iter_start.clear();
	for( LL iter = 0; iter < X; ++iter ) {
		if( iter_start.find( x ) != iter_start.end() ) return false;
		iter_start.insert( x );
		//
		for( int i = 0; i < n; ++i ) {
			x = x * Q(1,s[i]);
			if( x == qi ) {
				ipos = PI(iter,i);
				break;
			}
		}
		if( ipos.first != -1 ) break;
	}

	// find k (backwards)
	x = Q(1,'1');
	iter_start.clear();
	for( LL iter = X-1; iter >= 0; --iter ) {
		if( iter_start.find( x ) != iter_start.end() ) return false;
		iter_start.insert( x );
		//
		for( int i = n-1; i >= 0; --i ) {
			x = Q(1,s[i]) * x;
			if( x == qk ) {
				kpos = PI(iter,i);
				break;
			}
		}
		if( kpos.first != -1 ) break;
	}

	return ipos < kpos;
}

int main() {
	int cases;

	cin >> cases;

	for (int caseid = 1; caseid <= cases; ++caseid) {
		cout << "Case #" << caseid << ": ";
		LL L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		if (possible(s,X))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

