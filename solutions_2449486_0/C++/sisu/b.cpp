#include <iostream>
using namespace std;
const int MS = 128;
int ar[MS][MS];
int get(int sx, int sy, int dx, int dy, int c) {
	int big = 0;
	for(int i=0; i<c; ++i)
		big = max(big, ar[sy+dy*i][sx+dx*i]);
	return big;
}
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		int h,w;
		cin>>h>>w;
		for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) cin>>ar[i][j];
		bool ok = 1;
		for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
			ok &= min(get(0,i,1,0,w), get(j,0,0,1,h))==ar[i][j];
		}
		cout<<"Case #"<<a<<": "<<(ok?"YES":"NO")<<'\n';
	}
}
