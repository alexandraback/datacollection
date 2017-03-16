#include "main.h"

using namespace Core;
using namespace std;

void Core::init() {}

void Core::solve() {
	std::string str;
	CGET(str);
	std::map<char, int> m;
	fore(i, str) {
		++m[*i];
	}
	map<int, int> result;
	++result[0] = m['Z'];
	++result[2] = m['W'];
	++result[4] = m['U'];
	++result[6] = m['X'];
	++result[8] = m['G'];
	++result[5] = m['F'] - result[4];
	++result[1] = m['O'] - result[0] - result[2] - result[4];
	++result[3] = m['R'] - result[0] - result[4];
	++result[7] = m['V'] - result[5];
	++result[9] = m['I'] - result[5] - result[6] - result[8];
	fore(i, result) {
		fori(j, i->second) {
			cout << i->first;
		}
	}
	cout << endl;
}