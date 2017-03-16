#include <iostream>
using namespace std;
const int K = 4;
char bd[K+1][K+1];
char test(int sx, int sy, int dx, int dy) {
	int st = 0;
	if(bd[sy+dy*st][sx+dx*st]=='T') ++st;
	char stc = bd[sy+dy*st][sx+dx*st];
	if (stc=='.') return 0;
	bool ok = 1;
	for(int i=0; i<K; ++i) {
		char ch = bd[sy+dy*i][sx+dx*i];
		ok &= ch=='T' || ch==stc;
	}
	return ok ? stc : 0;
}

int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		for(int i=0; i<K; ++i) cin>>bd[i];
		char win = 0;

		for(int i=0; i<K; ++i) {
			if (!win) win = test(0,i,1,0);
			if (!win) win = test(i,0,0,1);
		}
		if (!win) win = test(0,0,1,1);
		if (!win) win = test(K-1,0,-1,1);
		bool full = 1;
		for(int i=0; i<K; ++i) for(int j=0; j<K; ++j) full &= bd[i][j]!='.';

		cout<<"Case #"<<a<<": ";
		if (win) cout<<win<<" won\n";
		else if (full) cout<<"Draw\n";
		else cout<<"Game has not completed\n";
	}
}
