#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <bitset>
#include <utility>
#include <limits>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv){

	unsigned long T;
	cin >> T;

	for(unsigned long t=1; t<=T; ++t){
		cout << "Case #" << t << ": ";

		string name;
		long n;

		cin >> name;
		cin >> n;

		long L = name.size();

		long result = 0;
		long last_end = 0;

		int run = 0;
		for(int i=0; i<L; ++i){
			char c = name[i];

			switch(c) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					run = 0;
					break;
				default:
					run++;
			}

			if( run >= n ) {
				long left = i - n + 2 - last_end;
				long right = L - i;
				result += left * right;

				last_end = i-n+2;
			}
		}

		cout << result;
		cout << endl;
	}

	return 0;
}
