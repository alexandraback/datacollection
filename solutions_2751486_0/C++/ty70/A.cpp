#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;


void output (int t, int res )
{
	printf ("Case #%d: %d\n", t, res  );
}

bool is_vowels (char c )
{
	return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' );
}

int calc (string s, int n )
{
	int m = s.length();
	int ans = 0;
	rep (i, m ){
		for (int j = 1; j <= m-i; j++ ){
			string t = s.substr (i, j );
//			cout << "t: " << t << endl;
			int curr = 0;
			int res = 0;
			bool found = false;
			rep (k, t.length() ){
				if (!is_vowels (t[k] ) ){
					curr++;
				}else{
					res = max (res, curr );
					curr = 0;
				} // end if
			} // edn rep
			if (curr != 0 )
				res = max (res, curr );
//			cout << "res: " << res << endl;
			if (res >= n ) ans++;
		} // end for
	} // end rep

	return ans;				
}

int main()
{
	freopen ("A-small-attempt0.in", "r", stdin );
//	freopen ("input.A", "r", stdin );
	int CASE;
	scanf ("%d", &CASE );

	for (int t = 1; t <= CASE; t++ ){
		string s = "";
		int n;
		cin >> s >> n;
	
		int res = calc (s, n );
		
		output (t, res );
	} // end for
		
		
	return 0;
}
