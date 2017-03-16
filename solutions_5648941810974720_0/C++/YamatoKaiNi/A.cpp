#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <bitset>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	const string nums[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

	for (int testcase = 0; testcase < T; testcase++){
		string line;
		cin >> line;
		double mat[26][11] = {0};
	
		for (int i = 0 ; i < 10; i++)
			for (char ch : nums[i])
				mat[ch - 'A'][i] += 1;

		for (char ch : line)
			mat[ch - 'A'][10] += 1;

		int j = -1, r = -1;

		int n = 11, m = 26;
		while (j < n){
			j++;
			int nonzero = -1;
			for (int i = r + 1; i < m; i++)
				if (abs(mat[i][j]) >= 1e-6){
					nonzero = i;
					break;
				}
			if (nonzero == -1)
				continue;
			r++;
			if (r != nonzero){
				for (int i = 0; i < n; i++){
					double temp = mat[r][i];
					mat[r][i] = mat[nonzero][i];
					mat[nonzero][i] = temp;
				}
			}

			double scale = mat[r][j];

			for (int i = 0; i < n; i++)
				mat[r][i] /= scale;
			for (int i = 0; i < m; i++)
				if (i != r){
					double c = mat[i][j];
					for (int l = 0; l < n; l++)
						mat[i][l] = -c * mat[r][l] + mat[i][l];
				}

		}

		string answer;
		printf("Case #%d: ", testcase + 1);
		for (int i = 0; i < 10; i++){
			int it = round(mat[i][n - 1]);
			for (int j = 0; j < it; j++){
				cout << i;
				answer += nums[i];
			}
		}
		cout << "\n";
		sort(answer.begin(),answer.end());
		sort(line.begin(),line.end());
		if (answer != line)
			cout << "Case " << testcase  + 1 << "WRONG\n";
	}
	return 0;
}
