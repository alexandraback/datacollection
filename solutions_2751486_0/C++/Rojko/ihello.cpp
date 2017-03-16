#include<iostream>
//#include<cstdio>
#include<cstring>
#include<vector>
//#include<algorithm>

using namespace std;

typedef unsigned long long ll;

ll count(string s, ll n) {
	ll ret = 0;
	for (ll i = 0; i<s.length(); ++i) {
		ll poc = 0;
		for (ll j = i; j<s.length(); ++j) {
			char c = s[j];
			if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
				poc++;
			} else {
				poc = 0;
			}
			if (poc >= n) { 
				ret+=(s.length()-j);
				break;
			}
		}
	}
	return ret;
}

int main(){
	ll T;
	cin >> T;
	for (ll t = 0; t<T; ++t) {
		string s;
		ll n;
		cin >> s;
		cin >> n;
		cout << "Case #" << t+1 << ": ";
		cout << count(s,n);
		cout << endl;
	}
	return 0;
}
