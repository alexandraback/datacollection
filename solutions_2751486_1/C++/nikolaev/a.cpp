#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for (int k=0; k<t; k++) {
		int res=0;
		string s;
		cin>>s;
		int n;
		cin>>n;
		int lastadd=0;
		int sp=-1;
		int cl=0;

		for (int i=0; i<s.size(); i++) {
			if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
				res+=lastadd;
				cl=0;
			}
			else {
				cl++;
				if (cl < n) res+=lastadd;
//				else if (cl==n) {
				else {
					lastadd=i-n+2;
					res+=lastadd;
				}
//				else {
//
//				}
			}
		}

		cout<<"Case #"<<k+1<<": "<<res<<'\n';
	}
	return 0;
}