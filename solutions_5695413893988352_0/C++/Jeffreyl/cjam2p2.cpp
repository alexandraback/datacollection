#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int T=0; string c, j, rc, rj; int larger; // 1 means c larger -1 means j larger
int recur(string cc, string jj, int ci, int ji, int mx) {
	int ans=999; string ac, aj;
	if (ci<mx) {
		if (cc[ci]=='?') {
			for (int i=0; i<=9; i++) {
				string ct=cc;
				ct[ci]=char(i+'0');
				int t=recur(ct, jj, ci+1, ji, mx);
				if (t<ans) {
					ans=t;
					ac=rc; aj=rj;
				}
			}
		} else {
			int t=recur(cc, jj, ci+1, ji, mx);
			if (t<ans) {
				ans=t;
				ac=rc; aj=rj;
			}
		}
		rc=ac; rj=aj;
		return ans;
	}
	if (ji<mx) {
		if (jj[ji]=='?') {
			for (int i=0; i<=9; i++) {
				string jt=jj;
				jt[ji]=char(i+'0');
				int t=recur(cc, jt, ci, ji+1, mx);
				if (t<ans) {
					ans=t;
					ac=rc; aj=rj;
				}
			}
		} else {
			int t=recur(cc, jj, ci, ji+1, mx);
			if (t<ans) {
				ans=t;
				ac=rc; aj=rj;
			}
		}
		rc=ac; rj=aj;
		return ans;
	}
	rc=cc;
	rj=jj;
	return abs(stoi(cc)-stoi(jj));
}
int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>c>>j;
		recur (c, j, 0, 0, c.length());
		cout<<"Case #"<<t<<": "<<rc<<" "<<rj<<endl;
	}
	return 0;
}
