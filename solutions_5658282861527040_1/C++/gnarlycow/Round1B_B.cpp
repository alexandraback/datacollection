//============================================================================
// Name        : Round1B_B.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a, b, k;
long long buf[33][2][2][2];
bool u[33][2][2][2];

long long solve(int s, int tx, int ty, int tz) {
	//cout << s << ' ' << tx << ' ' << ty << ' ' << tz << endl;
	if(s<0) {
		if(!tx&&!ty&&!tz) return 1LL;
		return 0LL;
	}
	if(u[s][tx][ty][tz]) return buf[s][tx][ty][tz];
	long long ans = 0;
	for(int i=0; i<2; ++i) {
		if(tx && i>((a>>s)&1)) continue;
		int newtx = (tx && i==((a>>s)&1));
		for(int j=0; j<2; ++j) {
			if(ty && j>((b>>s)&1)) continue;
			int newty = (ty && j==((b>>s)&1));
			int r = (i&j);
			if(tz && r>((k>>s)&1)) continue;
			int newtz = (tz && r==((k>>s)&1));
			ans += solve(s-1, newtx, newty, newtz);
		}
	}
	//cout << s << ' ' << tx << ' ' << ty << ' ' << tz << " ans = " << ans << endl;
	u[s][tx][ty][tz] = true;
	return buf[s][tx][ty][tz] = ans;
}

int main() {
	int nc;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		cin >> a >> b >> k;
		memset(buf,0,sizeof(buf));
		memset(u,0,sizeof(u));
		/* small case:
		int ans = 0;
		for(int i=0; i<a; ++i)
			for(int j=0; j<b; ++j)
				if((i&j)<k)
					++ans;
					*/
		long long ans = solve(30, 1, 1, 1);
		printf("Case #%d: ", cid);
		cout << ans << endl;
	}
	return 0;
}
