/* Round 1C
 * Problem A
 * intrepid
 */
#include <cassert>
#include <iostream>
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

bool doTest()
{
	double C, F, X;
	cin >> C >> F >> X;
	if ( ! cin.good() )
		return false;
	
	bool goal_met = false;
	double cur_rate = 2.0;
	double time_taken = 0.0;
	while ( ! goal_met )
	{
		double time_to_goal = X / cur_rate;
		double time_to_purchase = C / cur_rate;
		double time_if_purchase = time_to_purchase + X / ( cur_rate + F );
		
		if ( time_if_purchase < time_to_goal )
		{   // Buy some more rate!
			cur_rate += F;
			time_taken += time_to_purchase;
		}
		else
		{   // We are done!
			time_taken += time_to_goal;
			goal_met = true;
		}
	}
	
	cout << time_taken;
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(7);
	int runs;
	cin >> runs;
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
