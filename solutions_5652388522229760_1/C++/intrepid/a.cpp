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

int DecimalAndBits(LU a)
{
	int r = 0;
	while (a > 0) {
		int d = a % 10;
		r |= (1 << d);
		a /= 10;
	}
	return r;
}

bool doTest()
{
	LU seen = 0;
	LU x, a;
	cin >> x;
	a = x;
	seen |= DecimalAndBits(a);
	for (int i = 0; i < 101 && seen != 0x3FF; ++i) {
		a += x;
		seen |= DecimalAndBits(a);
	}
	
	if (seen == 0x3FF) {
		cout << a;
	}
	else {
		cout << "INSOMNIA";
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
