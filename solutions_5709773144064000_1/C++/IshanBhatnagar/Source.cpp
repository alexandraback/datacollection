#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll	MOD = 1000000007LL;
const double PI = 2*acos(0);

long double solve(double c, double f, double x)
{
	long double time;
	long double rate;

	rate = 2.0;
	time = 0.0;

	while(time+c/rate+x/(rate+f) < time+x/rate){
		time += c/rate;
		rate += f;
	}

	return time + x/rate;
}

int main(void)
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios_base::sync_with_stdio(false);
	long double c, f, x;

	int t, i;
	cin >> t;

	for(i=1; i<=t; ++i)
	{
		cin >> c >> f >> x;
		cout << "Case #" << i << ": " << fixed << setprecision(7) << solve(c, f, x) << endl;
	}

	return 0;
} 