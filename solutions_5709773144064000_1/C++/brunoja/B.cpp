#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

ld C, F, X;

ld solve() // lets hope this thing converges ;)
{
	ld best = 1/0.0, res = 0;
	for (int f = 0;;++f)
	{
		res += C/(2+f*F);
		ld tmp = res+X/(2+(f+1)*F);
		if (tmp > best) break;
		best = tmp;
	}
	best = min(best, X/2);
	return best;
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	cout << setprecision(10) << fixed;
	
	for (int q = 1; q <= t; ++q)
	{
		cout << "Case #" << q << ": ";
		cin >> C >> F >> X;
		cout << solve() << endl;
	}
}

