#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
signed main() {
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	for(int t=1;t<=tt;t++){
		cout << "Case #" << t << ": ";
		string s;
		cin >> s;
		int n = s.length();
		int a[26];
		memset(a,0,sizeof(a));
		int c[10];
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++) a[s[i]-'A']++;
		while(a['X'-'A']!=0){
			c[6]++;
			a['X'-'A']--;
			a['I'-'A']--;
			a['S'-'A']--;
		}
		while(a['Z'-'A']!=0){
			c[0]++;
			a['Z'-'A']--;
			a['E'-'A']--;
			a['R'-'A']--;
			a['O'-'A']--;
		}
		while(a['U'-'A']!=0){
			c[4]++;
			a['F'-'A']--;
			a['U'-'A']--;
			a['R'-'A']--;
			a['O'-'A']--;
		}
		while(a['F'-'A']!=0){
			c[5]++;
			a['F'-'A']--;
			a['I'-'A']--;
			a['V'-'A']--;
			a['E'-'A']--;
		}
		while(a['G'-'A']!=0){
			c[8]++;
			a['G'-'A']--;
			a['I'-'A']--;
			a['H'-'A']--;
			a['E'-'A']--;
			a['T'-'A']--;
		}
		
		while(a['I'-'A']!=0){
			c[9]++;
			a['N'-'A']--;
			a['I'-'A']--;
			a['N'-'A']--;
			a['E'-'A']--;
		}
		
		while(a['W'-'A']!=0){
			c[2]++;
			a['T'-'A']--;
			a['W'-'A']--;
			a['O'-'A']--;
		}
		while(a['R'-'A']!=0){
			c[3]++;
			a['R'-'A']--;
			a['E'-'A']--;
			a['H'-'A']--;
			a['E'-'A']--;
			a['T'-'A']--;
		}
		while(a['O'-'A']!=0){
			c[1]++;
			a['O'-'A']--;
			a['E'-'A']--;
			a['N'-'A']--;
		}
		c[7] += a['S'-'A'];
		for(int i=0;i<=9;i++){
			while(c[i]!=0){
				cout << i;
				c[i]--;
			}
		}
		cout << "\n";
	}
    return 0;
}
