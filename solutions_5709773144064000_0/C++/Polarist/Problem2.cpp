#include "Problem2.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <assert.h>
#include <list>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;


long double findCost(long double rate, long double cost, long double extraCookies, long double totalNeeded, long double elapsed = 0){
	long double noBuyTime = elapsed + totalNeeded / rate;
	long double buyTime = elapsed + cost / rate + totalNeeded / (rate + extraCookies);

	// if buying one is beneficial, recurse
	if (buyTime < noBuyTime) return min(buyTime, findCost(rate + extraCookies, cost, extraCookies, totalNeeded, elapsed + cost / rate));
	else return noBuyTime;
}

long double solveProblem(long double cost, long double  extraCookies, long double totalNeeded){
	return findCost(2.0, cost, extraCookies, totalNeeded);
}




int main(int argc, char ** argv){
	ifstream in("problem2.in");
	ofstream out("problem2.out");
	int count = 0;
	in >> count;
	cout << count;

	long double cost, extraCookies, totalNeeded;

	for (int i = 0; i < count; i++){
		// Get inputs
		in >> cost >> extraCookies >> totalNeeded;

		auto answer = solveProblem(cost, extraCookies, totalNeeded);
		out << fixed;
		out << "Case #" << i + 1 << ": " << setprecision(7) << answer << endl;
	}


	return 0;
}