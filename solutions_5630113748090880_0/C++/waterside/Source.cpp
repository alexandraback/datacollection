#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)

#include <cassert>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for (int i=0; i<(E); i++)

typedef long long ll;
//const ll MOD = 1000000007;
//const double PI = atan(1) * 4;










int N;
vector<int> dat[103];
vector<int> a[103];
vector<int> b[103];


int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);

		FOR(i, 103) dat[i].clear();
		FOR(i, 103) a[i].clear();
		FOR(i, 103) b[i].clear();

		
		
		
		cin >> N;
		FOR(t, 2*N-1) {
			dat[t].resize(N);
			FOR(i, N) cin >> dat[t][i];
		}

		
		bool taken[103] ={};
		FOR(i, N) {
			int minVal = 987654;
			FOR(t, 2*N-1) if (!taken[t]) minVal = min(minVal, dat[t][i]);

			FOR(t, 2*N-1) if (!taken[t]) if (minVal == dat[t][i]) {
				if (a[i].empty())
					a[i] = dat[t];
				else
					b[i] = dat[t];

				taken[t] = true;
			}
		}
		

		/*
		FOR(i, N) {
			cout << endl;
			for (int x : a[i]) cout << x << " ";
			cout << endl;
			for (int x : a[i]) cout << x << " ";
			cout << endl;
			cout << endl;
		}
		*/
		
		


		int I = -123;
		FOR(i, N) if (b[i].empty()) {
			I = i; break;
		}
		
		
	
		vector<int> &theOther = a[I];


		vector<int> ans;
		FOR(i, N) {
			if (i != I) {
				int aa = a[i][I];
				int bb = b[i][I];
				ans.push_back(aa != theOther[i] ? aa : bb);
			}
			else {
				ans.push_back(theOther[i]);
			}
		}




		for (int a : ans)
			cout << a << " ";
		cout << endl;

	}


	return 0;
}