#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int eval(ll x) {
	set<char> st;
	for (char ch='0'; ch<='9'; ch++) st.insert(ch);

	for (int i=1; i<=1000000; i++) {
		ll cur=x*i;
		stringstream ss; ss<<cur;
		string s=ss.str();
		int sz=s.size();
		for (int j=0; j<sz; j++)
			if(st.find(s[j])!=st.end()) st.erase(s[j]);
		if(st.empty()) return cur;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int x; cin>>x;
		int ret=eval(x);
		cout << "Case #" << c << ": ";
		if(ret==-1) cout << "INSOMNIA" << endl;
		else cout << ret << endl;
	}
	return 0;
}
