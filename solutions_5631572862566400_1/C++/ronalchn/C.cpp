#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> bff;
vector<int> ans;
vector<vector<int>> des;
vector<int> height;
vector<bool> cy;

int cycle(int i) {
	int fast = bff[i], slow = i;
	
	while (fast != slow) {
		fast = bff[bff[fast]];
		slow = bff[slow];
		if (ans[fast] != -1) {
			while (i != fast) {
				ans[i] = ans[fast];
				i = bff[i];
			}
			return ans[fast];
		}
	}

	int res = 1;
	fast = bff[slow];
	while (fast != slow) {
		cy[fast] = true;
		fast = bff[fast];
		cy[fast] = true;
		res++;
	}
	cy[slow] = true;
	fast = bff[slow];
	while (fast != slow) {
		ans[fast] = res;
		fast = bff[fast];
	}
	ans[slow] = res;

	while (i != fast) {
		ans[i] = res;
		i = bff[i];
	}
	return res;
}

int dfs(int i) {
	if (height[i]!=-1) return height[i];
	int h = 1;
	for (int v : des[i]) {
		h = max(h, dfs(v)+1);
	}
	height[i] = h;
	return h;
}

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    int n;
    cin >> n;

		bff = vector<int>(n+1);
		cy = vector<bool>(n+1,false);
		des = vector<vector<int>>(n+1);
		ans = vector<int>(n+1, -1);
		height = vector<int>(n+1, -1);

		for (int i=1;i<=n;i++) {
			cin >> bff[i];
		}


		int longest = 0;
		for (int i=1;i<=n;i++) {
			longest = max(longest, cycle(i));
		}
		for (int i=1;i<=n;i++) {
			//if (bff[bff[i]] != i) {
			if (!cy[i]) {
				des[bff[i]].push_back(i);
				//clog << bff[i] << "<-" << i << endl;
			}
		}
		for (int i=1;i<=n;i++) {
			dfs(i);
		}
		int total_size = 0;
		bool non_pairs = false;
		for (int i=1;i<=n;i++) {
			if (bff[bff[i]] == i && i < bff[i]) {
				//clog << "pair " << i << " " << bff[i] << endl;
				int size = dfs(i) + dfs(bff[i]);
				total_size += size;
				if (size > 2) non_pairs = true;
			}
		}

		//clog << non_pairs << endl;
		//clog << total_size << endl;
		//for (auto k : cy) clog << k << " "; clog << endl;
		//for (auto k : height) clog << k << " "; clog << endl;

		if (!non_pairs) {
			if (total_size%2==1) total_size--;
		}
		longest = max(longest, total_size);

    printf("Case #%d: %d\n", t, longest);
  }

}
