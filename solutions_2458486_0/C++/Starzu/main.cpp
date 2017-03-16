#include <iostream>
#include <vector>

using namespace std;

struct Chest {
	bool opened;
	int open;
	vector<int> keys;
};

int n;
int keys[201];
int all[201];
int need[201];
int indep[201];
Chest chests[201];
vector<int> ans;

bool find() {
	{
		bool all=true;
		for (int i=0; i<n && all; ++i)
			if (chests[i].opened == false)
				all=false;
		if (all) return true; 
	}

	for (int i=0; i<n; ++i) {
		if (chests[i].opened == false && keys[chests[i].open] > 0) {
			if (need[chests[i].open] > 1 && keys[chests[i].open] == 1 && indep[chests[i].open] == 0) {
				bool cont = false;
				for (int j=0; j<chests[i].keys.size(); ++j)
					if (chests[i].keys[j] == chests[i].open)
						cont = true;
				if (!cont) continue;
			}
			//cout << "IN: " << i+1 << endl;
			//system("PAUSE");
			chests[i].opened = true;
			keys[chests[i].open]--;
			need[chests[i].open]--;
			for (int j=0; j<chests[i].keys.size(); ++j) {
				keys[chests[i].keys[j]]++;
				if (chests[i].keys[j] != chests[i].open) indep[chests[i].keys[j]]--;
			}
			if (find()) {
				ans.push_back(i);
				return true;
			}
			for (int j=0; j<chests[i].keys.size(); ++j) {
				keys[chests[i].keys[j]]--;
				if (chests[i].keys[j] != chests[i].open) indep[chests[i].keys[j]]++;
			}
			need[chests[i].open]++;
			keys[chests[i].open]++;
			chests[i].opened = false;
			//cout << "OUT: " << i+1 << endl;
			//system("PAUSE");
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;

	int k, tmp, tmp2;
	for (int it=0; it<t; ++it) {
		ans.clear();
		for (int i=0; i<201; ++i) {
			chests[i].keys.clear();
			keys[i]=need[i]=all[i]=indep[i]=0;
		}

		cin >> k >> n;
		for (int i=0; i<k; ++i) {
			cin >> tmp;
			keys[tmp]++;
			all[tmp]++;
			//indep[tmp]++;
		}
		for (int i=0; i<n; ++i) {
			chests[i].opened = false;
			cin >> chests[i].open;
			need[chests[i].open]++;
			cin >> tmp;
			for (int j=0; j<tmp; ++j) {
				cin >> tmp2;
				all[tmp2]++;
				if (chests[i].open != tmp2) {
					indep[tmp2]++;
				}
				chests[i].keys.push_back(tmp2);
			}
		}

		bool fail=false;
		for (int i=0; i<n && !fail; ++i) {
			if (all[i]<need[i]) {
				fail=true;
			}
		}

		if (!fail && find()) {
			cout << "Case #" << it+1 << ": ";
			for (int i=ans.size()-1; i>=0; --i)
				cout << ans[i]+1 << " ";
			cout << endl;
		} else cout << "Case #" << it+1 << ": IMPOSSIBLE" << endl;
	}

	//system("PAUSE");
	return 0;
}