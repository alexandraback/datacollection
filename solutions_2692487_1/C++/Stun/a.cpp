#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <map>
#include <stack>

using namespace std;

int main(){
	int tcase;
	int A, N;
	vector<int> motes;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		cin >> A >> N;
		motes.resize(N);
		for(size_t i = 0; i < N; ++i) {
			cin >> motes[i];
		}
		
		sort(motes.begin(), motes.end());
		
		int sol = N;
		int cur = 0;
		for(size_t i = 0; i < N; ++i) {
			if (A > motes[i]) A += motes[i];
			else {
				// DELETE
				// cout << cur <<  " " << sol << endl;
				sol = std::min(cur + int(N - i), sol);
				if (A == 1) {
					cur = sol;
					break;
				}
				while (A <= motes[i]) {
					A += A - 1;
					cur++;
				}
				A += motes[i];
			}
		}
		sol = std::min(cur, sol);
		cout << "Case #" << casen + 1 << ": ";
		cout << sol << endl;
		
	}
	

	return 0;
}
