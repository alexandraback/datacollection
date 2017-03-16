#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void main() {

	FILE *str, *abc;
	freopen_s(&str, "input.txt", "r", stdin);
	freopen_s(&abc, "out.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int tt = 0; tt < t; tt++) {
		cout << "Case #" << tt + 1 << ": ";
		
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		int w1[100][100], w2[100][100], w3[100][100];
		memset(w1, 0, sizeof(w1));
		memset(w2, 0, sizeof(w2));
		memset(w3, 0, sizeof(w3));
		vector<vector<int>> an(0);
		int ans = 0;

		for (int i = 0; i<a; i++)
			for (int j = 0; j<b; j++)
				for (int u = 0; u < c; u++)
				{
					if (w1[i][j] < k && w2[j][u] < k && w3[i][u] < k) {
						ans++;
						w1[i][j]++;
						w2[j][u]++;
						w3[i][u]++;
						an.push_back({i+1,j+1,u+1});
					}
				}
		cout << ans << endl;
		for (int i = 0; i < ans; i++)
			cout << an[i][0] << " " << an[i][1] << " " << an[i][2] << endl;
	}
		
}