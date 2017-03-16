#include <bits/stdc++.h>
using namespace std;

int f(int n){
	int ans = 0;
	for(int i = 0; (1<<i) <= n; i++)
		if((1<<i)&n)
			ans++;
	return ans;
}

int main(){
	int T;
	cin >> T;

	for(int t = 0; t < T; t++){
		int j, p, s;
		size_t k;
		cin >> j >> p >> s >> k;
		int n = j*p*s, ans = 0;
		vector< vector<int> > ans_a;
		vector< vector<int> > a;
		for(int i = 0; i < j; i++)
			for(int l = 0; l < p; l++)
				for(int r = 0; r < s; r++)
					a.push_back({i, l, r});
		if(j <= (int) k && p <= (int) k && s <= (int) k)
			ans = n, ans_a = a;
		else
		for(int mask = (1<<n)-1; mask >= 1; mask--){
			if(f(mask) <= ans)
				continue;
			multiset< pair<int, int> > jp, js, ps;
			vector< vector<int> > _a;
			int z = 0;
			bool fail = false;
			for(int i = 0; i < n; i++){
				if(mask&(1<<i)){
					int _j = a[i][0], _p = a[i][1], _s = a[i][2];
					if(jp.count({_j, _p}) >= k || js.count({_j, _s}) >= k || ps.count({_p, _s}) >= k){
						fail = true;
						break;
					}
					jp.insert({_j, _p});
					js.insert({_j, _s});
					ps.insert({_p, _s});
					_a.push_back({_j, _p, _s});
					z++;
				}
			}
			if(!fail && z > ans)
				ans = z, ans_a = _a;
		}
		cout << "Case #" << t+1 << ": " << ans << endl;
		for(int i = 0; i < ans; i++)
			cout << ans_a[i][0]+1 << " " << ans_a[i][1]+1 << " " << ans_a[i][2]+1 << endl;
	}

	return 0;
}
