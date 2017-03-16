#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;
int S;
int p;
vector<int> t;
int memo[101][101];

inline int tripletScoreCount( int total, bool surprising)
{
	int a = total / 3;
	int r = total % 3;
	int ret = 0;
	
	if ( surprising ) {
		switch ( r ) {
			case 0 :
				if ( a-1 >= 0 && a + 1 >= p ) ret = 1;
				break;
			case 1 :
				if ( a-1 >= 0 &&  a + 1 >= p ) ret = 1;
				break;
			case 2 :
				if ( a + 2 >= p ) ret = 1;
				break;
		}
	} else {
		switch ( r ) {
			case 0 :
				if ( a >= p ) ret = 1;
				break;
			case 1 :
				if ( a + 1 >= p ) ret = 1;
				break;
			case 2 :
				if ( a + 1 >= p ) ret = 1;
				break;
		}
	}
	return ret;
}

inline int recur(int s, int u)
{
	if ( u < 0 ) return 0;
	if ( memo[s][u] != -1 ) return memo[s][u];

	int ret1 = 0;
	
	if ( s <= u+1 ) {
		ret1 += tripletScoreCount( t[u], false);
		ret1 += recur( s, u-1);
	}
	
	int ret2 = 0;
	if ( s > 0 ) {
		ret2 += tripletScoreCount( t[u], true);
		ret2 += recur( s-1,u-1);
	}

	memo[s][u] = ret1 > ret2 ? ret1 : ret2;
	return memo[s][u];
//	return ret1 > ret2 ? ret1 : ret2;
}

int solve()
{
	for ( int i = 0; i <= S; i++ ) {
		for ( int j = 0; j < t.size(); j++ ) {
			memo[i][j] = -1;
		}
	}

	return recur( S, t.size()-1);
}

int main(int argc, char* argv[])
{
	int	casenum;
	cin >> casenum;
	for ( int i = 1; i <= casenum; i++ ) {
		cin >> N >> S >> p;
		t.clear();
		for ( int j = 0; j < N; j++ ) {
			int ti;
			cin >> ti;
			t.push_back(ti);
		} 
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
