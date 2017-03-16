// GoogleCodeJam_2013_1A_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_VALUE = 10000;

int _tmain(int argc, char* argv[])
{
	ifstream in;
	ofstream out;

	int iPro;
	int k;

	//in.open("input.txt");
	in.open("B-small-attempt3.in");
	//in.open("A-large.in");
	out.open("out.text");
	
	long e,r,n,res;
	long now;
	
	long i,j;


	long value[MAX_VALUE];
	
	in >> iPro;

	for ( k=1; k<=iPro; k++)
	{
		in >> e >> r >> n;

		for (i=0;i<n;i++)
		{
			in >> value[i]; 
		}

		value[n] = 0;

		res = 0;
		now = e;

		// input end

		for (i=0;i<n;)
		{
			long dist=0,spend=0;

			if ( i==n-1)
			{
				res += value[i]*now;
				break;
			}

			for ( j=i+1; j<n;j++)
			{
				spend += r;
				dist++;

				if ( value[i]<value[j])
				{
					if ( now + spend >= e ) 
					{
						res += value[i] * ( spend - e + now );
						i=j;
						now = e;
					}
					else
					{
						now += r;
						i=j;
					}
					break;
				}
				
				if ( spend > e || j==n-1 )
				{
					res += value[i] * now;
					i++;
					now = r;
					break;
				}
			}

			
		}

		// output start

		out << "Case #" << k << ": " << setprecision(20) << res << endl;

	}

	return 0;
}

