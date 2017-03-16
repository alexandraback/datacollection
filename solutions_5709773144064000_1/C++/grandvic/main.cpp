#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
 
using namespace std;

double waitTime(double r, double x)
{
	return x/r;
}

void solve()
{
	double r = 2.0, c, f, x; cin>>c>>f>>x;
	double time = 0.0;
	double best_time = waitTime(r, x);
	while(true)
	{
		double waitWin  = waitTime(r, x);
		double waitFarm = waitTime(r, c); r+=f;
		double waitWinWithFarm = waitFarm + waitTime(r, x);
		if(waitWin<waitWinWithFarm)
		{
			cout<<(time + waitWin)<<endl;
			break;
		}
		else
		{
			time += waitFarm;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(7);
		cout<<"Case #"<<t<<": ";
		solve();
	}
 
	return 0;
} 