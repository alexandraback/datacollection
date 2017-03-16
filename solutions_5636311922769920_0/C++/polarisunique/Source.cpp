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
	ifstream myfile("D-small-attempt0.in");
	ofstream file("out.txt");
	int n;
	myfile >> n;
	for (int i = 0; i < n; i++){
		int k, c, s;
		myfile >> k >> c >> s;
		file << "Case #" << i + 1 << ": ";
		for (int j = 0; j < s; j++){
			int64_t q = 1 + j*(int64_t)pow(k, c - 1);
			file << q;
			if (j < s - 1)
				file << " ";
		}
		file << endl;
	}
}