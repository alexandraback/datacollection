/// gcc version 4.8.2 with -std=c++11

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iterator>

#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

#include <string>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#include <tuple>
#include <initializer_list>

#include <cmath>

// Boost library can be retrieved from http://www.boost.org/
// 1.52 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

#define RNG(v) (v).begin(), (v).end()
#define REP(v, e) for(UI v = 0U; v < e; ++v)
#define REP_(v, s, e) for(UI v = s; v < e; ++v)
#define REPV(v, e) for(v = 0; v < e; ++v)
#define REPV_(v, s, e) for(v = s; v < e; ++v)

using namespace std;

template<class Integer>
inline boost::iterator_range< boost::range_detail::integer_iterator<Integer> >
IR(Integer first, Integer  last)
{ return boost::irange(first, last); }

void c1(int R, int M)
{
	cout << "c" << endl;
	for(int i: IR(0, R - M - 1)) cout << "." << endl;
	for(int i: IR(0, M)) cout << "*" << endl;
}

void r1(int C, int M)
{
	cout << "c";
	for(int i: IR(0, C - M - 1)) cout << ".";
	for(int i: IR(0, M)) cout << "*";
	cout << endl;
}

void c2(int R, int M)
{
	if(2*R-M == 1) {
		cout << "c*\n";
		for(int i: IR(0, R - 1)) cout << "**" << endl;
	} else if(M % 2 || 2*R-M == 2) {
		cout << "Impossible" << endl;
	} else {
		cout << "c.\n";
		for(int i: IR(0, R - M/2 - 1)) cout << ".." << endl;
		for(int i: IR(0, M/2)) cout << "**" << endl;
	}
}

void r2(int C, int M)
{
	if(2*C-M == 1) {
		cout << "c";
		for(int i: IR(0, M/2)) cout << "*";
		cout << endl;
		cout << "*";
		for(int i: IR(0, M/2)) cout << "*";
		cout << endl;
	} else if(M % 2 || 2*C-M == 2) {
		cout << "Impossible" << endl;
	} else {
		cout << "c";
		for(int i: IR(0, C - M/2 - 1)) cout << ".";
		for(int i: IR(0, M/2)) cout << "*";
		cout << endl;
		cout << ".";
		for(int i: IR(0, C - M/2 - 1)) cout << ".";
		for(int i: IR(0, M/2)) cout << "*";
		cout << endl;
	}
}

char result[50][50];
void gen(int R, int C, int M)
{
	for(int i: IR(0,R)) { for(int j: IR(0,C)) { result[i][j] = '*'; } }
	if(R*C - M == 1) { // nothing to do
	} else if(R*C - M == 4) {
		result[0][0] = result[0][1] = result[1][0] = result[1][1] = '.';
	} else if(R*C - M == 6) {
		result[0][0] = result[0][1] = result[1][0] = result[1][1] = result[2][0] = result[2][1] = '.';
	} else if(R*C - M == 8) {
		for(int i: IR(0,3)) { for(int j: IR(0,3)) { result[i][j] = '.'; } }
		result[2][2] = '*';
	} else if(R*C - M < 9) {
		cout << "Impossible" << endl;
		return;
	} else if(M <= (R-2)*(C-2)) {
		for(int i: IR(0,2)) { for(int j: IR(0,C)) { result[i][j] = '.'; } }
		for(int i: IR(0,R)) { for(int j: IR(0,2)) { result[i][j] = '.'; } }
		int MM = (R-2)*(C-2);
		for(int i: IR(2, R)) {
			if(M == MM) break;
			for(int j: IR(2,C)) {
				result[i][j] = '.'; --MM;
				if(M == MM) break;
			}
		}
	} else {
		for(int i: IR(0,3)) { for(int j: IR(0,3)) { result[i][j] = '.'; } }
		int MM = R*C - 9;
		if(((R*C-M) % 2) == 0) {
			result[2][2] = '*'; ++MM;
		}
		for(int i: IR(3, R)) {
			if(M == MM) break;
			for(int j: IR(0, 2)) {
				result[i][j] = '.';
			}
			MM-=2;
		}
		for(int i: IR(3, C)) {
			if(M == MM) break;
			for(int j: IR(0, 2)) {
				result[j][i] = '.';
			}
			MM-=2;
		}
	}
	result[0][0] = 'c';
	for(int i: IR(0,R)) { for(int j: IR(0,C)) { cout << result[i][j]; } cout << endl; }
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		int R, C, M; cin >> R >> C >> M;
		cout << "Case #" << casenum+1 << ":" << endl;
		if(R == 1) { r1(C, M); }
		else if(C == 1) { c1(R, M); }
		else if(R == 2) { r2(C, M); }
		else if(C == 2) { c2(R, M); }
		else { gen(R, C, M); }
	}

	return 0;
}
