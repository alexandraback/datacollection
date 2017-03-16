#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string tw, kb;
int mx, tot, com;

void gen_all(string w, int l) {
	if (l == 0) {
		int cur = 0;
		size_t loc = 0;
		++com;
		while (loc != string::npos) {
			loc = w.find(tw, loc);
			if (loc != string::npos) {
				++cur;
				++loc;
				++tot;
			}
		}
		mx = max(mx, cur);
		return;
	}
	for (int i = 0; i < kb.size(); ++i) {
		gen_all(w + kb[i], l - 1);
	}
}

double solve_case() {
	int k, l, s;
	string b, w;
	cin>>k>>l>>s>>b>>w;
	tw = w;
	kb = b;
	mx = 0;
	tot = 0;
	com = 0;
	gen_all("", s);
	return double(mx) - double(tot) / com;
}

int main() {
	int tt;
	cin>>tt;
	for (int t = 1; t <= tt; ++t) {
		cout<<"Case #"<<t<<": "<<fixed<<setprecision(8)<<solve_case()<<endl;
	}
	return 0;
}


