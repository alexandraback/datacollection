#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define esta(mask, bit) ((mask & (1<<bit)) != 0)

string str[128];

int main () {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T, result = 0;
	cin >> T;
	
	int a,b,k;
	for( int tc = 1; tc <= T; tc++ ) {
		cin >> a >> b >> k;
		
		result = 0;
		for( int i = 0; i < a; i++ ) {
			for( int j = 0; j < b; j++ ) {
				if( (i&j) < k )
					result++;
			}
		}
		cout << "Case #" << tc << ": " << result << endl;
	}
}
