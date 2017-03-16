#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int nums[1024];

int main(){
	int tests;

	cin >> tests;

	for(int test = 1; test <= tests; ++test){
		int ans = INT_MAX;
		int mx = 0;
		int n;

		cin >> n;
		for(int i = 0; i < n; ++i){
			int p;
			cin >> p;
			nums[i] = p;
			if(p > mx) mx = p;
		}

		for(int i = 1; i <= mx; ++i){
			int cuts = 0;
			for(int j = 0; j < n; ++j){
				if(nums[j] > i){
					cuts += (nums[j] + i-1)/i-1;
				}
			}

			if(cuts + i < ans) ans = cuts + i;
		}

		cout << "Case #" << test << ": " << ans << endl;
	}
}
