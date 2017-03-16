#include <iostream>
#include <cstring>
using namespace std;
int T, ans[10], letters[30]; string s;
int main() {
	cin>>T;
	for (int t=1; t<=T; t++){
		cin>>s;
		memset (ans, 0, sizeof ans);
		memset (letters, 0, sizeof letters);
		for (int i=0; i<s.length(); i++)
			letters[s[i]-'A']++;
		while (letters['Z'-'A']>0) {
			letters['Z'-'A']--;
			letters['E'-'A']--;
			letters['R'-'A']--;
			letters['O'-'A']--;
			ans[0]++;
		}
		while (letters['G'-'A']) {
			letters['E'-'A']--;
			letters['I'-'A']--;
			letters['G'-'A']--;
			letters['H'-'A']--;
			letters['T'-'A']--;
			ans[8]++;
		}
		while (letters['X'-'A']) {
			letters['S'-'A']--;
			letters['I'-'A']--;
			letters['X'-'A']--;
			ans[6]++;
		}
		while (letters['W'-'A']) {
			letters['T'-'A']--;
			letters['W'-'A']--;
			letters['O'-'A']--;
			ans[2]++;
		}
		while (letters['U'-'A']) {
			letters['F'-'A']--;
			letters['O'-'A']--;
			letters['U'-'A']--;
			letters['R'-'A']--;
			ans[4]++;
		}
		while (letters['V'-'A']) {
			letters['F'-'A']--;
			letters['I'-'A']--;
			letters['V'-'A']--;
			letters['E'-'A']--;
			ans[5]++;
		}
		while (letters['R'-'A']) {
			letters['T'-'A']--;
			letters['H'-'A']--;
			letters['R'-'A']--;
			letters['E'-'A']--;
			letters['E'-'A']--;
			ans[3]++;
		}
		while (letters['V'-'A']) {
			letters['S'-'A']--;
			letters['E'-'A']--;
			letters['V'-'A']--;
			letters['E'-'A']--;
			letters['N'-'A']--;
			ans[7]++;
		}
		while (letters['O'-'A']) {
			letters['O'-'A']--;
			letters['N'-'A']--;
			letters['E'-'A']--;
			ans[1]++;
		}
		while (letters['I'-'A']) {
			letters['N'-'A']--;
			letters['N'-'A']--;
			letters['I'-'A']--;
			letters['E'-'A']--;
			ans[9]++;
		}
		cout<<"Case #"<<t<<": ";
		for (int i=0; i<=9; i++) {
			while (ans[i]-->0) cout<<i;
		}
		cout<<endl;
	}
	return 0;
}
