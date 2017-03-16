#include <bits/stdc++.h>
using namespace std;

int T, TC = 1;
char S[2005], d;
int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d%c", &T, &d);
	while(T--){
		gets(S);
		int len = strlen(S), hitung[30] = {0};
		for(int i = 0; i < len; i++) hitung[S[i]-'A']++;
		vector<int> ans;
		while(len > 0){
			if(hitung['Z'-'A'] > 0) ans.push_back(0), hitung['Z'-'A']--, hitung['E'-'A']--, hitung['R'-'A']--, hitung['O'-'A']--, len -= 4;
			else if(hitung['X'-'A'] > 0) ans.push_back(6), hitung['S'-'A']--, hitung['I'-'A']--, hitung['X'-'A']--, len -= 3;
			else if(hitung['S'-'A'] > 0) ans.push_back(7), hitung['S'-'A']--, hitung['E'-'A'] -= 2, hitung['V'-'A']--, hitung['N'-'A']--, len -= 5;
			else if(hitung['V'-'A'] > 0) ans.push_back(5), hitung['F'-'A']--, hitung['I'-'A']--, hitung['V'-'A']--, hitung['E'-'A']--, len -= 4;
			else if(hitung['F'-'A'] > 0) ans.push_back(4), hitung['F'-'A']--, hitung['O'-'A']--, hitung['U'-'A']--, hitung['R'-'A']--, len -= 4;
			else if(hitung['G'-'A'] > 0) ans.push_back(8), hitung['E'-'A']--, hitung['I'-'A']--, hitung['G'-'A']--, hitung['H'-'A']--, hitung['T'-'A']--, len -= 5;
			else if(hitung['H'-'A'] > 0) ans.push_back(3), hitung['T'-'A']--, hitung['H'-'A']--, hitung['R'-'A']--, hitung['E'-'A'] -= 2, len -= 5;
			else if(hitung['T'-'A'] > 0) ans.push_back(2), hitung['T'-'A']--, hitung['W'-'A']--, hitung['O'-'A']--, len -= 3;
			else if(hitung['O'-'A'] > 0) ans.push_back(1), hitung['O'-'A']--, hitung['N'-'A']--, hitung['E'-'A']--, len -= 3;
			else ans.push_back(9), hitung['N'-'A'] -= 2, hitung['I'-'A']--, hitung['E'-'A']--, len -= 4;
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", TC++);
		for(int i = 0; i < (int)ans.size(); i++) printf("%d", ans[i]);
		puts("");
	}
	return 0;
}
