#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

void Target() {
	long long R, T;
	fin >> R >> T;
	
	long long answer = (1 - 2*R + floor(sqrt((long double)(4*R*R - 4*R + 1 + 8*T))))/4;
	fout << answer << endl;
}

int main() {
	int N;
	fin >> N;
	for (int i=1; i<=N; ++i) {
		fout << "Case #" << i << ": ";
		// Call function
		Target();
	}
	return 0;
}