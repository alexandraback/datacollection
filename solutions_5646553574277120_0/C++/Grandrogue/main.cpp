#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("C-small-attempt3.in");
ofstream fout("out.txt");

bool used[31];

bool check(int n) {
	for(int i = 1; i <= n; ++i) {
		if(!used[i]) return false;
	}
	return true;
}

int main() {
	int tests;
	fin >> tests;
	int c, n, m;
	for(int test = 0; test < tests; ++test) {
		vector<int> a;
		fin >> c >> n >> m;
		for(int i = 0; i <= m; i++) {
			used[i] = false;
		}
		for(int i = 0; i < n; i++) {
			int x;
			fin >> x;
			a.push_back(x);
		}
		    
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = m - a[i]; j >= 1; j--) {
				if(used[j]) {
					used[j + a[i]] = true;
				}
			}
			used[a[i]] = true;
		}
		while(!check(m)) {
			ans++;
			for(int i = 1; i <= m; ++i) {
				if(!used[i]) {
					for(int j = m - i; j >= 1; j--) {
						if(used[j]) {
							used[j + i] = true;
						}
					}
					used[i] = true;
					break;
				}
			}
		}
		fout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}
