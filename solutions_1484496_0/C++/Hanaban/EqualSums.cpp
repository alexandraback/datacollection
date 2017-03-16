#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

int N;
int sum;
int S[20];

void solve(int case_no)
{
	
	
	cin >> N;
	sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
		sum += S[i];
	}
	
	map<int, int> m;
	
	for (int i = 1; i <= 1 << 19; ++i) {
		int s1 = 0;
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j) ) s1 += S[j];
		}
		if (s1 > sum / 2) continue;
		if (m.find(s1) != m.end() ) {
			if (m[s1] | i == 0) {
				bool first = true;
				for (int j = 0; j < 20; ++j) {
					if (m[s1] & (1 << j) ) {
						if (!first) {
							cout << " ";
						}
						first = false;
						cout << S[j];
					}
				}
				cout << endl;
				first = true;
				for (int j = 0; j < 20; ++j) {
					if (i & (1 << j) ) {
						if (!first) {
							cout << " ";
						}
						first = false;
						cout << S[j];
					}
				}
				cout << endl;
				return;
			}
		} else m[s1] = i;
	}
	
	cout << "Impossible" << endl;
	return;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d:\n", i);
		solve(i);
	}
	
	return 0;
}
