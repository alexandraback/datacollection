// GoogleCodeJam_2013_1Round.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int _tmain(int argc, char* argv[])
{
	ifstream in;
	ofstream out;

	int iPro;
	int k;

	double i;
	
	double r,t;
	double res;

	//in.open("input.txt");
	in.open("A-small-attempt0.in");
	out.open("out.text");

	
	in >> iPro;

	for ( k=1; k<=iPro; k++)
	{
		in >> r >> t;

		res = 0;

		for ( i=r; ;i+=2)
		{
			t -= (1+2.0*i);
			if ( t<0 )
			{
				cout << setprecision(20) << res << "/" << t << "/" << t+(1+2.0*i)<<  "/" << i << endl;
				break;
			}
			else res++;
		}

		// output start

		out << "Case #" << k << ": " << setprecision(20) << res << endl;

	}



	return 0;
}

