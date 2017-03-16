//
//  googleB.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cassert>

#define EPS 1e-5

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		int n, s, p;
		cin >> n >> s >> p;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			int cur;
			cin >> cur;
			double div = cur/3.0;
			if(div > p-1 + EPS)
				ans++;
			else if(div + EPS > p-2 + (2/3.0) && p>= 2 && s)
			{
				s--;
				ans++;
			}
		}
		//	assert(s==0);
		cout << ans << endl;
	}
	return 0;
}