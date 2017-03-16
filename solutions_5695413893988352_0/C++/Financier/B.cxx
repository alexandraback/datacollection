# include <bits/stdc++.h>
using namespace std;

string build(int n, int l)
{
	string ret = "";
	for(int i=0; i<l; ++i) {
		ret += (n % 10) + '0';
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool can(string a, string a_)
{
	bool flag = true;
	for(int i=0; i<a.size(); ++i) {
		flag &= (a[i] == a_[i] or a[i] == '?');
	}
	return flag;
}

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		string a, b; cin >> a >> b;
		int l = a.size();
		
		int n = 1;
		for(int i=0; i<l; ++i) {
			n *= 10;
		}
		
		string aa, bb; int diff = 100500;
		for(int i=0; i<n; ++i) {
			for(int k=0; k<n; ++k) {
				string a_ = build(i, l);
				string b_ = build(k, l);
				
				if (can(a, a_) && can(b, b_)) {
					if (abs(i - k) < diff) {
						diff = abs(i - k);
						aa = a_;
						bb = b_;
					}
				}
			}
		}
		
		printf("Case #%d: %s %s\n", T_, aa.c_str(), bb.c_str());
	}
	return 0;
}