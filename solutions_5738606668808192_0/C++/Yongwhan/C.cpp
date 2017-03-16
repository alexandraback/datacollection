#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(ll x) {
	for (ll d=2; d*d<=x; d++) {
		if(x%d==0) {
			if(d!=1&&d!=x) return false;
		}
	}
	return true;
}

ll fact(ll x) {
	for (ll d=2; d*d<=x; d++)
		if(x%d==0)
			if(d!=1&&d!=x) return d;
}

ll eval(string &s, int b) {
	int n=s.size();
	ll ret=0;
	for (int i=0; i<n; i++)
		ret=ret*b+(s[i]-'0');
	return ret;
}

vector<ll> factor(string &s) {
	vector<ll> ret, empty;
	for (int b=2; b<=10; b++) {
		ll cur=eval(s,b);
		if(!isprime(cur)) ret.push_back(fact(cur));
		else return empty;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << "Case #1:" << endl;
	int ct=0;
	for (int i=0; i<(1<<16); i++) {
		string cur;
		for (int j=0; j<16; j++)
			if(i&(1<<j)) cur+='1';
			else cur+='0';

		int sz=cur.size();
		char first=cur[0], last=cur[sz-1];
		if(first=='1'&&last=='1') {
			vector<ll> ret=factor(cur);
			if(!ret.empty()) {
				cout << cur;
				for (int i=2; i<=10; i++)
					cout << " " << ret[i-2];
				cout << endl;
				ct++;
			}
		}

		if(ct==50) return 0;
	}
}
