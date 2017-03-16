#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int n;
		cin >> n;
		vector<int> b(n);
		vector<vector<int>> inv(n);
		for(int i = 0; i < n; ++i){
			cin >> b[i];
			--b[i];
			inv[b[i]].push_back(i);
		}
		int answer = 0;
		for(int i = 0; i < n; ++i){
			vector<bool> used(n, false);
			int v = i, len = 0;
			while(!used[v]){
				used[v] = true;
				v = b[v];
				++len;
			}
			if(v == i){
				answer = max(answer, len);
			}
		}
		vector<int> used(n, -1);
		int sum = 0;
		for(int i = 0; i < n; ++i){
			if(used[i] >= 0){ continue; }
			const int x = i, y = b[i];
			if(x != b[y]){ continue; }
			int xlen = 1, ylen = 1;
			queue<int> q;
			q.push(x);
			used[x] = 1;
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				xlen = max(xlen, used[u]);
				for(const auto v : inv[u]){
					if(used[v] >= 0 || v == y){ continue; }
					used[v] = used[u] + 1;
					q.push(v);
				}
			}
			q.push(y);
			used[y] = 1;
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				ylen = max(ylen, used[u]);
				for(const auto v : inv[u]){
					if(used[v] >= 0 || v == x){ continue; }
					used[v] = used[u] + 1;
					q.push(v);
				}
			}
			sum += xlen + ylen;
		}
		answer = max(answer, sum);
		cout << "Case #" << case_num << ": " << answer << endl;
	}
	return 0;
}

