/* CodeJam 2014
 * Round 1B
 * Problem B
 * intrepid
 */
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <numeric>
#include <memory>
#include <limits>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

default_random_engine generator(system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution(1,100);
auto myRand = bind(distribution, generator);

#if 0 
bool large()
{
	int A, B, K;
	cin >> A >> B >> K;
	if ( ! cin.good() ) return false;
	
	int uA = min(A, K);
	int uB = min(B, K);
	
	int P = uA * B + uB * ( A - uA );
	
	cout << P;	
}
#endif

bool doTest()
{
	int A, B, K;
	cin >> A >> B >> K;
	if ( ! cin.good() ) return false;
	
	int t = 0;
	for (int ai = 0; ai < A; ++ai)
	{
		for (int bi = 0; bi < B; ++bi)
		{
			if ( (ai & bi) < K )
				++t;
		}
	}
	cout << t;
	
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
