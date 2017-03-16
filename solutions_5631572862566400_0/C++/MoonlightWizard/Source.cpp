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

int find_best(vector<int> all, vector<int> best, int nextNum) {
	if (count(all.begin(), all.end(), nextNum) <= 1) {
		return best.size();
	}
	else {
		int curMax = 0;
		for (int i = 0; i < all.size(); i++) {
			if (count(best.begin(), best.end(), i) == 0 && all[i] == nextNum) {
				vector<int> newBest = vector<int>(best);
				newBest.push_back(nextNum);
				int cur = find_best(all, newBest, i);
				if (cur > curMax) {
					curMax = cur;
				}
			}
		}
		return curMax;
	}
}

int main() {
	fstream input, output;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	int t;
	input >> t;
	for (int i = 0; i < t; i++) {
		int n;
		input >> n;
		vector<int> all;
		for (int j = 0; j < n; j++) {
			int r;
			input >> r;
			all.push_back(r-1);
		}
		int maxsize = 0;
		int numCycles2 = 0;
		for (int j = 0; j < n; j++) {
			if (all[all[j]] == j) {
				numCycles2++;
			}
		}
		numCycles2 /= 2;
		//cout << "numCycles2 is " << numCycles2 << endl; 
		for (int j = 0; j < n; j++) {
			vector<int> best;
			int current = j;
			int next = all[j];
			best.push_back(current);
			while (true) {
				while (count(best.begin(), best.end(), next) == 0) {
					best.push_back(next);
					current = next;
					next = all[current];
				}
				if (next == best[best.size() - 2])  {
					if (best.size() == n) {
						maxsize = n;
						break;
					}
					else {
						int curBest = find_best(all, best, current);
						curBest += (numCycles2 - 1) * 2;
						if (curBest > maxsize) {
							maxsize = curBest;
						}
						break;
					}
				}
				else if (next == best[0]) {
					if (best.size() > maxsize) {
						maxsize = best.size();
					}
					break;
				}
				else {
					break;
				}
			}
		}
		output << "Case #" << i+1 << ": " << maxsize << endl;
	}
}
