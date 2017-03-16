#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <math.h>
#include <utility>
#include <sstream>
#pragma comment(linker, "/STACK:133217728")

using namespace std;

int n;
int x[44][44];
int ea[44], eb[44];
int cnt = 0;

bool GOOD = 1;
int col[44];

void check(int v) {
	col[v] = 1;
	//if(print) cout << "v = " << v << " " << n << endl;
	for(int i=0; i<n; i++) {
		//if(print) cout << "col[" << i << "] = " << col[i] << endl;
		if(x[v][i] && col[i] == 1) {
			GOOD = 0;
		}
		if(x[v][i] && !col[i]) check(i);
	}
	col[v] = 2;
}

int main() {  
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("ans.txt", "w", stdout);
	
	/*n = 5;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.length();j++)
			x[i][j] = s[j] == '1';
	}
	check(0);*/
	//cout << GOOD << endl;
	int T;
	cin >> T;
	
	
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		//int n, len;
		int len;
		cin >> n >> len;
		bool ok = 0;
		int nn = n * ( n - 1) / 2;
		for(int mask = 0; mask < (1 << nn) && !ok; mask++) {
			cnt = 0;
			int a = 0, b = 0;
			for(int i = 0; i < nn; i++) {
				b++;
				if(b == n) { a++; b = a + 1; }
				if(mask & (1 << i)) {
					ea[cnt] = a;
					eb[cnt] = b;
					cnt++;
				} 
			}

			for(int msk2 = 0; msk2 < (1 << cnt); msk2++) {
				GOOD = 1;
				for(int i=0; i < n; i++)
					for(int j = 0; j < n; j++)
						x[i][j] = 0;
				for(int i = 0; i < cnt; i++)
					if(msk2 & (1 << i)) x[ea[i]][eb[i]] = 1; else
						x[eb[i]][ea[i]] = 1;
				bool good = 1;
				for(int i=0; i<n; i++)
					if(x[n-1][i] == 1) good = 0;
				if(!good) continue;

				for(int i=0; i<n; i++) col[i] = 0;
				check(0);

				if(!GOOD) continue;

				for(int k = 0; k < n; k++)
					for(int i = 0; i < n; i++)
						for(int j = 0; j < n; j++)			
							x[i][j] += x[i][k] * x[k][j];
				
				if(x[0][n-1] == len) { 
					ok = 1; 
					for(int i=0; i < n; i++)
						for(int j = 0; j < n; j++)
							x[i][j] = 0;
					for(int i = 0; i < cnt; i++)
						if(msk2 & (1 << i)) x[ea[i]][eb[i]] = 1; else
							x[eb[i]][ea[i]] = 1;
					break; 
				}
			}
		}
		if(ok) {
			
			cout << "POSSIBLE\n";
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) cout << x[i][j]; cout << endl;
			}
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
	
	return 0;
}