
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream input("C:/users/sebastien/Downloads/B-small-attempt0.in");
//	ifstream input("C:/users/sebastien/Downloads/example.in");
	ofstream output("C:/users/sebastien/Downloads/output.txt");

	output.precision(16);

	int T;
	input >> T;

	for (int test = 1; test <= T; ++test) {
		cout << "test " << test << "\n";
		output << "Case #" << test << ": ";

		double C, F, X;
		input >> C;
		input >> F;
		input >> X;

		double cookies = 0.;
		double cookiesPerSec = 2.;
		double time = 0.;
		double best = 1e300;


		while(time < best) {
			// number of cookies is always 0 at start of loop
			double justClickTime = time + X / cookiesPerSec;
			if (justClickTime < best) best = justClickTime;
			time = time + C / cookiesPerSec;
			cookiesPerSec += F;
		}
		output << best;

		output << "\n";
	}

	output.close();

	{
		cout << "DONE\n";
		int _;
		cin >> _;
	}

	return 0;
}
