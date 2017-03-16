#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool dp[2000001];

int main(){
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int N;
		cin >> N;
		vector<int> S(N);
		for(int i = 0; i < N; ++i){ cin >> S[i]; }
		int mask = -1;
		for(int i = 1; i < (1 << N) - 1; ++i){
			int sum = 0;
			for(int j = 0; j < N; ++j){
				if(i & (1 << j)){ sum += S[j]; }
			}
			memset(dp, 0, sizeof(dp));
			dp[0] = true;
			for(int j = 0; j < N; ++j){
				if(i & (1 << j)){ continue; }
				for(int k = sum; k >= 0; --k){
					dp[k + S[j]] |= dp[k];
				}
				if(dp[sum]){ break; }
			}
			if(dp[sum]){
				mask = i;
				break;
			}
		}
		cout << "Case #" << caseNum << ":" << endl;
		if(mask < 0){
			 cout << "Impossible" << endl;
		}else{
			int sum = 0;
			for(int i = 0; i < N; ++i){
				if(mask & (1 << i)){ sum += S[i]; }
			}
			int m2 = 0;
			for(int i = 0; i < (1 << N); ++i){
				if(mask & i){ continue; }
				int s = 0;
				for(int j = 0; j < N; ++j){
					if(i & (1 << j)){ s += S[j]; }
				}
				if(s == sum){ m2 = i; break; }
			}
			vector<int> v1, v2;
			for(int i = 0; i < N; ++i){
				if(mask & (1 << i)){ v1.push_back(S[i]); }
				if(m2 & (1 << i)){ v2.push_back(S[i]); }
			}
			for(int i = 0; i < v1.size(); ++i){
				cout << v1[i] << (i == v1.size() - 1 ? "\n" : " ");
			}
			for(int i = 0; i < v2.size(); ++i){
				cout << v2[i] << (i == v2.size() - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
