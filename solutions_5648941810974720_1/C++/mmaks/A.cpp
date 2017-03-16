#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("inAs.txt", "r", stdin);
	freopen("outAs.txt", "w", stdout);


	ll t;
	cin>>t;
	for(int cases = 1; cases <= t; cases ++) {

		cout<<"Case #"<<cases<<": ";
		string s;
		cin>>s;
		ll n = s.size();

		map<char, int> mp;
		for(int i=0;i<n;i++) {
			mp[s[i]] ++;
		}
		string ans;
		while( mp.find('Z') != mp.end() && (mp['Z'] != 0) ) {
			ans += '0';
			mp['Z']--;
			mp['E']--;
			mp['R']--;
			mp['O']--;
		}
		
		while( mp.find('X') != mp.end() && (mp['X'] != 0) ) {
			ans += '6';
			mp['S']--;
			mp['I']--;
			mp['X']--;
		}

		while( mp.find('W') != mp.end() && (mp['W'] != 0) ) {
			ans += '2';
			mp['T']--;
			mp['W']--;
			mp['O']--;
		}

		while( mp.find('G') != mp.end() && (mp['G'] != 0) ) {
			ans += '8';
			mp['E']--;
			mp['I']--;
			mp['G']--;
			mp['H']--;
			mp['T']--;
		}

		while( mp.find('U') != mp.end() && (mp['U'] != 0) ) {
			ans += '4';
			mp['F']--;
			mp['O']--;
			mp['U']--;
			mp['R']--;
		}

		while( mp.find('T') != mp.end() && (mp['T'] != 0) ) {
			ans += '3';
			mp['T']--;
			mp['H']--;
			mp['R']--;
			mp['E']--;
			mp['E']--;
		}

		
		while( mp.find('F') != mp.end() && (mp['F'] != 0) ) {
			ans += '5';
			mp['F']--;
			mp['I']--;
			mp['V']--;
			mp['E']--;
		}


		while( mp.find('O') != mp.end() && (mp['O'] != 0) ) {
			ans += '1';
			mp['O']--;
			mp['N']--;
			mp['E']--;
		}
		//cout<<s<<"\n";

		while( mp.find('S') != mp.end() && (mp['S'] != 0) ) {
			ans += '7';
			mp['S']--;
			mp['E']--;
			mp['V']--;
			mp['E']--;
			mp['N']--;
		}
		//cout<<s<<"\n";
		
		while( mp.find('I') != mp.end() && (mp['I'] != 0) ) {
			ans += '9';
			mp['N']--;
			mp['I']--;
			mp['N']--;
			mp['E']--;
		}


		sort(ans.begin(), ans.end());
		cout<<ans<<"\n";
	}
	return 0;
}