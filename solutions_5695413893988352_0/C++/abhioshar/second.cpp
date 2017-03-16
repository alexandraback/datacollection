#include <bits/stdc++.h>

using namespace std;

vector<string> sa, sb;
string a, b;
int n;

int num(string str) {
	//cout<<"str is "<<str<<endl;
	int ns = str.size();
	int ans = 0;
	for(int i = 0; i < ns; ++i) {
		ans = ans*10 + (str[i]-'0');
	}
	return ans;
}

string tostr(int x) {
	stringstream ss;
	ss << x;
	string ans = ss.str();
	//cout<<"ret "<<ans<<endl;
	return ans;
}

void fa(string s, int i) {
	if(i == n) {
		sa.push_back((s));
		return;
	}
	if(a[i] != '?') {
		s += a[i];
		fa(s, i+1);
	}
	else {
		for(int j = 0; j <= 9; ++j) {
			fa(s+tostr(j), i+1);
		}
	}
}

void fb(string s, int i) {
	if(i == n) {
		sb.push_back((s));
		return;
	}
	if(b[i] != '?') {
		s += b[i];
		fb(s, i+1);
	}
	else {
		for(int j = 0; j <= 9; ++j) {
			fb(s+tostr(j), i+1);
		}
	}
}


int main(void) {

	ifstream fin;
	ofstream fout;
	fin.open("B-small-attempt1.in");
	fout.open("output.out");

	int tt;
	fin>>tt;
	for(int t = 1; t <= tt; ++t) {
		cout<<t<<endl;
		sa.clear();
		sb.clear();
		fin>>a>>b;
		//cout<<a<<" "<<b<<endl;
		n = a.size();
		string s = "";
		s.clear();
		fa(s, 0);
		s.clear();
		fb(s, 0);
		int minans = 100000000;
		string ans1, ans2;
		for(int i = 0; i < sa.size(); ++i) {
			for(int j = 0; j < sb.size(); ++j) {
				string aa = sa[i];
				string bb = sb[j];
				int na = num(aa);
				int nb = num(bb);
				//cout<<na<<" "<<nb<<endl;
				if(abs(na-nb) <= minans) {
					if(abs(na-nb) < minans) {
						ans1 = aa;
						ans2 = bb;
						minans = abs(na-nb);
					}
					else {
						if(na < num(ans1)) {
							ans1 = aa;
							ans2 = bb;
						} 
						else if(na == num(ans1)) {
							if(nb < num(ans2)) {
								ans1 = aa;
								ans2 = bb;
							}
						}
					}
				}
			}
		}
		fout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<"\n";

	}




	fin.close();
	fout.close();
	return 0;
}

