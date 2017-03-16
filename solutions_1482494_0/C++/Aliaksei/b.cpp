#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.second<=b.second) return false;
	//if(a.first==b.first&&a.second<=b.second) return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin>>n;	
	for (int step=0; step<n; ++step)
	{
		printf("Case #%d: ", step+1);

		int k;
		cin>>k;
		int a, b;
		vector <pair<int, int> > g(k);
		for (int i=0; i<k; ++i)
		{
			scanf("%d%d", &a, &b);
			g[i]=make_pair(a, b);
		}
		sort(g.begin(), g.end(), comp);
		vector <int> used(k);
		int count=0;
		int step=0;
		for (int l=0; l<2*k; ++l){
			for (int ll=0; ll<k; ++ll)
			for (int m=0; m<k;  ++m)
			{
				if (used[m]!=2&&g[m].second<=count)
					if (used[m]==0) used[m]=2, count+=2, step+=1;
					else used[m]=2, count+=1, step+=1;
			}
			int mind=-1;
			for (int m=0; m<k; ++m)
			{
				if (used[m]==0&&g[m].first<=count)
				{used[m]=1, count+=1, step+=1; break;}
			}
		}
		if (count!=2*k)
		{
			printf("Too Bad\n");
			
		}
		else
			printf("%d\n",step);

	}

}
