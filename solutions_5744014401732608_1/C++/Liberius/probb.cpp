#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

using namespace std;

typedef pair<short, long long> inputpair;
/*
long long max_way(short buildings) {
	if (buildings == 2) return 1;
	long long result = 0;
	for (short i = 2; i < buildings; ++i)
		result += max_way(i);
	return result;
}
*/
/*
long long max_way(short buildings) {
	vector<long long> result(buildings+1);
	result[2] = 1;
	for (size_t i = 3; i <= buildings; ++i)
		result[i] = accumulate(result.begin() + 2, result.begin() + i, 0);
	return result[buildings];
} =>maxway(2)==1, maxway(n>2) = 2^(n-3)

void process (const inputpair& input, ostream& op){
	
}
*/

int main(int argc, char** argv){
	string filename;
	cout << "input filename: ";
	cin >> filename;
	ifstream ip(filename.c_str());
	ofstream op("output.txt");
	if (!(ip.is_open())) {
		op << "File not exist.";
		op.close();
		return 1;
	}
	size_t T;
	ip >> T;
	string input;
	for (size_t i = 1; i <= T; ++i){
		inputpair temp;
		ip >> temp.first >> temp.second;
		op << "Case #" << i << ": ";
		if (temp.second > (static_cast<long long>(1) << (temp.first-2)))
			op << "IMPOSSIBLE" << endl;
		else {
			op << "POSSIBLE" << endl;
			if (temp.second == (static_cast<long long>(1) << (temp.first - 2))) {
				op << '0';
				for (short j = 1; j < temp.first; ++j)
					op << '1';
			}
			else {
				string tempstr;
				tempstr = "0";
				while (temp.second != 0) {
					if (temp.second % 2) tempstr.insert(0, "1");
					else tempstr.insert(0, "0");
					(temp.second) >>= 1;
				}
				tempstr.insert(0, temp.first - tempstr.size(), '0');
				op << tempstr;
			}
			op << endl;
			for (size_t j = 1; j < temp.first; ++j) {
				for (size_t k = 0; k <= j; ++k)
					op << '0';
				for (size_t k = j + 1; k < temp.first; ++k)
					op << '1';
				op << endl;
			}
		}
	}
	op.close();
	ip.close();
	return 0;
}