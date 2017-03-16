#include "main.h"
#include <list>


using namespace std;

void Core::init() {}

void Core::solve() {
	string str;
	CGET(str);
	list<char> result;
	result.push_back(str[0]);
	for (auto i = str.begin() + 1; i != str.end(); ++i) {
		if (*i >= result.front()) {
			result.push_front(*i);
		} else {
			result.push_back(*i);
		}
	}
	cout << string(result.begin(), result.end());
}