#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void big(string::iterator b, string::iterator e) {
	while (b!=e) {
		if (*b=='?') *b='0';
		b++;
	}
}

void small(string::iterator b, string::iterator e) {
	while (b!=e) {
		if (*b=='?') *b='9';
		b++;	
	}
}

bool eq(string &a, string &b, int e) {
	for (int i=0; i<e; i++) {
		if ((a[i]!='?')&&(b[i]!='?')) if (a[i]!=b[i]) return false;
		if ((a[i]=='?')&&(b[i]=='?')) a[i]=b[i]='0';
		if (a[i]!='?') b[i]=a[i];
		if (b[i]!='?') a[i]=b[i];
	}
	return true;
}

ll diff(string &a, string &b) {
	ll x=0, y=0;
	for (int i=0; i<a.size(); i++) x*=10, x+=a[i]-'0', y*=10, y+=b[i]-'0';
	return abs(x-y); 
}

int main() {
	int T; cin>>T;
	
	for (int testCase=1; testCase<=T; testCase++) {
		string C, J; cin>>C>>J;
		string winC=C, winJ=J;
		ll best=1000000000000000047LL;
		
		for (int i=0; i<C.size(); i++) {
			string c=C, j=J;
			
			if (j[i]=='9') continue;
			if (c[i]=='0') continue;
			if ((c[i]!='?')&&(j[i]!='?')) if (c[i]!=j[i]) continue;
			if ((c[i]=='?')&&(j[i]=='?')) c[i]='1', j[i]='0';
			if (c[i]!='?') j[i]=c[i]-1;
			if (j[i]!='?') c[i]=j[i]+1;
			
			if (eq(c, j, i)==false) break;
			big(c.begin()+i+1, c.end());
			small(j.begin()+i+1, j.end());
			if (diff(c, j)<=best) {
				if (c<winC) winC=c, winJ=j;
				else if (c==winC) if (j<winJ) winC=c, winJ=j;
			}
		}
		
		for (int i=0; i<C.size(); i++) {
			string c=C, j=J;
			
			if (j[i]=='0') continue;
			if (c[i]=='9') continue;
			if ((c[i]!='?')&&(j[i]!='?')) if (c[i]!=j[i]) continue;
			if ((c[i]=='?')&&(j[i]=='?')) c[i]='0', j[i]='1';
			if (j[i]!='?') c[i]=j[i]-1;
			if (c[i]!='?') j[i]=c[i]+1;
			
			if (eq(c, j, i)==false) break;
			small(c.begin()+i+1, c.end());
			big(j.begin()+i+1, j.end());
			if (diff(c, j)<=best) {
				if (c<winC) winC=c, winJ=j;
				else if (c==winC) if (j<winJ) winC=c, winJ=j;
			}
		}
		
		if (eq(C, J, C.size())==true) winC=C, winJ=J;
		cout<<"Case #"<<testCase<<": "<<winC<<" "<<winJ<<endl;
	}
	return 0;
}
