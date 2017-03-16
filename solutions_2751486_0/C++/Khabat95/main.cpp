#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

typedef set<int>::iterator SETIT;
typedef map<int, int>::iterator MAPIT;
typedef pair<int, int> PAIR;

static set<int> pos_v;
static vector<int> consec;
static vector<int> lengths;
static vector<int> poss;

void algo() {
	string name;
	cin >> name;

	int n;
	cin >> n;

	pos_v.clear();
	consec.clear();
	lengths.clear();
	poss.clear();

	pos_v.insert(name.length());

	int pos = name.find('a', 0);
	while(pos != string::npos) {
		pos_v.insert(pos);
		pos = name.find('a', pos+1);
	}

	pos = name.find('e', 0);
	while(pos != string::npos) {
		pos_v.insert(pos);
		pos = name.find('e', pos+1);
	}

	pos = name.find('i', 0);
	while(pos != string::npos) {
		pos_v.insert(pos);
		pos = name.find('i', pos+1);
	}

	pos = name.find('o', 0);
	while(pos != string::npos) {
		pos_v.insert(pos);
		pos = name.find('o', pos+1);
	}

	pos = name.find('u', 0);
	while(pos != string::npos) {
		pos_v.insert(pos);
		pos = name.find('u', pos+1);
	}

	pos = -1;
	int length = name.length();
	for(SETIT it=pos_v.begin(); it!=pos_v.end(); ++it) {
		int cons = *it - pos;
		if(cons > n) {
			consec.push_back(cons - 1);
			lengths.push_back(length);
			poss.push_back(pos+1 - (name.length() - length));

			length -= pos+1 - (name.length() - length) + 1;
		}

		pos = *it;
	}

	long long res = 0;
	for(int i=0; i<lengths.size(); ++i) {
		res += (long long)poss[i] * ((long long)lengths[i] - (long long)n - (long long)poss[i] + 1);

		res += ((long long)consec[i] - (long long)n + 1) * ((long long)lengths[i] - (long long)consec[i] - (long long)poss[i] + 1);
		res += (((long long)consec[i] - (long long)n) * ((long long)consec[i] - (long long)n + 1)) / 2;
	}

	cout << res << endl;
}

int main() {
	int n_cases;
	cin >> n_cases;

	for(int i=0; i<n_cases; ++i) {
		cout << "Case #" << i+1 << ": ";
		algo();
	}
}

