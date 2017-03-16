//
//  google2a.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-05-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

#define EPS 1e-10

using namespace std;

int s[201];
int sorted[201];

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		printf("Case #%d:", tt);
		
		int x = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> s[i];
			sorted[i] = s[i];
			x += s[i];
		}
		sort(sorted,sorted+n);
		for (int i = 0; i < n; i++) 
		{
			int current = s[i];
			double k = 0.5;
			double step = 0.25;
			while(true)
			{
				if(k < EPS || k > 1-EPS)
					break;
				
				double newscore = current + x*k;
				
				double missing = 0;
				int j = 0;
				while(j < n && sorted[j] < newscore)
					missing += newscore - sorted[j++];
				
				missing -= newscore - current;
				if(fabs(missing - x*(1-k)) < EPS)
					break;
				else if(missing - x*(1-k) > 0)
					k -= step;
				else
					k += step;
				step /= 2;
			}
			
			
			printf(" %.9f", k*100);
		}
		printf("\n");		
	}
	return 0;
}