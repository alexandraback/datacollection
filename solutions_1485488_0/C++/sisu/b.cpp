#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>
using namespace std;
int H,N,M;
int cs[256][256];
int fs[256][256];
//int ts[256][256];

struct S {
	int x,y;
	int t;
	bool operator<(const S& s) const {
		return t>s.t;
	}
};
bool done[256][256];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int solve() {
//	cout<<"\n\n";
	priority_queue<S> q;
	q.push((S){0,0,0});
	while(!q.empty()) {
		S s = q.top();
		q.pop();
		if (done[s.y][s.x]) continue;
		done[s.y][s.x] = 1;
//		cout<<"found "<<s.y<<' '<<s.x<<' '<<s.t<<'\n';
		if (s.y==N-1 && s.x==M-1) return s.t;

		for(int i=0; i<4; ++i) {
			int x = s.x+dx[i];
			int y = s.y+dy[i];
			if (x<0 || x>=M || y<0 || y>=N) continue;
			if (done[y][x]) continue;
			int ah = min(cs[s.y][s.x], cs[y][x]) - 50;
			if (ah < fs[y][x]) continue;
			if (cs[y][x]-fs[s.y][s.x] < 50) continue;

			ah = min(ah,H);
			int at = max(s.t, H-ah);
			ah = H-at;
			if (at<=0 && s.t==0) {
				q.push((S){x,y,0});
				continue;
			}
			int wlevel = ah - fs[s.y][s.x];
//			cout<<"asdasd "<<x<<' '<<y<<' '<<at<<" ; "<<wlevel<<'\n';
			if (wlevel < 20) at += 100;
			else at += 10;
			q.push((S){x,y,at});
		}
	}
	return -10;
}

int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		memset(done,0,sizeof(done));
		cin>>H>>N>>M;
		for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>cs[i][j];
		for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>fs[i][j];
		double r = 0.1*solve();
		cout<<"Case #"<<a<<": "<<fixed<<setprecision(15)<<r<<'\n';
	}
}
