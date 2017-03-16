#include<iostream>
#include<string>
using namespace std;

int pps(string& s) {
	int p[s.size() + 10];
	for(int i = 0; i < s.size() + 2; i ++) {
		p[i] = -1;
	}
	for(int i = 1; i < s.size(); i ++) {
		int t = p[i - 1];
		while(t != -1 && s[t + 1] != s[i]) {
			t = p[t];
		}
		if(s[t + 1] == s[i]) {
			p[i] = t + 1;
		}
		//cout << p[i] << " ";
	}
	//cout << endl;
	return p[s.size() - 1] + 1;
}

int bla[1000];

void rozwiaz(int t) {
	int k, l, s;
	string sk, sl;
	cin >> k >> l >> s;
	cin >> sk >> sl;
	int ps = pps(sl);
	int odp = 0;
	
	for(int i = 0; i < 300; i ++) {
		bla[i] = 0;
	}
	
	//cout << "COS" << endl;
	for(int i = 0; i < sk.size();  i ++) {
		bla[sk[i]] ++;
	}
	
	//cout << "COS" << endl;
	long double f = s - l + 1;
	
	for(int i = 0; i < sl.size(); i ++) {
		if(bla[sl[i]] == 0) {
			cout << "Case #" << t << ": 0" << endl;
			return;
		}
		f = f * (double)(bla[sl[i]]) / (double)(k);
		//cout << f << endl;
	}
	
	//cout << f;
	
	if(s >= l) {
		odp = 1 + (s - l) / (l - ps);
	}
	//cout << ps << " " << s << " " << l << " " << odp << endl;
	
	f = double(odp) - f;
	
 	cout.precision(10);
	cout << "Case #" << t << ": " << f << endl;
	
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i ++) {
		rozwiaz(i);
	}
}
