#include <iostream>
#include <list>
using namespace std;

list< double > naomi, ken, dnaomi, dken;

int playDeceitfulWar() {
	int result = 0;
	list<double>::iterator it1 = dken.end();
	while (--it1 != dken.begin()) {
		list<double>::iterator it2 = dnaomi.end();
		--it2;
		if (*it2 > *it1) {
			result++;
			dnaomi.erase(it2);
		}
		else {
			it2 = dnaomi.begin();
			dnaomi.erase(++it2);
		}
		dken.erase(it1);
	}
	return result;
}

int playWar() {
	int result = 0;
	list<double>::iterator it1 = naomi.end();
	while (--it1 != naomi.begin()) {
		list<double>::iterator it2 = ken.end();
		--it2;
		if (*it2 > *it1) {
			ken.erase(it2);
		}
		else {
			result++;
			it2 = ken.begin();
			ken.erase(++it2);
		}
		naomi.erase(it1);
	}
	return result;
}


int main() {
	int T;
	cin >> T;
	for (int k = 1; k <= T; ++k) {
		naomi.clear();
		ken.clear();
		naomi.push_back(-1);
		ken.push_back(-1);
		
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			double tmp;
			cin >> tmp;
			naomi.push_back(tmp);
		}
		for (int i = 0; i < N; ++i) {
			double tmp;
			cin >> tmp;
			ken.push_back(tmp);
		}
		
		naomi.sort();
		dnaomi.assign(naomi.begin(), naomi.end());
		ken.sort();
		dken.assign(ken.begin(), ken.end());
		
		int dwar = playDeceitfulWar();
		int war = playWar();
		cout << "Case #" << k << ": " << dwar << ' ' << war << endl;
	}
}


