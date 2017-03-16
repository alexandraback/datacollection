#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;


struct field {
	int r, c, h;
	bool operator()( const field& f1, const field& f2 ) const {
		return f1.h > f2.h;
	}
};

int a[100][100];
int b[100][100];
vector<field> fields;

int main(int argc, char** argv) {
	int cases;
	
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		
		cout << "Case #" << caseid << ": ";
		
		fields.clear();
		int rows, cols;
		cin >> rows >> cols;
		for( int r = 0; r < rows; ++r ) {
			for( int c = 0; c < cols; ++c ) {
				a[r][c] = 100;
				cin >> b[r][c];
				
				field f;
				f.r = r;
				f.c = c;
				f.h = b[r][c];
				fields.push_back( f );
			}
		}
		sort( fields.begin(), fields.end(), field() );
		
		for( int i = 0; i < rows*cols; ++i ) {
			field& f = fields[i];
			if( a[f.r][f.c] == f.h ) continue; // nothing to do
			assert( a[f.r][f.c] > f.h );
			
			int ok = 1;
			for( int r = 0; r < rows; ++r ) {
				if( b[r][f.c] > f.h ) {
					ok = 0;
					break;
				}
			}
			if( ok ) {
				for( int r = 0; r < rows; ++r ) {
					a[r][f.c] = min( a[r][f.c], f.h );
				}
				continue;
			}
			
			ok = 1;
			for( int c = 0; c < cols; ++c ) {
				if( b[f.r][c] > f.h ) {
					ok = 0;
					break;
				}
			}
			if( ok ) {
				for( int c = 0; c < cols; ++c ) {
					a[f.r][c] = min( a[f.r][c], f.h );
				}
				continue;
			}
			cout << "NO\n";
			goto nextcase;
		}
		cout << "YES\n";
		nextcase:;
	}
	return 0;
}


	