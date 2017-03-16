// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// We have an infinite strip of paper divided into a sequence of cells.
// All of the cells are initially white.
// We place a robot onto one of the cells.
// Each time the robot stands on a cell, it paints the cell red.
// 
// 
// 
// You are given an int N.
// The robot will now make N steps.
// In each step, the robot will move either one cell to the left or one cell to 
// the right, with equal probability.
// All random choices made by the robot are mutually independent.
// 
// 
// 
// Compute and return the expected number of red cells at the end.
// 
// 
// DEFINITION
// Class:RedPaint
// Method:expectedCells
// Parameters:int
// Returns:double
// Method signature:double expectedCells(int N)
// 
// 
// NOTES
// -Your return value must have an absolute or a relative error at most 10^(-9).
// 
// 
// CONSTRAINTS
// -N will be between 0 and 500, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 0
// 
// Returns: 1.0
// 
// No movement. At the end there is a single red cell: the one with the robot.
// 
// 1)
// 1
// 
// Returns: 2.0
// 
// One step. The robot will choose a random direction and move. There will be 
// exactly two red cells: the one where it started and the one where it ended.
// 
// 
// 2)
// 2
// 
// Returns: 2.5
// 
// In the third step the robot will color a third cell red with probability 1/2. 
// Hence, the expected number of red cells is 0.5*2 + 0.5*3 = 2.5.
// 
// 
// 3)
// 4
// 
// Returns: 3.375
// 
// 
// 
// END CUT HERE
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size()

int A;
int B;
int K;

long long cache[34][2][2][2];

int bit(unsigned int A, int pos)
{
	return (bool)(A & (1U << (31-pos)));
}


long long solve(int pos, bool eqA, bool eqB, bool eqK)
{
	long long &result = cache[pos][eqA][eqB][eqK];

	if (result != -1)
		return result;

	result = 0;

	if (pos == 32)
		return result = 1LL;

	for(int a = 0; a < 2; ++a)
	{
		if (eqA && a == 1 && bit(A, pos) == 0)
			continue;

		for(int b = 0; b < 2; ++b)
		{
			if (eqB && b == 1 && bit(B, pos) == 0)
				continue;

			int k = a&b;

			if (eqK && k == 1 && bit(K, pos) == 0)
				continue;

			bool eqA_new = eqA && (bit(A, pos) == a);
			bool eqB_new = eqB && (bit(B, pos) == b);
			bool eqK_new = eqK && (bit(K, pos) == k);

			if (eqA_new && a == 1 && bit(A, pos) == 0)
				printf("");


			result += solve(pos+1, eqA_new, eqB_new, eqK_new);
		}
	}


	return result;
}


void solve(int test)
{
	memset(cache, -1, sizeof(cache));
	long long res = solve(0, true, true, true);

	cout << "Case #" << test << ": " << res << "\n";
	cerr << "Case #" << test << ": " << res << "\n";
}


int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	REP(t, T)
	{
		cin >> A >> B >> K;
		--A;
		--B;
		--K;

		solve(t+1);
	}
}
