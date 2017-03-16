# include <bits/stdc++.h>
using namespace std;

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		string s; cin >> s;
		map<char, int> mp;
		for(int i=0; i<s.size(); ++i) {
			mp[s[i]] += 1;
		}
		
		auto dd = [&](string ss, int cnt) {
			for(int i=0; i<ss.size(); ++i) {
				mp[ss[i]] -= cnt;
			}
		};
		
		vector<int> ans(10, 0);
		
		ans[6] = mp['X'];
		dd("SIX", ans[6]);
		
		ans[8] = mp['G'];
		dd("EIGHT", ans[8]);
		
		ans[0] = mp['Z'];
		dd("ZERO", ans[0]);
		
		ans[2] = mp['W'];
		dd("TWO", ans[2]);
		
		ans[7] = mp['S'];
		dd("SEVEN", ans[7]);
		
		ans[5] = mp['V'];
		dd("FIVE", ans[5]);
		
		ans[4] = mp['F'];
		dd("FOUR", ans[4]);
		
		ans[1] = mp['O'];
		dd("ONE", ans[1]);
		
		ans[9] = mp['N']/2;
		dd("NINE", ans[9]);
		
		ans[3] = mp['T'];
		dd("THREE", ans[3]);
		
		printf("Case #%d: ", T_);
		for(int i=0; i<10; ++i) {
			for(int k=0; k<ans[i]; ++k) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
	
	return 0;
}