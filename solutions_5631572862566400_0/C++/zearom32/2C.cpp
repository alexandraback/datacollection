
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int dfs(vector<int>& out, vector<int>& flag, int node, int color, int ans = 0) {
	//cout << node << endl;
	if (flag[node] != 0) return ans;
	flag[node] = color;
	return dfs(out, flag, out[node], color, ans + 1);
}

void dfs1(vector<int>& out, vector<int>&v, vector<int>& col, int node, vector<int>& record, int dep = 0) {
	if (col[node]) return;
	col[node] = 1;
	record[node] = max(record[node], dep);
	dfs1(out, v, col, out[node], record, dep + 1);
}


bool valid(vector<int>& out, vector<int>& arr) {
	for (int i = 1; i < arr.size() - 1; i++) {
		if (out[arr[i]] != arr[i - 1] && out[arr[i]] != arr[i + 1]) return false;
	}
	return true;
}


bool aaa;
vector<int> vis;
void brute(vector<int>& out, vector<int>& arr, int l, int m, int n) {
	if (aaa) return;
	if (l == m) {
		arr[m] = arr[0];
		arr[m + 1] == arr[1];
		if (valid(out, arr)) aaa = true;
	}
	else {
		if (l >= 2 && l < m -1 && out[arr[l - 1]] != arr[l - 2]) {
			int p = out[arr[l - 1]];
			if (!vis[p]) {
				arr[l] = p; vis[p] = 1;
				brute(out, arr, l + 1, m, n);
				vis[p] = 0;
			}
		}
		else {
			for (int p = 1; p <= n; p++) {
				if (!vis[p]) {
					arr[l] = p; vis[p] = 1;
					brute(out, arr, l + 1, m, n);
					vis[p] = 0;
				}
			}
		}
	}
}

void solve2(ifstream& fin, ofstream& fout) {

	int n;
	fin >> n;
	vector<int> out(n + 1);

	queue<int>q;

	vector<int> v(n + 1);
	vector<int> flag(n + 1);

	for (int i = 1; i <= n; i++) {
		fin >> out[i];
		v[out[i]]++;
	}
	
	aaa = false;
	vis = vector<int>(n + 1);
	int ans = 0;
	for (int i = n; i >= 2; i--) {
		vector<int> arr(i+2);
		brute(out, arr, 0, i, n);
		if (aaa) {
			ans = i;
			break;
		}
	}
	fout << ans << endl;
}

void solve(ifstream& fin, ofstream& fout) {

	int n;
	fin >> n;
	vector<int> out(n+1);

	queue<int>q;	
	int ans = 0;

	vector<int> v(n+1);
	vector<int> flag(n+1);

	for (int i = 1; i <= n; i++) {
		fin >> out[i];
		v[out[i]]++;
	}


	for (int i = 1; i <= n; i++) {
		if (!v[i]) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int p = i;
		int q = out[p];
		if (out[q] == p) {
			out[p] = p;
			out[q] = q;
			vector<int> record(n + 1);
			for (int j = 1; j <= n; j++) {
				if (v[j] == 0) {
					vector<int> col(n + 1);
					cout << "dfs" << j << endl;
					dfs1(out, v, col, j, record);
				}
			}
		//	cout << "mm" << p << " " << q << " " << record[p] << " " << record[q] << endl;
			ans = max(ans, 2 + record[p] + record[q]);
			out[p] = q;
			out[q] = p;
		}
	}


	for (int i = 0; i < n; i++) {
		vector<int> flag(n + 1);
		int p = dfs(out, flag, i + 1, i + 1);
		cout << p << endl;
		ans = max(ans, p);
	}


	fout << ans << endl;
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "c.in";
	}
	else {
		inn = argv[1];
	}
	string in = inn;
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(inn);
	ofstream fout(out);

	int t;
	fin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cout << "Case " << cs << endl;
		fout << "Case #" << cs << ": ";
		solve2(fin, fout);
	}
	fout.close();

	return 0;
}