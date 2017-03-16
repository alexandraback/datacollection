/*
ID : thewise1
PROG: 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
	long double pi = 3.14159265358979;
	ofstream cout ("AS.out");
        ifstream cin ("A-small-attempt0.in");

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		
	long double r, t;
	r = 0;
	t = 0;
	cin >> r;
	cin >> t;

	long int scount = 1;
	t = t*pi;
	while (true)
	{
		t -= 2*pi*r+(2*(double)scount-1)*pi;
		//cout << t << endl;
		if (t < 0)
		{
			cout << "Case #" << i+1 << ": " << (scount-1)/2 << endl;
			break;
		}
		scount += 2;
	}
	
	}

	return 0;	
}
