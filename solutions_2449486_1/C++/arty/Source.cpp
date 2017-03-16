#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("output.txt");

void read_pattern(vector<vector<int>>& pattern) {
	int n, m;
	fin >> n >> m;
	pattern.clear();
	for (int i=0;i<n;i++) {
		vector<int> line;
		for (int j=0;j<m;j++) {
			int tmp;
			fin >> tmp;
			line.push_back(tmp);
		}
		pattern.push_back(line);
	}
}

int find_min(vector<vector<int>>& pattern) {
	int n = pattern.size();
	int m = pattern[0].size();
	int result = pattern[0][0];
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (pattern[i][j] < result) {
				result = pattern[i][j];
			}
		}
	}
	return result;
}

int find_max(vector<vector<int>>& pattern) {
	int n = pattern.size();
	int m = pattern[0].size();
	int result = pattern[0][0];
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (pattern[i][j] > result) {
				result = pattern[i][j];
			}
		}
	}
	return result;
}

bool is_it_possbile(vector<vector<int>>& pattern) {
	int start = find_max(pattern), end = find_min(pattern);
	int n = pattern.size();
	int m = pattern[0].size();
	bool result = true;
	for (int k=start; k >= end; k--) {
		vector<vector<bool>> marked;
		
		for(int i=0;i<n;i++) {
			vector<bool> line(m);
			for (int j=0;j<m;j++) {
				line[j] = false;
			}
			marked.push_back(line);
		}


		for (int i=0;i<n;i++) {
			bool ok = true;
			for (int j=0;j<m;j++) {
				if (pattern[i][j] > k) ok = false;
			}
			if (ok) {
				for (int j=0;j<m;j++) {
					if (pattern[i][j] == k) 
						marked[i][j] = true;
				}
			}
		}

		for (int i=0;i<m;i++) {
			bool ok = true;
			for (int j=0;j<n;j++) {
				if (pattern[j][i] > k) ok = false;
			}
			if (ok) {
				for (int j=0;j<n;j++) {
					if (pattern[j][i] == k) 
						marked[j][i] = true;
				}
			}
		}

		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				if (pattern[i][j] == k && !marked[i][j]) {
					result = false;
				}
			}
		}

		if (result == false) break;

	}
	return result;
}

int main() {

	int T;
	fin >> T;
	for (int t=1;t<=T;t++) {
		vector<vector<int>> pattern;
		read_pattern(pattern);
		bool result = is_it_possbile(pattern);
		if (result) {
			fout << "Case #" << t << ": YES" << endl;
		} else {
			fout << "Case #" << t << ": NO" << endl;
		}
	}

	fin.close();
	fout.close();

	return 0;
}