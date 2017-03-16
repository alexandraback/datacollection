#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit
#include <cstdio>	// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>	// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int a[505];
int n;
set<int> sum[2000005];

void disp_array (int s, int t, int T )
{
	cout << "Case #" << T << ": " << endl;

	for (int i = 0; i < n; i++ ){
		if (s & (1<<i) ){
			cout << a[i] << ' ';
		} // end if
	} // end for
	cout << endl;
	for (int i = 0; i < n; i++ ){
		if (t & (1<<i) ){
			cout << a[i] << ' ';
		} // end if
	} // end for
	cout << endl;
}

int main()
{
//	cut here before submit 
//	freopen ("testcase.ES", "r", stdin );
	freopen ("C-small-attempt1.in", "r", stdin );
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; Case++ ){
		memset (a, 0, sizeof (a ) );
		rep (i, 2000005 )
			sum[i].clear();

		cin >> n;
		rep (i, n ){
			cin >> a[i];
		} // end rep

		bool found = false;
		for (int i = 1; i < 1<<n; i++ ){
			int curr = 0;
			for (int j = 0; j < n; j++ ){
				if (i&(1<<j) ){
					curr += a[j];
				} // end if
			} // end for
			if (sum[curr].empty() ){
				sum[curr].insert (i );
			}else{
				disp_array (*sum[curr].begin(), i, Case );
				found = true;
				break;
			} // end if 
		} // end for

		if (!found ){
			cout << "Case #" << Case << ": " << endl;
			cout << "Impossible" << endl;
		} // end if			
	} // end loop

//	cout << res << endl;	
		
	return 0;
}
