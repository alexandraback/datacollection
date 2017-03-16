#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

struct level
{
public:
	int one, two;
	int index;

};

bool cmp(const level& a, const level& b)
{
	return a.two < b.two;
}



int main()
{
	int t;
	cin>>t;
	for(int casenum = 1; casenum <= t; casenum++)
	{
		int n;
		cin>>n;
		level data[n];
		for(int i = 0; i<n;i++)
		{
			cin>>data[i].one>>data[i].two;
			data[i].index = i;
		}
		sort(data, data+n, cmp);

		int taken[n];

		for(int i = 0; i<n;i++)
			taken[i] = 0;

		int twopointer = 0;

		int curstars = 0, ans = 0;
		bool fail = false;
		while(twopointer < n)
		{
			if(data[twopointer].two <= curstars)
			{
				if(taken[data[twopointer].index] == 0)
					curstars += 2;
				else
					curstars++;
				ans++;
				taken[data[twopointer].index] = 2;
				twopointer++;
			}
			else
			{
				bool found = false;
				for(int i = n-1; !found && i>=twopointer; i--)
				{
					if(taken[data[i].index] == 0 && data[i].one<=curstars)
					{
						taken[data[i].index] = 1;
						found = true;
						ans++;
						curstars++;
					}
				}
				if(!found)
				{
					fail = true;
					break;
				}
			}
		}


		if(fail)
			cout<<"Case #"<<casenum<<": Too Bad"<<endl;
		else
		{
			assert(curstars == 2*n);
			cout<<"Case #"<<casenum<<": "<<ans<<endl;
		}
	}
	return 0;
}
