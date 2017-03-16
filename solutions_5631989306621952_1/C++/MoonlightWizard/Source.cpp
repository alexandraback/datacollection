#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

int main() {
	int t;
	fstream input, output;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	input >> t;
	input.get();
	for (int i = 0; i < t; i++) {
		string x;
		getline(input, x);
		string best = "";
		best += x[0];
		for (int j = 1; j < x.length(); j++) {
			if (x[j] >= best[0]) {
				best = x[j] + best;
			}
			else {
				best += x[j];
			}
		}
		output << "Case #" << i+1 << ": " << best << endl;
	}
}