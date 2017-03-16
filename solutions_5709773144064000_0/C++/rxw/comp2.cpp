#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream in("in.IN", ifstream::in);
	ofstream out("out.txt", ifstream::out);

	int numTests = 0;
	in >> numTests;

	for (int i = 0; i < numTests; ++i)
	{
		//c = farm cost
		//f = additional rate provided by farms
		//x = winning condition
		//r = current cookie rate
		double c, f, x, r;
		in >> c;
		in >> f;
		in >> x;
		double time = 0;
		double cookies = 0;
		r = 2.0;

		//if time to win is less than time to farm, add time to win and exit
		if(x <= c) {
			time += (x - cookies) / r;
		}
		else {
			while(true) {
				//add time to farm
				time += c / r;

				//time to win without buying farm
				double timeWithoutFarm = (x - c) / r;
				//time to win if you buy a farm
				double timeWithFarm = x / (r + f);

				if(timeWithoutFarm <= timeWithFarm) {
					time += timeWithoutFarm;
					break;
				}
				else {
					//update the rate to include the new purchased farm
					r += f;
				}
			}
		}

		//write to file this case, 7 decimal places
		out << "Case #" << i + 1 << ": " << fixed << setprecision(7) << time << endl;
	}

	return 0;
}