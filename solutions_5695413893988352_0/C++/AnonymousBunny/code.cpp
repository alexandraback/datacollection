#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
int toint (string s){
	int t=1;
	int res=0;
	for (int i=s.size()-1; i>=0; i--){
		res+=(s[i]-'0')*t;
		t=t*10;
	}
	return res;
}

string tos (int n, int sz){
	vector <char> v;
	while (n){
		v.push_back(n%10+'0');
		n=n/10;
	}
	while (v.size()!=sz) v.push_back('0');
	reverse(v.begin(), v.end());
	string s="";
	for (int i=0; i<v.size(); i++) s+=v[i];
	return s;
}

bool canobt (string s, int p){
	string q= tos(p, s.size());
	for (int i=0; i<s.size(); i++){
		if (s[i]!='?' and s[i]!=q[i]) return 0;
	}
	return 1;
}

vector <pii> res;

bool cmp (pii x, pii y){
	if (abs(x.F-x.S)!=abs(y.F-y.S)) return (abs(x.F-x.S)<abs(y.F-y.S));
	if (x.F!=y.F) return x.F<y.F;
	return x.F<y.S;
}

void check (string x, string y){
	int n= x.size();
	int ln= 1;
	for (int i=0; i<n; i++) ln= ln*10;
	for (int i=0; i<ln; i++){
		if (!canobt(x, i)) continue;
		for (int j=0; j<ln; j++){
			if (!canobt(y, j)) continue;
			res.push_back(mp(i, j));
		}
	}
}

int uu;

void print (int n){
	pii c= mp(1000000, 20000000);
	for (int i=0; i<res.size(); i++) if (cmp(res[i], c)) c= res[i];
	cout<<"Case #"<<uu<<": "<<tos(c.F, n)<<" "<<tos(c.S, n)<<endl;
}



int main() {
	// your code goes here
	int t;
	cin>>t;
	for (uu=1; uu<=t; uu++){
		res.clear();
		string p, q;
		cin>>p>>q;
		check(p, q);
		print(p.size());
	}
	return 0;
}
