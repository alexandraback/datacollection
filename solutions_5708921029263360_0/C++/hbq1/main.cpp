#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef long long int lli;

const int MAXSIZE = 20;

int a[MAXSIZE][MAXSIZE][MAXSIZE];


int main() {
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int t, tn = 1;
	cin >> t;
	while (tn <= t) {
		cout << "Case #" << tn << ": ";
		tn++;
		
		for (int i = 0; i < MAXSIZE; ++i)
			for (int j = 0; j < MAXSIZE; ++j)
				for (int k = 0; k < MAXSIZE; ++k)
					a[i][j][k] = 0;
		vector<vector<int>> ans(0);
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		for (int i = J; i > 0; --i)
			for (int j = 1; j <= P; ++j)
				for (int k = S; k > 0; --k)
					if (a[i][0][k] < K && a[i][j][0] < K && a[0][j][k] < K) {
						vector<int> l(3);
						l[0] = i;
						l[1] = j;
						l[2] = k;
						ans.push_back(l);
						a[i][0][k]++;
						a[0][j][k]++;
						a[i][j][0]++;
					}

		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
		//cout << endl;
	}
	return 0;
}

