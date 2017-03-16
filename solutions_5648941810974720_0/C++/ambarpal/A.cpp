#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ll test; scanf("%lld", &test);
	for (ll t = 1; t <= test; t++){
		string s; cin >> s;
		string num[] = {"ZERO", "TWO", "FOUR", "ONE", "FIVE", "SIX", "EIGHT", "THREE", "SEVEN", "NINE"};
		int mapping[] = {0, 2, 4, 1, 5, 6, 8, 3, 7, 9};
		int msk[2010]; for (int i = 0; i < 2010; i++) msk[i] = 1;
		int number[10]; for (int i = 0; i <= 9; i++) number[i] = 0;
		for (int i = 0; i <= 9; i++){
			int fnd = 1;
			while (fnd){
				vector<int> taken;
				for (int j = 0; j < num[i].size(); j++){
					fnd = 0;
					for (int k = 0; k < s.size(); k++){
						if (num[i][j] == s[k] && msk[k] == 1){
							msk[k] = 0;
							fnd = 1;
							taken.push_back(k);
							break;
						}
					}
					if (fnd == 0){
						for (int l = 0; l < taken.size(); l++)
							msk[taken[l]] = 1;
						break;
					}
				}
				if (fnd == 1) number[i]++;
			}
			//~ for (int i = 0; i < s.size(); i++) cout << msk[i];
			//~ cout << endl;
		}
		for (int i = 0; i < s.size(); i++) if (msk[i] == 1) cout << "PROBLEM";
		vector<int> dig;
		for (int i = 0; i <= 9; i++){
			for (int j = 0; j < number[i]; j++) dig.push_back(mapping[i]);
		}
		sort(dig.begin(), dig.end());
		printf("Case #%lld: ", t);
		for (int i = 0; i < (int)dig.size(); i++) printf("%d", dig[i]);
		printf("\n");
	}
	return 0;
}
