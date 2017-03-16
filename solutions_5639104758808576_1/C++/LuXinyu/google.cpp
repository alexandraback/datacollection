#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

int t;


int main() {

	ifstream fin("A-large.in", ifstream::in);
	ofstream fout("result.out", ofstream::out);
	fin >> t;
	int s_max;
	string digits;
	int cur, result;
	for(int i = 0; i < t; ++i) {
		fin >> s_max >> digits;
		cur = 0;
		result = 0;
		for(int j = 0; j <= s_max; ++j) {
			if(digits[j] <= '0')
				continue;
			if(cur < j) {
				result += (j - cur);
				cur += (j - cur);
			}
			cur += (digits[j] - 48);
		}		
		cout << "Case #" << (i+1) << ": " <<  result << endl;
		fout << "Case #" << (i+1) << ": " <<  result << endl;
		
	}
	
	return 0;
}
