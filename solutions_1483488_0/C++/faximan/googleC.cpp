//
//  googleC.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int GetNumberOfDigits (int i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		int a, b;
		cin >> a >> b;
		long long ans = 0;
		int digits = GetNumberOfDigits(a);
		
		for (int n = a; n <= b; n++) 
		{
			for (int m = n+1; m <= b; m++) 
			{
				for (int power = 1; power <= digits; power++) 
				{
					int curLength = pow(10, power);
					int move = n % curLength;
					int newn = move * pow(10, digits-power) + n/curLength;
					if(newn == m)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}