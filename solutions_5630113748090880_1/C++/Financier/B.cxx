# include <bits/stdc++.h>
using namespace std;

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		int n; cin >> n;
		map<int, bool> ans;
		for(int i=0; i<2*n-1; ++i) {
			for(int k=0; k<n; ++k) {
				int t; scanf("%d", &t);
				ans[t] = 1 - ans[t];
			}
		}
		
		vector<int> srt;
		for(auto t:ans) {
			if (t.second) {
				srt.push_back(t.first);
			}
		}
		sort(srt.begin(), srt.end());
		
		printf("Case #%d: ", T_);
		for(int i=0; i<srt.size(); ++i) {
			printf("%d ", srt[i]);
		}
		printf("\n");
		
		if (srt.size() != n) {
			cerr << T_ << " - " << srt.size() << endl;
		}
	}
	return 0;
}