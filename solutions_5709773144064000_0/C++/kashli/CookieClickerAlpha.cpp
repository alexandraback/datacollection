/*
 * CookieClickerAlpha.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: Ganesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#define iter(i, N) for(long long i=0 ; i<N ; i++)

using namespace std;

int main()
{
	long long cases;
	cin>>cases;
	cout<<fixed;
	iter(q, cases)
	{
		double C, F, X;
		cin>>C>>F>>X;
		double cps = 2;
		double time = 0;
		while(X/cps > C/cps + X/(F+cps))
		{
			time+=C/cps;
			cps+=F;
		}
		time+=X/cps;
		cout<<"Case #"<<q+1<<": "<< std::setprecision(7)<<time<<"\n";
	}
	return 0;
}

