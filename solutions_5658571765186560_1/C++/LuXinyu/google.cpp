#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

int t;


int main() {

	ifstream fin("D-large.in", ifstream::in);
	ofstream fout("result.out", ofstream::out);
	fin >> t;
//	cin >> t;
	int x, r, c;
	string result = "RICHARD";
	for(int i = 0; i < t; ++i) {
		fin >> x >> r >> c;
//		cin >> x >> r >> c;
		if(r < c)
			swap(r, c);
		int small = (x+1) >> 1, large = x + 1 - small;
		if(x > r)
			result = "RICHARD";
		else if( small > c)
			result = "RICHARD";
		else if((r * c) % x != 0)
			result = "RICHARD";
		else if( small < c)
			result = "GABRIEL";
		else {			// (x + 1) / 2 == c			
			int max_wrap = (small - 1) * (large - 1);
			if(max_wrap == 0) {
				result = "GABRIEL";
			}
			else {
				bool find = true;
				int limit = min(x - 1, max_wrap);
				for(int j = 1; j <= limit; ++j) {
					find = true;
					for(int k = 0; k <= r - large; ++k) {
						if((j + k * small) % x == 0) {
							find = false;
							break;
						}
					}
//					cout << j << "--" << find << endl;
					if(find) {
						break;
					}
				}
				if(find) {
					result = "RICHARD";
				}
				else {
					result = "GABRIEL";
				}
			}						
		}
		cout << "Case #" << (i+1) << ": " <<  result << endl;
		fout << "Case #" << (i+1) << ": " <<  result << endl;
	}
	
	return 0;
}
