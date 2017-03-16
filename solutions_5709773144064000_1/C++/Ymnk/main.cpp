#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

int main()
{
	fstream output_file;
	output_file.open("output.txt");


	int T;
	cin >> T;
	for(int i=0; i<T;i++)
	{
		double C, F, X;
		double cps, total_time, time_needed, time_to_farm;
		bool done = false;
		cin >> C >> F >> X;

		total_time = 0.0;
		cps = 2.0;
		time_needed = X / cps;

		while(!done)
		{
			time_needed = X/cps;
			time_to_farm = C/cps;

			if(time_needed <= time_to_farm + X/(cps+F))
			{
				total_time += time_needed;
				done = true;
			}
			else
			{
				total_time += time_to_farm;
				cps += F;
			}
		}


		output_file << "Case #" << i+1 << ": ";
		output_file << fixed << setprecision(7) << total_time << endl;
	}

	output_file.close();
	return 0;
}