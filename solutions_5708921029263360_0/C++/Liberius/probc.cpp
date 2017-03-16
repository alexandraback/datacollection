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

struct inputformat{
	short j,p,s,k;
};

void process (const inputformat& input, ostream& op){
	vector<short> jptable(input.j*input.p,0);
	vector<short> jstable(input.j*input.s,0);
	vector<short> pstable(input.p*input.s,0);
	size_t cnt=0;
	vector<short> result;
	for (short j = 1; j <= input.j; ++j){
		for (short p = 1; p <= input.p; ++p){
			for (short s = 1; s <= input.s; ++s){
				if (jptable[(j-1)*input.p + (p-1)] >= input.k) continue;
				if (jstable[(j-1)*input.s + (s-1)] >= input.k) continue;
				if (pstable[(p-1)*input.s + (s-1)] >= input.k) continue;
				++cnt;
				result.push_back(j); result.push_back(p); result.push_back(s);
				jptable[(j - 1)*input.p + (p - 1)]++;
				jstable[(j - 1)*input.s + (s - 1)]++;
				pstable[(p - 1)*input.s + (s - 1)]++;
			}
		}
	}
	op << cnt << endl;
	for (size_t i = 0; i < cnt; ++i)
		op << result[3*i] <<' '<< result[3*i+1] << ' '<< result[3*i+2] << endl;
}


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
		inputformat temp;
		ip >> temp.j>> temp.p>> temp.s>> temp.k;
		op << "Case #" << i << ": ";
		process(temp,op);
	}
	op.close();
	ip.close();
	return 0;
}