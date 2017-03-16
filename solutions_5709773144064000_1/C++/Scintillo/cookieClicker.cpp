#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long double real;
const real initialRate = 2.0;

real solve()
{
	real farmCost, farmValue, target;
	cin >> farmCost >> farmValue >> target;

	real sol1, sol2;
	real rate = initialRate;
	real prep = 0.0;

	do
	{
		sol1 = prep + target / rate;
		sol2 = prep + farmCost / rate;
		prep = sol2;
		rate += farmValue;
		sol2 += target / rate;
	}
	while(sol1 >= sol2);

	return min(sol1, sol2);
}

int main()
{
	cout << setprecision(16);

	int caseCount;
	cin >> caseCount;

	for(int i = 1; i <= caseCount; i++)
	{
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}