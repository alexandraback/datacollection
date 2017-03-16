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
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> PI;

const int dy[] = { 1, 0, -1, 0 }; 
const int dx[] = { 0, 1, 0, -1 };
const char DIR[] = { 'N', 'E', 'S', 'W' };

void output (int t, string res )
{
	printf ("Case #%d: ", t );
	cout << res << endl;
}

string M[205][205];

int main()
{
	freopen ("B-small-attempt1.in", "r", stdin );
//	freopen ("input.B", "r", stdin );
	int CASE;
	scanf ("%d", &CASE );

	for (int t = 1; t <= CASE; t++ ){
		rep (i, 205 ) rep (j, 205 ){
			M[i][j].clear();
		} // end rep
		int x, y;
		scanf ("%d %d", &x, &y );

		int ox = 100;
		int oy = 100;
		M[oy][ox] = '_';
//		while (M[oy+y][ox+x].empty() ){
		rep (CNT, 50 ){
			rep (i, 205 ){
				rep (j, 205 ){
					if (!M[i][j].empty() ){
						string curr = M[i][j];
						int cl = curr.length();
						rep (k, 4 ){
							int nx = j+cl*dx[k];
							int ny = i+cl*dy[k];
							if (nx < 0 || nx >= 205 || ny < 0 || ny >= 205 ) continue;
							string next = curr + DIR[k];
							if (M[ny][nx].empty() || M[ny][nx] == "_"  || M[ny][nx].length() > next.length() ){
						//		if (!M[ny][nx].empty() ){
						//			cout << "exist: " << M[ny][nx] << endl;
						//		} // end if
								M[ny][nx] = curr + DIR[k];
							} // end if
						} // end rep
					} // end if
				} // end rep
			} // end rep
		} // end while
		
		string ans = M[oy+y][ox+x];
		ans = ans.substr (1 );
//		dfs (0, 0, x, y, 1, "" );
		output (t, ans );
	} // end for
		
		
	return 0;
}
