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


int main()
{
	int T;
	scanf ("%d", &T );
	for (int t = 1; t <= T; t++ ){
		int res = 0;
		int A, B, K; cin >> A >> B >> K;
		for (int a = 0; a < A; a++ ){
			for (int b = 0; b < B; b++ ){
				int curr = a & b;
				if (K > curr ){
					res++;
//					cerr << "a: " << a << " b: " << b << " a & b: " << curr << endl;
				} // end if
			} // end for
		} // end for
		output (t, res );
	} // end for 
	
		
	return 0;
}
