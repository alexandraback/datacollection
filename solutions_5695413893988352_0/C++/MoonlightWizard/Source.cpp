#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

int main() {
	int t;
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	cin >> t;
	cin.get();
	for (int i = 0; i < t; i++) {
		string c, j;
		cin >> c >> j;
		cin.get();
		cout << "Case #" << i + 1 << ": ";
		if (c == j) {
			for (int k = 0; k < c.size(); k++) {
				cout << (c[k] == '?' ? '0' : c[k]);
			}
			cout << " ";
			for (int k = 0; k < c.size(); k++) {
				cout << (c[k] == '?' ? '0' : c[k]);
			}
		}
		else {
			int numQ = count(c.begin(), c.end(), '?') + count(j.begin(), j.end(), '?');
			int diff = -1;
			int bestX = -1;
			int bestY = -1;
			for (int i = 0; i < pow(10, numQ); i++) {
				string all = c + j;
				for (int j = 0; j < numQ; j++) {
					string x = "";
					x += (((int)((i / pow(10, j))) % 10) + '0');
					all.replace(all.find_first_of("?"), 1, x);
				}
				string newc = all.substr(0, c.size());
				string newj = all.substr(c.size(), all.size());
				int x = stoi(newc);
				int y = stoi(newj);
				if (diff == -1) {
					diff = abs(x - y);
					bestX = x;
					bestY = y;
				}
				else if (abs(x - y) < diff) {
					diff = abs(x - y);
					bestX = x;
					bestY = y;
				}
				else if (abs(x - y) == diff) {
					if (x < bestX) {
						bestX = x;
						bestY = y;
					}
					else if (y < bestY) {
						bestY = y;
					}
				}
			}
			int numXDigits = bestX == 0 ? 1 : (int)((log10(bestX) + 1));
			for (int i = 0; i < c.size() - numXDigits; i++) {
				cout << "0";
			}
			cout << bestX << " ";
			int numYDigits = bestY == 0 ? 1 : (int)((log10(bestY) + 1));
			for (int i = 0; i < j.size() - numYDigits; i++) {
				cout << "0";
			}
			cout << bestY;
		}
		cout << endl;
		/*int diff = 0;
		string newc = "", newj = "";
		int cInt = 0, jInt = 0;
		int bigger = 0;
		for (int i = 0; i < c.size(); i++) {
			if (c[i] == '?' && j[i] == '?') {
				if (bigger == 1) {
					newc += '0';
					newj += '9';
				}
				else if (bigger == -1) {
					newc += '9';
					newj += '0';
				}
				else {
					newc += '0';
					newj += '0';
				}
			}
			else if (c[i] == '?' && j[i] != '?') {
				newc += j[i];
				newj += j[i];
			}
			else if (j[i] == '?' && c[i] != '?') {
				newc += c[i];
				newj += c[i];
			}
			else {
				if (c[i] > j[i] && bigger==0) {
					bigger = 1;
				}
				else if (c[i] < j[i] && bigger==0) {
					bigger = -1;
				}
				newc += c[i];
				newj += j[i];
			}
		}
		cout << newc << " " << newj << endl;*/
	}
}