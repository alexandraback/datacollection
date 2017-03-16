#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;

int DX[4]={-1,0,1,0};
int DY[4]={0,1,0,-1};

vector<LL> rebuild(map<LL,LL> M, LL x) {
	vector<LL> ret;
	while (x>0) {
		LL p = M[x];
		ret.push_back(x-p);
		x = p;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;


	for (int t=1; t<=T; t++) {
		int H,N,M;
		cin >> H >> N >> M;
		vector<vector<int> > top,bot;
		vector<vector<double> > best;
		top.resize(N, vector<int>(M));
		bot.resize(N, vector<int>(M));
		best.resize(N, vector<double>(M, 100000000.0));
		cerr<<"H"<<H<<" N"<<N<<" M"<<M<<endl;
		{
			for (int y=0; y<N; y++) {
				for (int x=0; x<M; x++) {
					cin >> top[y][x];
					cerr<<top[y][x]<<" ";
				}
				cerr <<endl;
			}
			for (int y=0; y<N; y++) {
				for (int x=0; x<M; x++) {
					cin >> bot[y][x];
					cerr<<bot[y][x]<<" ";
				}
				cerr <<endl;
			}
		}
		// (time,wl)
		typedef pair<pair<double,double>,pair<int,int> > TPOS;
		priority_queue<TPOS> pq;
		pq.push(make_pair(make_pair(0.0, double(H)), make_pair(0,0)));
		best[0][0]=0;
		double resp = -1;
		while (pq.size()) {
			TPOS pos = pq.top();
			pq.pop();
			double  t=-pos.first.first;
			double wl = pos.first.second;
			int x=pos.second.first;
			int y=pos.second.second;

			if (x==M-1 && y==N-1) {
				cerr<<"reach!!!! at time"<<t<<endl;
				resp = t;
				break;
			}
			cerr<<"(1) am at ("<<x<<","<<y<<") at time "<<t<<" with waterL="<<wl<<" floor is at "<<bot[y][x]<<endl;
			for (int d=0; d<4; d++) {
				int x1=x+DX[d], y1=y+DY[d];
				if (x1<0 || y1<0 || x1>=M || y1>=N) {
					continue;
				}
				// try (x1,y1)
				if (top[y][x] - bot[y1][x1] < 50)  // cond2
					continue;
				if (top[y1][x1] - bot[y][x] < 50)  // cond1
					continue;
				if (top[y1][x1] - bot[y1][x1] < 50)  // cond1
					continue;
				double wait = 0;
				double wl1 = wl;
				if (top[y1][x1] - wl < 50)  {
					wl1 = top[y1][x1]-50;
					double dd = wl - wl1;
					wait += dd/10.0;
					cerr<<"  should wait down"<<dd<<"cm"<<" or time "<<wait<<endl;
				}
				if (wait==0 && t==0 && wl==H && best[y1][x1]>0) {
					best[y1][x1] = 0;
					cerr<<"  (1) enter ("<<x1<<","<<y1<<") at time ZERO (wait was "<<wait<<")"<<endl;
					TPOS pos1 = make_pair(make_pair(0,wl1), make_pair(x1,y1));
					pq.push(pos1);
				}
				bool fast = wl1 - bot[y][x] >= 20;
				double t1 = t + (fast ? 1 : 10) + wait;
				if (t1 < best[y1][x1]) {
					best[y1][x1] = t1;
					wl1 -= fast ? 10 : 100;
					cerr<<"  (2) enter ("<<x1<<","<<y1<<") fast="<<fast<<" at time "<<t1<<" (wait was "<<wait<<") water down to "<<wl1<<endl;
					TPOS pos1 = make_pair(make_pair(-t1,wl1), make_pair(x1,y1));
					pq.push(pos1);
				}
			}

		}
		cout << "Case #" << t << ": " << (resp>0 ? resp : 0) << endl;
	}


}