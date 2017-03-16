//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e2 + 9;
typedef long double ld;
ofstream fout("codejam.out");
#define cout fout
int cnt[Maxn];
ld pro[Maxn][Maxn];
ld dp[Maxn][Maxn][Maxn];
int main(){
	int tc;
	cin >> tc;
	int ts = 0;
	while(tc--){
		cout << "Case #" << ++ts << ": ";
		for(int i = 0; i < Maxn;i++)
			for(int j = 0; j < Maxn;j++){
				pro[i][j] = 0;
				for(int r = 0; r < Maxn;r++)
					dp[i][j][r] = 0;
			}
		int k,l,n;
		cin >> k >> l >> n;
		string key,pat;
		cin >> key >> pat;
		for(int i = 0; i < k;i++)
			cnt[key[i]]++;
		bool f = 0;
		for(int i = 0; i < l;i++)
			if(!cnt[pat[i]])
				f = 1;
		if(f){
			cout << setprecision(10) << fixed <<  0 << endl;
			continue;
		}
		int lw = 0;
		for(int i = 0; i < l - 1;i++){
			bool flag = 0;
			for(int j = 0; j < i + 1;j++)
				if(pat[j] != pat[l - i - 1 + j])
					flag = 1;
			if(flag) continue;
			lw = i + 1;
		}
		int pick = (n - l) / (l - lw) + 1;
		for(int j = 0; j < k;j++)
			for(int state = 0; state <= l;state++){
				string S = "";
				for(int i = 0; i < state;i++)
					S += pat[i];
				S += key[j];
				int num = 0;
				for(int i = 0; i < l;i++){
					bool flag = 0;
					for(int r = 0; r < i + 1;r++)
						if(S[state - i + r] != pat[r])
							flag = 1;
					if(flag) continue;
					num = i + 1;
				}
				pro[state][num] += 1;
			}
		for(int i = 0; i <= l;i++)
			for(int j = 0; j <= l;j++){
				pro[i][j] /= (ld)k;
			}
		dp[0][0][0] = 1;
		for(int i = 1; i <= n;i++)
			for(int state = 0; state <= l;state++){
				for(int picked = 0; picked <= n;picked++){
					for(int other = 0; other <= l;other++){
						int pk = picked;
						if(state == l) pk--;
						if(pk != -1)
							dp[i][state][picked] += dp[i-1][other][pk] * pro[other][state];
					}
				}
			}
//		for(int i = 1; i <= n;i++)
//			for(int state = 0; state <= l;state++)
//				for(int picked = 0;picked <= pick;picked++)
//					cout << i << ' ' << state << ' ' << picked << ' ' << dp[i][state][picked] << endl;
		ld ans = 0;
		pick = 0;
		for(int state = 0; state <= l;state++){
			for(int picked = 0; picked <= n;picked++){
				ans += picked * dp[n][state][picked];
				if(dp[n][state][picked] != 0) pick = max(pick,picked);
			}
		}
		cout << setprecision(10) << fixed << pick - ans << endl;
	}
	return 0;
}
