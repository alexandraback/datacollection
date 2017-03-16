#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int getMax(int* t, int l) {
	int max = t[0];
	for (int i = 1; i<l;i++) {
		if (max < t[i])
			max = t[i];
	}
	return max;
}

int getMins(int* t, int m) {
	int max = getMax(t,m);
	int mintime = max;
	for (int k = max; k > 0; k--) {
		int acc = k;
		
		for (int l=0;l<m;l++) {
			acc += ceil((double)t[l] / k) -1;
		}
		
		
		if (acc < mintime)
			mintime = acc;
	}
	return mintime;
}

int main(int argc, char **argv)
{
	int n;
	std::ifstream input;
	std::ofstream output;
	input.open("B-large.in");
	output.open("out.txt");
	input >> n;
	for (int i = 1;i<=n;i++) {
		int m;
		input >> m;
		int* t = new int[m];
		for (int j=0;j<m;j++) {
			input >> t[j];
		}
		
		int mintime = getMins(t,m);

		output << "Case #" << i << ": " << mintime << std::endl;
	}
    input.close();
	output.close();
	return 0;
}
