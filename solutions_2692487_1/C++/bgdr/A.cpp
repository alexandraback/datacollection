#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int T, c, A, N;
	vector<int> motes;
	cin >> T;
	for(int c = 1; c <= T; ++c){
		motes.clear();
		cin >> A >> N;
		for(int i = 0; i < N; ++i) { int m; cin >> m; motes.push_back(m); }
		sort(motes.begin(), motes.end());
		int cans = 0;
		int ans = N;
		if (A == 1){
			cout << "Case #" << c << ": " << N << endl;
			continue;
		}
		for(int i = 0; i < N; ++i){
			if(A > motes[i]) A += motes[i]; else {
				if(cans + N - i < ans) ans = cans + N - i;
				int needed = 0;
				while(A <= motes[i]){
					needed++;
					A += A-1;
				}
				cans += needed;
				A += motes[i];
			}
		}
		if(cans < ans) ans = cans;
		cout << "Case #" << c << ": " << ans << endl;


	}
	return 0;
}
