#include "main.h"
#include <list>
using namespace Core;
using namespace std;

void Core::init() {}

enum class Mode {
	CODER, JAMMER, EITHER
};

int pre(long long s) {
	return (s / 10) % 10;
}

void Core::solve() {
	int N;
	CGET(N);
	list<pair<string, string>> li;
	fori(i, N) {
		string a, b;
		CGET(a);
		CGET(b);
		li.push_back(make_pair(a, b));
	}
	li.sort();
	int count = 0;
	for (auto i = li.begin(); i != li.end();) {
		for (auto j = li.begin(); j != li.end(); ++j) {
			if (i == j) continue;
			if (i->first == j->first) goto found1;
		}
		goto notFound;
	found1:;
		for (auto j = li.begin(); j != li.end(); ++j) {
			if (i == j) continue;
			if (i->second == j->second) goto found2;
		}
		goto notFound;
	found2:;
		++count;
		li.erase(i++);
		continue;
	notFound:;
		++i;
	}
	cout << count << endl;
}