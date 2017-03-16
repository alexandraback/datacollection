#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input ("input2.in");
	ofstream output ("answers2.txt");
	output << fixed;
	int t;
	input >> t;
	for( int k = 1; k <= t; ++k )
	{
		double cForFarm, farmBoost, x;
		input >> cForFarm >> farmBoost >> x;
		double baseTime = 0.0;
		double speed = 2.0;
		double current = baseTime + x / speed;
		while( true )
		{
			baseTime += cForFarm / speed;
			speed += farmBoost;
			double bet = baseTime + x / speed;
			if( bet < current )
			{
				current = bet;
			}
			else
			{
				break;
			}
		}
		output << "Case #" << k << ": " << setprecision(7) << current << endl;
	}
	input.close();
	output.close();
}
