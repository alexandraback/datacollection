#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
static const int INF = 1000000000;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int n;
		cin >> n;
		const int m = n * 2 - 1;
		vector<vector<int>> q(m, vector<int>(n));
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){ cin >> q[i][j]; }
		}
		sort(q.begin(), q.end());
		vector<bool> used(m);
		vector<vector<vector<int>>> a(n);
		for(int i = 0; i < n; ++i){
			int minval = INF;
			for(int j = 0; j < m; ++j){
				if(used[j]){ continue; }
				minval = min(minval, q[j][i]);
			}
			for(int j = 0; j < m; ++j){
				if(used[j] || q[j][i] != minval){ continue; }
				a[i].push_back(q[j]);
				used[j] = true;
			}
		}
		vector<int> answer;
		for(int i = 0; i < n; ++i){
			if(a[i].size() != 1){ continue; }
			for(int j = 0; j < n; ++j){
				if(j == i){
					answer.push_back(a[i][0][j]);
				}else if(a[j][0][i] == a[i][0][j]){
					answer.push_back(a[j][1][i]);
				}else{
					answer.push_back(a[j][0][i]);
				}
			}
		}
		cout << "Case #" << case_num << ":";
		for(int i = 0; i < n; ++i){ cout << " " << answer[i]; }
		cout << endl;
	}
	return 0;
}

