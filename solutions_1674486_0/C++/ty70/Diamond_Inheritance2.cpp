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

int n;
set<int> node1[1005];
set<int> node2[1005];
bool used[1005][1005];

bool dfs (int s, int t )
{
	if (s == t ) return true;

//	for (int i = 0; i < n; i++ ){
	set<int>::iterator it = node1[s].begin();
	for (; it != node1[s].end(); it++ ){
		int i = (*it);
		if (!used[s][i] ){
			used[s][i] = true;
			if (dfs (i, t ) ) return true;
			used[s][i] = false;
		} // end if
	} // end for

	return false;
}

bool is_diamond (int s, int t )
{
	memset (used, false, sizeof (used ) );
	bool found1 = false, found2 = false;
	if (dfs (s, t ) ) found1 = true;
	if (dfs (s, t ) ) found2 = true;

	return (found1 && found2 );
}


int main()
{
//	cut here before submit 
//	freopen ("testcase.DI", "r", stdin );
	freopen ("A-small-attempt3.in", "r", stdin );
	int t;
	cin >> t;
	for (int Case = 1; Case <= t; Case++ ){
//		memset (node, false, sizeof (node ) );
		cin >> n;
		rep (i, n ){ 
			node1[i].clear();
			node2[i].clear();
		} // end rep

		rep (from, n ){
			int in;
			cin >> in;
			rep (j, in ){
				int to;
				cin >> to;
				to--;
				node1[from].insert (to );
				node2[to].insert (from );
			} // end rep
		} // end rep
		vector<int> cand_from, cand_to;
		cand_from.clear();
		cand_to.clear();

		rep (i, n ){
			if (node1[i].size() > 1 ){
				cand_from.push_back (i );
			} // end if
			if (node2[i].size() > 1 ){
				cand_to.push_back (i );
			} // end if
		} // end rep

		bool found = false;
		rep (i, cand_from.size() )
		rep (j, cand_to.size() )
			if (cand_from[i] != cand_to[j] && is_diamond (cand_from[i], cand_to[j] ) ){
				found = true;
				break;
			} // end if
		cout << "Case #" << Case << ": " << (found == true ? "Yes" : "No" ) << endl;
	} // end loop

//	cout << res << endl;	
		
	return 0;
}
