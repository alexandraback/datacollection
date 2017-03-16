#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <queue>
using namespace std;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define in(x,s) (s.find(x)!=s.end())

typedef long long int64;
typedef vector<int> VI;
typedef vector<string> VS;

const double eps = 1E-12;
const double pi=acos(-1.0); 


ifstream fin("c.in");
ofstream fout("c.out");

int T;

struct Car
{
	double pos;
	double speed;
	bool lane;
};
class CruiseControl
{
public:
	double T;
	int N;
	CruiseControl()
	{
		T = 0.0;
		fin>>N;
		char ch;
		for(int i=0;i<N;i++)
		{
			fin>>ch>>cars[i].speed>>cars[i].pos;
			if(ch == 'L')
			{
				cars[i].lane = false;

			}
			else
				cars[i].lane = true;

		}
	}
	Car cars[60];
	void lineup()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			if(cars[i].pos>cars[j].pos)
			{
				Car tCar = cars[i];
				cars[i] = cars[j];
				cars[j] = tCar;
			}
		}

		//switch to the left lane if possible
		for(int i=0;i<N;i++)
			if(cars[i].lane)
			{
				//behind car occupies left lane
				if(i>0 && cars[i-1].pos + 5.0 > cars[i].pos+eps)
					continue;
				if(i+1<N && cars[i].pos + 5.0 > cars[i+1].pos + eps)
					continue;
				cars[i].lane = false;
			}
	}
	bool checkCollision()
	{
		//if two cars connect and are both on right, collision
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
				if(cars[i].lane && cars[j].lane && cars[i].speed>cars[j].speed && cars[i].pos+eps+5.0>cars[j].pos)
					return true;
			}

		//if two cars connect and are both on left, and the quicker one could not switch to right, collision
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
				if(!cars[i].lane && !cars[j].lane && cars[i].speed>cars[j].speed && cars[i].pos+eps+5.0>cars[j].pos)
				{
					//switch first
					cars[i].lane = true;

					for(int k=max(i-2,0);k<i;k++)
					{
						if(cars[k].lane && cars[k].pos + 5.0 > cars[i].pos+eps)
							return true;

					}
					for(int k=i+1;k< min(i+3, N);k++)
					{
						if(cars[k].lane && cars[i].pos + 5.0 > cars[k].pos + eps)
							return true;
					}
				}
					
			}
			for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
				if(cars[i].lane && cars[j].lane && cars[i].speed>cars[j].speed && cars[i].pos+eps+5.0>cars[j].pos)
					return true;
			}
		return false;
	}
	double run()
	{
		while(true)
		{
			lineup();
			bool col = checkCollision();
			if(col)
			{
				return T;
			}
			bool good = forward();
			if(good)
				return -1.0;

		}

	}
	bool forward()
	{
		double minT = 1000000.0;
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(cars[i].speed > cars[j].speed && cars[i].pos + 5.0 < cars[j].pos - eps)
				{
					double touch = (cars[j].pos - cars[i].pos - 5.0)/(cars[i].speed - cars[j].speed);
					minT = min(minT, touch);
				}
			}
		}
		if (minT >=  1000000.0-eps)
			return true;

		for(int i=0;i<N;i++)
		{
			cars[i].pos = cars[i].pos + cars[i].speed*minT;
		}
		T += minT;
		return false;
	}

};
int main()
{
	
	fin>>T;
	
	
	for(int c=1;c<=T;c++)
	{
		CruiseControl* cc = new CruiseControl();
		double res = cc->run();
		if(res < 0.0-eps)
		{
					cout<<"Case #"<<c<<": Possible"<<endl;
		fout<<"Case #"<<c<<": Possible"<<endl;
		}
		else
		{
		
		fout.setf(ios::fixed,ios::floatfield);	 


	
		cout<<"Case #"<<c<<": "<<res<<endl;
		fout<<"Case #"<<c<<": "<<setprecision(7)<<res<<endl;
	

		}
		
	}
	return 0;
}
