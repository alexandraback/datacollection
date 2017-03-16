#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define OUTPUT_PREFIX "Case #"
#define INPUT_NAME "A-small-attempt3.in"
#define OUTPUT_NAME "output.dat"

using namespace std;

int main() {

	ifstream input;
	ofstream output;

	int testcase;

	input.open(INPUT_NAME);
	output.open(OUTPUT_NAME);

	input >> testcase;

	for(int test=0;test<testcase;test++) {
		int answer;
		int row,column,shipSize;

		input >> row >> column >> shipSize;

		float rate = (float)column/(float)shipSize;

		answer = (int)rate*row + shipSize-1;

		if(rate!=(int)rate)
			answer++;

		output << OUTPUT_PREFIX << test+1 << ": " << answer << endl;
	}

	return 0;
}