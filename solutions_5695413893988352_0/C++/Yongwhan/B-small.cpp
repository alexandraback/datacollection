#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

bool cmp(ii x, ii y) {
	int a=abs(x.first-x.second);
	int b=abs(y.first-y.second);
	if(a==b) {
		if(x.first==y.first) return x.second<y.second;
		else return x.first<y.first;
	} else return a<b;
}

string eval(int n, int sz) {
	stringstream ss; ss<<n;
	string s=ss.str();
	while(s.size()<sz) s='0'+s;
	return s;
}

bool ok(int n, string s) {
	int sz=s.size();
	stringstream ss; ss<<n;
	string t=ss.str();
	if(t.size()>s.size()) return false;
	string cur=eval(n,sz);
	for (int i=0; i<sz; i++) {
		if(s[i]=='?') {
		} else {
			if(s[i]!=cur[i]) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		string s,t; cin>>s>>t;
		vector<ii> ret;

		vector<int> x,y;
		for (int i=0; i<1000; i++)
			if(ok(i,s)) x.push_back(i);
		for (int i=0; i<1000; i++)
			if(ok(i,t)) y.push_back(i);

		int n=x.size(), m=y.size();
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				ret.push_back(make_pair(x[i],y[j]));
		sort(ret.begin(), ret.end(), cmp);

		cout << "Case #" << c << ": " << eval(ret[0].first,s.size()) << " " << eval(ret[0].second,t.size()) << endl;
	}
	return 0;
}
