#include <iostream>
using namespace std;
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		int n,s,p;cin>>n>>s>>p;
		int r=0;
		int x = p + 2*max(p-1,0);
		int y = p + 2*max(p-2,0);
		for(int i=0; i<n; ++i) {
			int a;cin>>a;
			if (a>=x) ++r;
			else if (a>=y && s) ++r,--s;
		}
		cout<<"Case #"<<a<<": "<<r<<'\n';
	}
}
