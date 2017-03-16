#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int s[6] = {0, 1, 4, 9, 121, 484};

typedef struct {
	int a, b, c;
} com;

vector<string> v[52];
vector<com> vc;

int scount(int n, bool bSelf){
	int ret = 0;
	while (ret<6 && s[ret]<=n) {
		++ret;
	}
	if(s[ret-1]==n && !bSelf) return (ret-1);
	return ret;
}

int toInt(string n){
	int ret = 0;
	for (int i=0; i<n.length(); ++i) {
		ret = ret*10+n[i]-'0';
	}
	return ret;
}


int ndigit(int n){
	int ret=0;
	for (int i=1, j=1, k=1; i<=3; ++i) {
		if (i<=(n/2-1)) {
			k*=(n/2-i);
			ret += k/j;
			j*=(i+1);
		} else {
			break;
		}
	}
	if (n%2) {//odd
		ret *= 2;
		ret += 4+n/2;
	} else {
		ret += 2;
	}
	
	return ret;
}

void save(const string& org, const int& k){
	string dst = org.c_str();
	v[k].push_back(dst);
}

int solve(string n, bool bSelf){
	if (n.length()<=4) return scount(toInt(n), bSelf);
	
	int ret = 6;
	int l = n.length(), i;
	for (i=3; (i*2-1)<l; ++i) {
		ret += v[i].size();
	}
	if (l%2==0) return ret;
	
	l = l/2+1;
	for (i=0; i<v[l].size(); ++i) {
		if (n>v[l][i]) ++ret;
		else if(n==v[l][i] && bSelf) ++ret;
		else break;
	}
	return ret;
}

void fillVc(){
	int i, j, k;
	for (i=1; i<=25; ++i) {
		com c1 = {i, i, i};
		vc.push_back(c1);
		for (j=i+1; j<=25; ++j) {
			com c2 = {i, i, j};
			vc.push_back(c2);
			for (k=j+1; k<=25; ++k) {
				com c3 = {i, j, k};
				vc.push_back(c3);
			}
		}
	}
}

void fillDigitN(int n){
	if (n%2) {
		string st;
		int k=n/2-1, i, j;
		
		for (i=0; i<n*2-1; ++i) st[i] = '0';
		st[0]='1'; st[n/2]='1'; st[n-1]='1';
		save(st, n);
		st[0]='1'; st[n/2]='0'; st[n-1]='1';
		save(st, n);
		st[0]='1'; st[n/2]='2'; st[n-1]='1';
		save(st, n);
		st[0]='2'; st[n/2]='1'; st[n-1]='2';
		save(st, n);
		st[0]='2'; st[n/2]='0'; st[n-1]='2';
		save(st, n);
		
		for (i=0; i<vc.size(); ++i) {
			if (vc[i].c>k) continue;
			for (j=0; j<n*2-1; ++j) st[j] = '0';
			st[vc[i].a] = '1'; st[n-1-vc[i].a] = '1';
			st[vc[i].b] = '1'; st[n-1-vc[i].b] = '1';
			st[vc[i].c] = '1'; st[n-1-vc[i].c] = '1';
			st[0]='1'; st[n/2]='1'; st[n-1]='1';
			save(st, n);
			st[0]='1'; st[n/2]='0'; st[n-1]='1';
			save(st, n);
			if (vc[i].a==vc[i].b && vc[i].b==vc[i].c) {
				st[0]='1'; st[n/2]='2'; st[n-1]='1';
				save(st, n);
			}
		}
	} else {
		string st;
		int k = n/2-1, i, j;
		
		for (i=0; i<n*2-1; ++i) st[i] = '0';
		st[0]='1'; st[n-1]='1';
		save(st, n);
		st[0]='2'; st[n-1]='2';
		save(st, n);
		
		for (i=0; i<vc.size(); ++i) {
			if (vc[i].c>k) continue;
			for (j=0; j<n*2-1; ++j) st[j] = '0';
			st[vc[i].a] = '1'; st[n-1-vc[i].a] = '1';
			st[vc[i].b] = '1'; st[n-1-vc[i].b] = '1';
			st[vc[i].c] = '1'; st[n-1-vc[i].c] = '1';
			st[0]='1'; st[n-1]='1';
			save(st, n);
		}
	}
}

void square(string& st){
	int i, j;
	string n = st.c_str();
	int l = n.length()/2+1;
	for (i=0; i<l; ++i) n[i] -= '0';
	for (i=0; i<n.length(); ++i) st[i] = '0';
	for (i=0; i<l; ++i) {
		for (j=0; j<l; ++j) {
			st[i+j] += n[i]*n[j];
		}
	}
}

int main(){
	int t, i, j;
	string a, b;
	int sa, sb;
	cin >> t;
	
	fillVc();
	for (i=3; i<=51; ++i) {
		fillDigitN(i);
		sort(v[i].begin(), v[i].end());
		for (j=0; j<v[i].size(); ++j) {
			square(v[i][j]);
		}
	}
	
	for (i=0; i<t; ++i) {
		cin >> a >> b;
		
		sa = solve(a, false);
		sb = solve(b, true);
		
		cout << "Case #" << (i+1) <<": "<<sb-sa<<endl;
	}
	
	return 0;
}