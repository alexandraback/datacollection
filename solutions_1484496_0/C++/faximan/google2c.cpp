//
//  google2c.cpp
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
#include <math.h>

#define EPS 1e-10

using namespace std;

long long a[501];

map<long long, vector<long long> >m;

int main()
{
	int t;
	cin >> t;
	
	

	for(int tt = 1; tt <= t; tt++)
	{
		bool ok = false;
		cout << "Case #" << tt <<":" << endl;
		m.clear();
		
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		vector<bool> v(20, false);
		for(int l = 0; l < pow(2,20); l++)
		{
		for(vector<bool>::iterator it = v.begin(); it != v.end(); ++it)
		{
			if(*it)
				*it = false;
			else{
				*it = true;
				break;
			}
		}
			long long sum = 0;
			vector<long long> cur;
			for(int i = 0; i < 20; i++)
				if(v[i])
				{
					sum += a[i];
					cur.push_back(a[i]);
				}
			if(m.count(sum))
			{
				ok = true;
				vector<long long> aa = m[sum];
				for(int i = 0; i < aa.size(); i++)
				{
					if(i) cout << " ";
					cout << aa[i];
				}
				cout << endl;
				for(int i = 0; i < cur.size(); i++)
				{
					if(i) cout << " ";
					cout << cur[i];
				}
				cout << endl;
				break;
			}
			else
				m[sum] = cur;
		}
				
		if(!ok)
			cout << "Impossible" << endl;
		
	}
		return 0;
}