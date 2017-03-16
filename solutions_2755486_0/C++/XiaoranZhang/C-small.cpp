#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int Ncase, limit = 676060;
	int wall[2][2000];
	int n[20], d[20], w[20], e[20], s[20], dd[20], dp[20], ds[20];
	
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		int N, ans = 0;
		memset(wall, 0, sizeof(wall));
		
		cin >> N;
		for (int i = 0; i < N; i ++) {
			cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
		}
		
		int t = 0;
		for (int i = 0; i <= limit; i ++) {
			memcpy(wall[1 - t], wall[t], sizeof(wall[1 - t]));
			
			for (int j = 0; j < N; j ++) {
				int p  = i - d[j];
				
				if (p >= 0 && p % dd[j] == 0 && p / dd[j] < n[j]) {
					// Attack!
					bool succ = false;
					p = p / dd[j];
					int f = s[j] + ds[j] * p;
					int left = (w[j] + p * dp[j] + 500) * 2;
					int right = (e[j] + p * dp[j] + 500) * 2;
					for (int u = left; u <= right; u ++) {
						if (wall[t][u] < f) {
							succ = true;
							break;
						}
					}
					
					if (succ) {
						//Success!
						ans ++;
						for (int u = left; u <= right; u ++) {
							if (wall[1 - t][u] < f) {
								wall[1 - t][u] = f;
							}
						}
					} 
				}
			}
			
			t = 1 - t;
		}
		
		cout << "Case #" << T << ": " << ans << endl;
	}
	
	return 0;
}
