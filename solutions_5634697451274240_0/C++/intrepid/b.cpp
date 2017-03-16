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

void flip(vector<int>& v, int pos)
{
	vector<int> orig(pos);
	for (size_t i = 0; i < orig.size(); ++i)
		orig[i] = !v[i];
	copy(orig.rbegin(), orig.rend(), v.begin());
}

bool doTest()
{
	string s;
	cin >> s;
	vector<int> v(s.size());
	for (size_t i = 0; i < s.size(); ++i)
		v[i] = (s[i] == '+');
	const int N = s.size();
	
	int flips = 0;
	
	while (true) {
		if (v[0]) {
			int bp = 1;
			while (bp < N && v[bp]) ++bp;
			if (bp == N) break;
			flip(v, bp);
			++flips;
		}
		else {
			int bm = N;
			while(bm > 0 && v[bm-1]) --bm;
			if (bm == 0) break;
			flip(v, bm);
			++flips;
		}
	}
	
	cout << flips;
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
