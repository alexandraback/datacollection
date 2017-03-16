/*
 ID: aandrew
 PROG: GCJ qual 2012, B
 URL: 
 LANG: C++
 
 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPE(i, n) for(int i = 0; i <= n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;

bool is_valid(int i, int j, int k) {
	return (abs(i-j) <= 2 && abs(i-k) <= 2 && abs(j-k) <= 2);
}
bool is_surprising(int i, int j, int k) {
	return is_valid(i,j,k) && (abs(i-j) == 2 || abs(i-k) == 2 || abs(j-k) == 2);
}
bool is_not_surprising(int i, int j, int k) {
	return is_valid(i,j,k) && (abs(i-j) < 2 && abs(i-k) < 2 && abs(j-k) < 2);
}

int T, N, S, p, t[105];
int main() {
	cin >> T;
	
	REP(v, T) {
		cin >> N >> S >> p;
		REP(j, N) {
			cin >> t[j];
		}
		
		int score = 0;
		REP(w, N) {
			bool flag = false;
			REPE(i, 10) REPE(j, 10) REPE(k, 10) {
				if (!flag && max(max(i,j),k) >= p && i+j+k == t[w]) {
					if (is_not_surprising(i,j,k)) {
						//cout << "y " << t[w] << " " << i << " " << j << " " << k << endl;
						flag = true;
					}
				}
			}
			REPE(i, 10) REPE(j, 10) REPE(k, 10) {
				if (!flag && max(max(i,j),k) >= p && i+j+k == t[w]) {
					if (!flag && S && is_surprising(i,j,k)) {
						//cout << "n " << t[w] << " " << i << " " << j << " " << k << endl;
						S--;
						flag = true;
					}
				}
			}
			score += flag;
		}
		cout << "Case #" << (v+1) << ": " << score << endl;
	}
}