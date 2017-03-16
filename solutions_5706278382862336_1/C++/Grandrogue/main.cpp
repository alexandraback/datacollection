#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("out.txt");

long long gcd (long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

void get(string s, long long &a, long long &b) {
	int pos=s.find('/');
	a=0;
	b=0;
	for(int i=0;i<pos;i++) {
		a=a*10+s[i]-'0';
	}
	for(int i=pos+1;i<s.length();i++) {
		b=b*10+s[i]-'0';
	}
}

int main() {
	int tests;
	fin >> tests;
	for(int _t = 0; _t < tests; _t++) {
		long long res=0;
		string s;
		fin>>s;
		long long q,p,gc;
		get(s,p,q);
		gc=gcd(p,q);
		p/=gc;
		q/=gc;
		long long two=1;
		while(two<q) {
			two*=2;
		}
		if(two!=q) res=-1; else
		while(q>p) {
			q/=2;
			res++;
		}
		if(res==-1)
		fout << "Case #" << _t+1 << ": impossible" << endl; else
		fout << "Case #" << _t+1 << ": " << res << endl;
	}
	return 0;
}