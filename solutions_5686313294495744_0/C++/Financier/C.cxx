# include <bits/stdc++.h>
using namespace std;

struct SBJ {
	string a, b;
};

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		int n; cin >> n;
		
		vector<SBJ> cn(n);
		map<string, int> fs, sc;
		for(int i=0; i<n; ++i) {
			cin >> cn[i].a >> cn[i].b;
			fs[cn[i].a] += 1;
			sc[cn[i].b] += 1; 
		}
		
		map<string, bool> fs_, sc_;
		
		int ans = n;
		for(int i=0; i<n; ++i) {
			if (fs[cn[i].a] == 1 || sc[cn[i].b] == 1) {
				ans -= 1;
				
				fs_[cn[i].a] = true;
				sc_[cn[i].b] = true;
			}
		}
		
		for(auto t:fs_) fs.erase(t.first);
		for(auto t:sc_) sc.erase(t.first);
		
		ans -= max(fs.size(), sc.size());
		
		printf("Case #%d: %d\n", T_, ans);
	}
	return 0;
}