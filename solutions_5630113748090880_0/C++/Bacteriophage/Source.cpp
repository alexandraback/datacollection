#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
static int caseNum = 1;


void find(ifstream& in, ofstream& out, int N) {
	map<int, int> mymap;
	set<int> myset;
	string temp;
	int tempNum;
	for (int i = 0; i < N * (2 * N - 1); i++) {
		in >> temp;
		tempNum = stoi(temp);
		auto mit = mymap.find(tempNum);
		if (mit == mymap.end()) {
			pair<int, int> newpair = { tempNum, 1 };
			mymap.insert(newpair);
		}
		else {
			mit->second++;
		}
	}
	for (auto i = mymap.begin();i != mymap.end();i++) {
		if (i->second % 2) {
			myset.insert(i->first);
		}
	}
	cout << "Case #" << caseNum << ": ";
	for (auto i = myset.begin(); i != myset.end();i++) {
		cout << *i << ' ';
	}
	cout << endl;
	out << "Case #" << caseNum << ": ";
	for (auto i = myset.begin(); i != myset.end();i++) {
		out << *i << ' ';
	}
	out << endl;

}

int main() {
	string temp;
	ifstream file("B-small-attempt0.in");
	ofstream out("output.out");
	int T;
	file >> temp;
	T = stoi(temp);
	if (T >= 1 && T <= 50) {
		while (T != 0) {
			int N;
			file >> temp;
			N = stoi(temp);
			find(file, out, N);
			T--;
			caseNum++;
		}
	}
	return 0;
}