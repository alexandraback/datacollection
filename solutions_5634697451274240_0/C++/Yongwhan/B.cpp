#include<bits/stdc++.h>
using namespace std;

string trim(string s) {
	int n=s.size(), cur=-1;
	for (int i=n-1; i>=0; i--)
		if(s[i]=='+') cur=i;
		else break;

	if(cur==-1) return s;

	string ret;
	for (int i=0; i<cur; i++)
		ret+=s[i];
	return ret;
}

int eval(string s) {
	// remove last +'s
	s=trim(s);
	if(s.empty()) return 0;

	int ret=0;
	int n=s.size();
	bool up=false;
	for (int i=0; i<n; i++) {
		if(s[i]=='+') s[i]='-', up=true;
		else break;
	}
	if(up) ret++;

	for (int i=0; i<n/2; i++)
		swap(s[i], s[n-1-i]);
	for (int i=0; i<n; i++)
		if(s[i]=='+') s[i]='-';
		else s[i]='+';
	ret++;

	ret+=eval(s);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		string s; cin>>s;
		cout << "Case #" << c << ": " << eval(s) << endl;
	}
	return 0;
}
