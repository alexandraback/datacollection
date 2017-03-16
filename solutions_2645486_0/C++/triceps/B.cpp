#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

__int64 solve( __int64 E, __int64 R, __int64 e, __int64 c, const vector<__int64>& v )
{
	if ( c == v.size() ) {
		return 0;
	}

	__int64 ret = 0;
	for ( size_t i = 0; i <= e; i++ ) {
		auto g = i*v[c] + solve(E, R, min(E,e-i+R), c+1, v);
		ret = max(ret,g);
	}
	return ret;
}

int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ ) {
		__int64 E, R, N;
		cin >> E >> R >> N;
		vector<__int64> v(N);
		for ( auto i = 0; i < N; i++ ) {
			cin >> v[i];
		}
        printf( "Case #%d: %lld\n", t, solve(E,R,E,0,v) );
    }
    return 0;
}
