#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
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

double calc( vector<int> _v, double x ) {
	sort( _v.begin(), _v.end() );
	int n = _v.size();

	vector<double> v;
	for( int i = 0; i < n; ++i ) {
		v.push_back( _v[i] );
	}
	while(x > 1.0E-9) {
		int inc = 0;
		for( int i = 1; i < n; ++i ) {
			if( fabs(v[i]-v[i-1]) > 1.0E-9 ) {
				int m = i;
				double diff = v[i]-v[i-1];
				if( diff*m > x ) {
					for( int j = 0; j < i; ++j ) {
						v[j] += x/m;
					}
					x = 0;
					inc = 1;
					break;
				} else {
					for( int j = 0; j < i; ++j ) {
						v[j] = v[i];
					}
					x -= diff*m;
					inc = 1;
					break;
				}
			}
		}
		if( inc == 0 ) {
			for( int i = 0; i < n; ++i ) {
				v[i] += x/n;
			}
			x = 0;
		}
	}
	for( int i = 1; i < n; ++i ) {
		assert( v[i] >= v[i-1] );
	}
	return v[0];
}

int main() {
	int cases;
	int s[208];

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n;
		cin >> n;
		int sum = 0;
		for( int i = 0; i < n; ++i ) {
			cin >> s[i];
			sum += s[i];
		}
		cout << "Case #" << caseid << ":";
		for( int i = 0; i < n; ++i ) {
			double u = 0;
			double v = 1;
			vector<int> tmp;

			for( int j = 0; j < n; ++j ) {
				if( j == i ) continue;
				tmp.push_back(s[j]);
			}

			for( int j = 0; j < 1000; ++j ) {
				double w = (u+v)/2.0;
				if( s[i] + w*sum >= calc( tmp, (double)sum-w*sum ) ) {
					v = w;
				} else {
					u = w;
				}
			}

			printf( " %.14f", u*100 );
		}
		cout << endl;
	}
}
