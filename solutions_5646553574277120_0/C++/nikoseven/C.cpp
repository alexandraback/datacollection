#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int C,D,V;
int m[1000],nm;
int issued[1000];

bool can() {
	bool f[50];
	for(int i=0;i<=V;++i)
		f[i] = false;
	f[0] = true;
	for(int i=0;i<nm;++i) {
		for(int j=V;j>=m[i];--j) if( f[j-m[i]] )
			f[j] = true;
	}
	for(int i=0;i<=V;++i)
		if(!f[i])
			return false;
	return true;
}
bool okay;
void dfs(int r,int lst=0) {
	if( r == 0 ) {
		if( can() )
			okay = true;
		return;
	}
	
	for(int i=lst+1;i<=V && okay == false;++i) if( !issued[i] ) {
		issued[i] = true;
		m[nm++] = i;
		dfs(r-1,i);
		--nm;
		issued[i] = false;
	}
}


int main() {
	int T,ics = 0;
	cin >> T;
	while(T--) {
		cin >> C >> D >> V;
		for(int i=0;i<=V;++i)
			issued[i] = false;
		for(int i=0;i<D;++i) {
			cin >> m[i];
			issued[m[i]] = true;
		}
		nm = D;
		int ans = 0;
		for(int i=0;i<=V;++i) {
			okay = false;
			dfs(i);
			if( okay ) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n",++ics,ans);
	}
	return 0;
}