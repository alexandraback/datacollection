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
		int x;
		int y;
		cin >> x;
		cin >> y;

		cout << "Case #" << t << ": ";
		if (x < 0)
		{
			for (int i = 0; i < -x; i++)
			{
				cout << "EW";
			}

		} else {
			for (int i = 0; i < x; i++)
			{
				cout << "WE";
			}
		}

		if (y < 0)
		{
			for (int i = 0; i < -y; i++)
			{
				cout << "NS";
			}

		} else {
			for (int i = 0; i < y; i++)
			{
				cout << "SN";
			}
		}
		cout << endl;
	}

	return 0;
}
