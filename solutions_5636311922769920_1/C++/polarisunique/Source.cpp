// Example program
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

int main()
{
	ifstream myfile("D-large.in");
	ofstream file("out.txt");
	int n;
	myfile >> n;
	for (int i = 0; i < n; i++){
		int k, c, s;
		myfile >> k >> c >> s;
		file << "Case #" << i + 1 << ": ";
		if (c == 1){
			file << k << endl;
		}
		else if (k == 1){
			if (s >= 1)
				file << 1 << endl;
			else
				file << "IMPOSSIBLE" << endl;
		}
		else if (k == 2){
			if (s >= 1)
				file << 2 << endl;
			else
				file << "IMPOSSIBLE" << endl;
		}
		else if (k == 3){
			if (s >= 2)
				file << "2 6" << endl;
			else
				file << "IMPOSSIBLE" << endl;
		}
		else if (k - s > 2)
			file << "IMPOSSIBLE" << endl;
		else{
			for (int j = 2; j <= k - 2; j++){
				file << j << " ";
			}
			file << k*(k - 1) << endl;
		}
	}
}