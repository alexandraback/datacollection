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

		long X,Y;
		cin >> X >> Y;

		long absX = abs(X);
		long absY = abs(Y);

		for(long x=0; x<absX; ++x){
			if(X<0){
				cout << "EW";
			} else {
				cout << "WE";
			}
		}

		for(long y=0; y<absY; ++y){
			if(Y<0){
				cout << "NS";
			} else {
				cout << "SN";
			}
		}

		cout << endl;
	}

	return 0;
}
