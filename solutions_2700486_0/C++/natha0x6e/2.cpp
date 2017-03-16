#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>

typedef long long ll;
typedef double dub;

using namespace std;

int glob;
ll getHeight(ll x)
{
	ll low = 0;
	ll high = x;
	while(low < high)
	{
		ll mid = high - (high - low) / 2;
		if(mid * (mid + 1) / 2 > x)
		{
			high = mid - 1;
		}
		else
		{
			low = mid;
		}
	}
	glob = low;
	return (low + 1) / 2;
}

dub one(ll drops, ll target)
{
	dub res = 0.0;
	ll c = 1;
	for(int i = drops;i > target;i--)
	{
		c *= i;
	}
	for(int i = 1;i <= drops - target;i++)
	{
		c /= i;
	}
	dub div = 1.0;
	for(int i = 0;i < drops;i++)
	{
		div *= 2;
	}
	res = c / div;
	return res;
}
dub prob(ll drops, dub target)
{
	dub res = 0.0;
	for(int i = target;i <= drops;i++)
	{
		res += one(drops, i);
	}
	return res;
}

void runTest()
{
	ll numd;
	cin >> numd;
	ll x, y;
	cin >> x >> y;
	
	ll numHigh = getHeight(numd);
	ll in = (((numHigh * 2) * (numHigh * 2 - 1)) / 2);
	ll onout = numd - in;
	ll dist = abs(x) + y;
	cout.precision(10);
	cerr  << endl;
	cerr << "dist " << dist << " numHigh " << numHigh << " onout " << onout<< "  in " << in << "  glob " << glob << endl;
	if(dist < numHigh * 2)
	{
		//cerr << "too close" << endl;
		cout << "1.0" << endl;
	}
	else if(dist > numHigh * 2)
	{
		//cerr << "too far" << endl;
		cout << "0.0" << endl;
	}
	else
	{
		dub res = 0.0;
		ll gar = onout - 2 * numHigh;
		
			if(gar < 0)
			{
				gar = 0;
			}
		cerr << "gar " << gar << " y " << y << endl;
		ll drops = onout - 2 * gar;
		ll target = y - gar + 1;
		if(y < gar)
		{
			//cerr << "too low" << endl;
			res = 1.0;
		}
		else if(target > drops)
		{
			//cerr << "too high" << endl;
			res = 0.0;
		}
		else
		{
			cerr << "drops " << drops << " target " << target << endl;
			if(target <= drops)
			{
				res = prob(drops, target);
			}
		}
		
		cout << res << endl;
	}
}


int main(int argc, const char * argv[])
{
	(void) argc;
	(void) argv;
	int numTests;
	cin >> numTests;
	srand(time(NULL));
	
	for(int i =0;i < numTests;i++)
	{
		cout << "Case #" << i + 1 << ": ";
		runTest();
	}
}
