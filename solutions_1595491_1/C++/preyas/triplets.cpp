#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main()
{
	int t, n, s, p, score;
	cin>>t;
	for(int i = 1; i<=t; i++)
	{
		cin>>n>>s>>p;
		int ans = 0;
		for(int j = 0; j<n;j++)
		{
			cin>>score;
			int best = score/3;
			if(score%3)
				best++;
			if(best >=p )
				ans++;
			else if(best < p-1)
				continue;
			else
			{
				if(score == 0)
					continue;
				if(score%3 == 0 || score%3 == 2)
					if(s > 0)
					{
						s--;
						ans++;
					}
			}
		}

		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
