#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <fstream>

using namespace std;

typedef long long ll;

int main() { 
	ofstream fout;
	fout.open ("ayylmao.txt");
	ifstream fin;
	fin.open ("B-large.in");

	int t; fin>>t;
	for(int i = 1; i <= t; i++) {
		fout<<"Case #"<<i<<": ";
		int n;
		fin>>n;
		int h;
		bool heights[2501] = {false};
		for(int j = 0; j < 2*n*n-n ; j++) {
			fin>>h;
			//cout<<h<<endl;
			heights[h] = !heights[h];
		}
		for(int j = 1; j <= 2500; j++) {
			if(heights[j]) {
				fout<<' '<<j;
			}
		}
		fout<<endl;
	}
	return 0;
}