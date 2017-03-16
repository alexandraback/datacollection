#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<set>
#include<vector>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

vector < vector < int > > to;
vector< char > tome;

char used[1024];

bool dfs(int numb)
{
	used[numb] = 1;
	for (int i=0; i<to[numb].size(); i++)
	{
		int next = to[numb][i];
		if (used[next] == 1)
			return true;
		else
		{
			bool res = dfs(next);
			if (res)
				return true;
		}
	}
	return false;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif


	int T;

	cin >> T;

	for (int cs = 1; cs <= T; cs ++)
	{

		printf("Case #%d:\n",cs);

		double D;
		int N,A;
		cin >> D >> N >> A;

		vector< pair<double,double> >other(N); // time - dist

		for (int i=0; i<N; i++)
		{
			cin >> other[i].first;
			cin >> other[i].second;
		}

		while (other.size() >= 2 && other[other.size()-1].second > D && other[other.size()-2].second > D)
			other.pop_back();

		if (other[other.size() - 1].second > D)
		{
			if (other.size() > 1)
			{
				double newdist = D - other[other.size() - 2].second;
				double timepast = other[other.size() - 1].first - other[other.size() - 2].first;
				double newtime = timepast * ( newdist / ( other[other.size() - 1].second - other[other.size() - 2].second ) );
				other[other.size()-1].first = newtime;
				other[other.size()-1].second = D;
			}
			else
			{
				other[0].first = 0;
				other[0].second = D;
			}
		}


		vector<double>acc(A);

		for (int i=0; i<A; i++)
			cin >> acc[i];

		for (int i=0; i<A; i++)
		{
			double currpos = 0;
			double time = 0;
			double speed = 0;
			if (other[0].second > 0)
			{
				time = sqrt(2. * other[0].second / acc[i] );
				speed = acc[i] * time;
				currpos = other[0].second;
			}
			for (int j=1; j<other.size(); j++)
			{
				double dist = other[j].second - other[j-1].second;
				double needtime = ( -speed + sqrt(speed*speed + 2. * acc[i] * dist) ) / acc[i];
				if (time + needtime >= other[j].first)
				{
					currpos = other[j].second;
					speed = speed + acc[i] * needtime;
					time = time + needtime;
				}
				else
				{
					double needtime = other[j].first - time;
					double t2 = sqrt( 2. * ( dist - speed * needtime ) / acc[i] );
					speed = speed + acc[i] * t2;
					time = time + needtime;
					currpos = other[j].second;
				}
			}
			printf("%.8lf \n",time);
		}

	}

	return 0;
}