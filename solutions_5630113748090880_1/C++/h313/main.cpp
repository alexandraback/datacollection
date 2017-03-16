#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;


int main() {
	ifstream fin("test.in");
	ofstream fout("test.out");
	int cases;
	fin >> cases;
	for(int c = 1; c <= cases; c++) {
		int heights[2500] = {0};
		vector<int> good;
		int n;
		fin >> n;
		for(int i = 0; i < (2*n-1)*n; i++) {
			int temp;
			fin >> temp;
			heights[temp - 1]++;
		}
		for(int i = 0; i < 2500; i++) {
			if(heights[i] % 2 == 1) {
				good.push_back(i + 1);
			}
		}
		sort(good.begin(), good.end());
		fout << "Case #" << c << ": ";
		for(int i = 0; i < good.size(); i++)
			fout << good[i] << " ";
		fout << endl;
	}
}