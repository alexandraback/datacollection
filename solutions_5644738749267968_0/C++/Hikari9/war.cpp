#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

int t, n, tc;
set<double, greater<double> > a, b;
set<double> c, d;

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		a.clear();
		b.clear();
		c.clear();
		d.clear();
		for( int i=0; i<n; ++i ){
			double x;
			cin >> x;
			a.insert(x);
			c.insert(x);
		}
		
		for( int i=0; i<n; ++i ){
			double x;
			cin >> x;
			b.insert(x);
			d.insert(x);
		}
		cout << "Case #" << ++tc << ": ";
		int points = 0;
		for( set<double, greater<double> >::iterator it = a.begin(); it != a.end(); ++it ){
			set<double, greater<double> >::iterator it2;
			it2 = b.lower_bound( *it );
			if( it2 == b.end() ) continue;
			b.erase( it2 );
			points++;
		}
		cout << points;
		points = 0;
		for( set<double>::iterator it = c.begin(); it != c.end(); ++it ){
			set<double>::iterator it2;
			it2 = d.lower_bound( *it );
			if( it2 == d.end() ){
				it2 = d.begin();
				points++;
			}
			d.erase( it2 );
		}
		cout << " " << points << endl;
	}
}
