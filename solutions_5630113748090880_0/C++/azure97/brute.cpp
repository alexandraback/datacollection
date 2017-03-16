#include <bits/stdc++.h>
using namespace std;

vector<int> v[25];
int arr[25][25];
int n;

bool can(int mode,int idx,int pos) {
	bool ok = 1;
	if(mode == 0) {
		for(int i = 0 ; i < n ; i++)
			ok &= (arr[pos][i] == -1 || arr[pos][i] == v[idx][i]);
	}
	else {
		for(int i = 0 ; i < n ; i++)
			ok &= (arr[i][pos] == -1 || arr[i][pos] == v[idx][i]);	
	}
	return ok;
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		cin >> n;
		for(int i = 0 ; i < 2 * n - 1 ; i++) {
			v[i].clear();
			for(int j = 0 ; j < n ; j++) {
				int x;
				cin >> x;
				v[i].push_back(x);
			}
		}
		int nn = 2*n - 1;
		sort(v,v + nn);
		vector<int> ans;

		for(int bm = 0 ; bm < (1<<nn) ; bm++)
			if(__builtin_popcount(bm) == n) {
				int las = 0;
				for(int i = 0 ; i < nn ; i++)
					if(bm & (1<<i)) {
						for(int j = 0 ; j < n ; j++)
							arr[las][j] = v[i][j];
						las++;
					}
				las = 0;
				vector<int> unmatched;
				for(int i = 0 ; i < nn ; i++) {
					if(bm & (1<<i)) continue;
					while(las < n && !can(1,i,las)) {
						unmatched.push_back(las);
						las++;
					}
					las++;
				}
				while(las < n)
					unmatched.push_back(las), las++;
				//cerr << "SAIZ " << unmatched.size() << endl;
				if(unmatched.size() == 1) {
					int tem = unmatched[0];
					for(int i = 0 ; i < n ; i++)
						ans.push_back(arr[i][tem]);
					break;
				}
			}
		cerr << tc << endl;
		assert(ans.size() == n);	
		printf("Case #%d:",tc);
		for(int x : ans) {
			printf(" %d",x);
			assert(x != -1);
		}
		puts("");	
	}		
	return 0;
}