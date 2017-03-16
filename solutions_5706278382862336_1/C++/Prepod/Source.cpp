#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

__int64 gcd(__int64 a, __int64 b) {
	while(a > 0 && b > 0) {
		if (a > b) a%=b;
		else b%=a;
	}
	return a+b;
}

int main() {
	ifstream inp("A-large.in");
	cin.rdbuf(inp.rdbuf());
	ofstream out("output.txt");
	cout.rdbuf(out.rdbuf());
	int T; cin>>T;
	for(int t=1; t<=T; t++) {
		__int64 a, b, g;
		char c;
		cin>>a>>c>>b;
		g = gcd(a, b);
		a /= g; b /= g;
		int r1, r2;
		for(r1=0; (b&1)==0; r1++, b>>=1);
		for(r2=0; a>1; r2++, a>>=1);
		cout<<"Case #"<<t<<": ";
		if (b!=1) cout<<"impossible"<<endl;
		else cout<<r1-r2<<endl;
	}
	return 0;
}