#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

long double getTime(vector<long double> time, vector<long double> pos, long double accel, long double hill)
{
	long double
		mypos = 0.0,
		carpos = 0.0,
		mytime = 0.0,
		lastVel = 0.0,
		lastStep = 0.0;
	
	for (unsigned int x = 0; x < time.size(); ++x)
	{
		if (time[x] == 0.0)
		{
			carpos = pos[x];
			continue;
		}
		
		long double
			dt = time[x] - lastStep,
			carmove = pos[x] - carpos,
			carvel = carmove / dt;
		
		if (pos[x] < hill)
		{
			long double
				myvel = lastVel + accel * dt,
				mymove = dt * (lastVel + 0.5 * accel * dt);
			
			if (mymove <= carmove)
			{
				mypos += mymove;
				mytime = time[x];
				lastVel = myvel;
			}
			else
			{
				mypos += carmove;
				mytime = time[x];
				lastVel = MAX(carvel, sqrt(2.0 * carmove / accel));
			}
		}
		else
		{
			long double
				cartimetobottom = (hill - carpos) / carvel;
			
			long double
				mymove = hill - mypos,
				mytimetobottom = (-lastVel + sqrt(lastVel * lastVel + 2.0 * accel * mymove)) / accel;
			
			mytime += MAX(cartimetobottom, mytimetobottom);
			mypos = hill;
			break;
		}
		
		lastStep = time[x];
		carpos = pos[x];
	}
	
	if (mypos < hill)
	{
		mytime += sqrt(2.0 * (hill - mypos) / accel);
	}
	
	return mytime;
}

int main()
{
	ifstream input;
	input.open("input.in");
	
	unsigned int count = 0;
	input >> count;
	
	vector< vector<long double> > results;
	results.reserve(count);
	
	for (unsigned int x = 0; x < count; ++x)
	{
		long double d = 0.0;
		
		input >> d;
		
		int
			n = 0,
			a = 0;
		
		input >> n >> a;
		
		vector<long double>
			time,
			pos,
			accels;
		
		time.reserve(n);
		pos.reserve(n);
		accels.reserve(n);
		
		for (unsigned int y = 0; y < n; ++y)
		{
			long double temp;
			input >> temp;
			time.push_back(temp);
			input >> temp;
			pos.push_back(temp);
		}
		
		for (unsigned int y = 0; y < a; ++y)
		{
			long double temp;
			input >> temp;
			accels.push_back(temp);
		}
		
		vector<long double> times;
		times.reserve(a);
		for (unsigned int y = 0; y < a; ++y)
		{
			times.push_back(getTime(time, pos, accels[y], d));
		}
		
		results.push_back(times);
	}
	
	input.close();
	
	ofstream output;
	output.open("output.out");
	
	for (unsigned int x = 0; x < results.size(); ++x)
	{
		output << "Case #" << x + 1 << ":" << endl;
		for (unsigned int y = 0; y < results[x].size(); ++y)
			output << results[x][y] << endl;
	}
	
	output.close();
}
