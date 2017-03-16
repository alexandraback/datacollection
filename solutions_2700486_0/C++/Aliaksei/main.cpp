#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int st;
	cin >> st;
	vector<int> prepr(30006,0);
	for(int i = 1; i < 30006; ++i)
		prepr[i] = prepr[i-1] + i;
	for(int i = 0; i < 10060; ++i)
		prepr[i+1] = prepr[2*i+1];
	for(int steps = 0; steps< st; steps++)
	{
		long double prob = 0;
		int x, y, n;
		cin >> n >> x >> y;
		int tr = (abs(x) + y) / 2;
		int h = 2*tr;
		int a = y + 1;
		if(prepr[tr+1] >= n && n - prepr[tr] >= a)
		{
			if(a == 2*tr + 1)
			{
				if(prepr[tr+1] == n)
				printf("Case #%d: 1.0\n", steps+1);
				else
					printf("Case #%d: 0.0\n", steps+1);
				continue;
			}
			int t = n - prepr[tr];
			if(t- h >= a)
			{
				printf("Case #%d: 1.0\n", steps+1);
				continue;
			}
			prob = 1;
			long double cnk = 1;
			for(int k = 0; k < t; ++k)				
				prob /= 2.0;
			cnk*=prob;

			int curr = 1;
			for( ; curr <= t - h; ++curr)
			{
				cnk = cnk * (t - curr + 1) / curr;
			}
			prob = cnk;
			for( ; curr < a; ++curr)
			{				
				cnk = cnk * (t - curr + 1) / curr;
				prob+=cnk;
			}
			double prob2= 0;
			for( ; curr <= min(t, h); ++curr)
			{				
				cnk = cnk * (t - curr + 1) / curr;
				prob2+=cnk;
			}
			
			prob = 1 - prob/(prob+prob2);
			printf("Case #%d: %.9llf\n", steps+1, prob);
		}
		else if(n - prepr[tr] < a)
		{
			printf("Case #%d: 0.0\n", steps+1);
		}
		else
		{
			printf("Case #%d: 1.0\n", steps+1);
		}
	}

}