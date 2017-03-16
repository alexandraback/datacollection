/* Round 1B
 * Problem A
 * intrepid
 */
#include <cassert>
#include <cmath>

#include <algorithm>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using namespace chrono;

random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(1,100);
auto myRand = bind(distribution, generator);

typedef long double LD;
typedef int64_t LI;
typedef uint64_t LU;

const LD kPi = acos(static_cast<LD>(-1));

LU lupow(LU base, LU exp)
{
	LU r = 1;
	while (exp) {
		if (exp & 1)
			r *= base;
		exp >>= 1;
		base *= base;
	}
	return r;
}

class MemPow
{
public:
	MemPow(LU base, LU max) : base_(base), mem_(max+1, 0) { }
	
	LU operator()(LU exp)
	{
		if (mem_[exp] > 0)
			return mem_[exp];
		LU r = lupow(base_, exp);
		mem_[exp] = r;
		return r;
	}
	
private:
	LU base_;
	vector<LU> mem_;
};

bool doTest()
{
	int K, C, S;
	cin >> K >> C >> S;
	
	LI need = K / C + ((K%C==0)?0:1);

	if (need > S) {
		cout << "IMPOSSIBLE";
	}
	else if (C == 1) {
		for (int i=0; i < K; ++i)
			cout << i + 1 << ' ';
	}
	else {
		LU T0 = 1;
		LU N = 0;
		MemPow mempow(K,C);
		for (LI i = max(C - K, 0); i <= C - 2; ++i) {
			T0 += (C - i - 1) * mempow(i);
		}
		for (LI i = 0; i <= C - 1; ++i) {
			N += mempow(i);
		}
		N *= C;
		cout << T0 << ' ';
		LU T = T0;
		for (LI i = 0; i < need - 2; ++i) {
			T += N;
			cout << T << ' ';
		}
		if (need > 1)
			cout << mempow(C) + 1 - T0;
	}
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(7);
	int runs;
	cin >> runs;
	if ( ! cin.good() )
	{
		cerr << "Error reading runs!\n" << endl;
		return 0;
	}
	for (int run=1; run <= runs; ++run) {
		cout << "Case #" << run << ": ";
		
		if ( !doTest() )
		{
			cerr << "Test case failed!" << endl;
			break;
		}
		
		cout << "\n";
	}
	if ( !cin.good() ) cerr << "Error reading!\n" << endl;
	
	return 0;
}
