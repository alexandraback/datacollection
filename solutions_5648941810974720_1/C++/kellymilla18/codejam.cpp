#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

/*
0 - Z
2 - W
4 - U
6 - X
8 - G
5 - F
1 - O
3 - T
7 - S
9 - N

*/

int a[30];
int ans[1000];
main(){
	ios::sync_with_stdio(0);
	freopen("A-Large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	string s;
	cin >> t;
	while(t--) {
		int ctr = 0;
		cin >> s;
		cout << "Case #" << c++ << ": ";
		memset(a, 0, sizeof(a));
		for(int i = 0; i < s.length(); i++) 
			a[s[i]-'A']++;
		while(a['Z'-'A'] > 0) {
			a['Z'-'A']--;
			a['E'-'A']--;
			a['R'-'A']--;
			a['O'-'A']--;
			ans[ctr++] = 0;			
		}
		
		while(a['W'-'A'] > 0) {
			a['T'-'A']--;
			a['W'-'A']--;
			a['O'-'A']--;
			ans[ctr++] = 2;			
		}
		
		while(a['U'-'A'] > 0) {
			a['F'-'A']--;
			a['O'-'A']--;
			a['U'-'A']--;
			a['R'-'A']--;
			ans[ctr++] = 4;			
		}
		
		while(a['X'-'A'] > 0) {
			a['S'-'A']--;
			a['I'-'A']--;
			a['X'-'A']--;
			ans[ctr++] = 6;			
		}
		
		while(a['G'-'A'] > 0) {
			a['E'-'A']--;
			a['I'-'A']--;
			a['G'-'A']--;
			a['H'-'A']--;
			a['T'-'A']--;
			ans[ctr++] = 8;			
		}
		
		while(a['F'-'A'] > 0) {
			a['F'-'A']--;
			a['I'-'A']--;
			a['V'-'A']--;
			a['E'-'A']--;
			ans[ctr++] = 5;			
		}
		
		while(a['O'-'A'] > 0) {
			a['O'-'A']--;
			a['N'-'A']--;
			a['E'-'A']--;
			ans[ctr++] = 1;			
		}
		
		while(a['T'-'A'] > 0) {
			a['T'-'A']--;
			a['H'-'A']--;
			a['R'-'A']--;
			a['E'-'A']-=2;
			ans[ctr++] = 3;			
		}
		
		while(a['S'-'A'] > 0) {
			a['S'-'A']--;
			a['E'-'A']-=2;
			a['V'-'A']--;
			a['N'-'A']--;
			ans[ctr++] = 7;			
		}
		
		while(a['N'-'A'] > 0) {
			a['N'-'A']-=2;
			a['I'-'A']--;
			a['E'-'A']--;
			ans[ctr++] = 9;			
		}
		
		sort(ans, ans+ctr);
		for(int i = 0; i < ctr; i++)
			cout << ans[i];
		cout << endl;
		
	}
}

