#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int t, x, y;

string solve() {
	string ret;
	if(x < 0 && (-x)%2 == 0) {
		for(int i=1;i<=(-x);i++) ret += "EW";
	}
	if(x > 0 && x%2 == 0) {
		for(int i=1;i<=x;i++) ret += "WE";
	}
	if(x < 0 && (-x)%2 == 1) {
		for(int i=1;i<=(-x);i++) ret += "EW";
	}
	if(x > 0 && x%2 == 1) {
		for(int i=1;i<=x;i++) ret += "WE";
	}
	if(y < 0 && (-y)%2 == 0) {
		for(int i=1;i<=(-y);i++) ret += "NS";
	}
	if(y > 0 && y%2 == 0) {
		for(int i=1;i<=y;i++) ret += "SN";
	}
	if(y < 0 && (-y)%2 == 1) {
		for(int i=1;i<=(-y);i++) ret += "NS";
	}
	if(y > 0 && y%2 == 1) {
		for(int i=1;i<=y;i++) ret += "SN";
	}
	return ret;
}

int main() {
	cin >> t;
	for(int cs=1;cs<=t;cs++) {
		cin >> x >> y;
		cout << "Case #" << cs << ": " << solve() << "\n";
	}
	return 0;
}
