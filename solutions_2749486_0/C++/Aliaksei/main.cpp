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

int bins(vector<int> &v, int val)
{
	int lo = 0, hi = v.size(), med;
	while(lo + 1 < hi)
	{
		med = (lo + hi) / 2;
		if(med < val)
		{
			lo = med;
		}
		else
		{
			hi = med;
		}
	}
	return lo;
}



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int st;
	cin >> st;	

	for(int steps = 0; steps< st; steps++)
	{
		int x, y;
		cin >> x >> y;
		printf("Case #%d: ", steps+1);
		if(x > 0)
		{
			for(int i = 0; i < x; ++i)
				printf("WE");
		}
		else if(x < 0)
			{
				for(int i = 0; i < -x; ++i)
				printf("EW");
			}
		if(y > 0)
		{
			for(int i = 0; i < y; ++i)
				printf("SN");
		}
		if(y < 0)
		{
			for(int i = 0; i < -y; ++i)
				printf("NS");
		}
		printf("\n");
				
	}

}