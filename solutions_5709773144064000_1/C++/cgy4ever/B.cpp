#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

double price, more, want;
double ans;

void solve()
{
	cin >> price >> more >> want;
	ans = 1e10;
	double t = 0;
	double rate = 2;
	for(int i = 1; i <= 100000; i++)
	{
		ans = min(ans, want / rate + t);
		t += price / rate;
		rate += more;
	}
	cout << ans << endl;
	
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(7);
	return MAIN();
}
