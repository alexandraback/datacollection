#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dn[]={1,0,-1,0};
int dm[]={0,1,0,-1};

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		int H,N,M;
		cin >> H >> N >> M;
		int h1[N+2][M+2], h2[N+2][M+2];
		bool sn[N+2][M+2];
		for(int n=0; n<N+2; n++) for(int m=0; m<M+2; m++) h1[n][m]=h2[n][m]=sn[n][m]=0;
		for(int n=0; n<N; n++) for(int m=0; m<M; m++) { cin >> h2[n+1][m+1]; }
		for(int n=0; n<N; n++) for(int m=0; m<M; m++) { cin >> h1[n+1][m+1]; }
		cout << "Case #" << ts << ": ";
		priority_queue<pair<int,pair<int,int> > > q;
		q.push(make_pair(0,make_pair(1,1)));
		while(!q.empty()) {
			int T = q.top().first;
			int n = q.top().second.first;
			int m = q.top().second.second;
			//cout << T << " " << n << " " << m << endl;
			q.pop();
			if(n==N && m==M) {
				//cout << "Yahoo" << " " << N << " " << M << endl;
				cout << -T*0.1;
				break;
			}
			if(sn[n][m]) continue;
			sn[n][m]=1;
			q.push(make_pair(T-1, make_pair(n,m)));
			for(int d=0; d<4; d++) {
				int n2 = n+dn[d];
				int m2 = m+dm[d];
				int TT=T;
				if(max(0,H+T) > h2[n2][m2]-50) TT = h2[n2][m2]-50-H;
				if(h1[n][m] > h2[n2][m2]-50) continue;
				if(h1[n2][m2] > h2[n2][m2]-50) continue;
				if(h1[n2][m2] > h2[n][m]-50) continue;
				int T2=0;
				if(TT==0) T2=0;
				else if(H+TT>=h1[n][m]+20) T2=TT-10;
				else T2=TT-100;
				if(!sn[n2][m2]) q.push(make_pair(T2,make_pair(n2,m2)));
			}
		}
		cout << endl;
	}
}
