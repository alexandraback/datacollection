#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int check(vector<string> w, int M) {
	int H=w.size(), W=w[0].size();
	VVI nu(H, VI(W));
	REP(y, H)REP(x,W)if(w[y][x]=='*') M--;
	if(M!=0)return 0;
	
	REP(y, H)REP(x,W)if(w[y][x]=='*')RANGE(dy,-1, 2)RANGE(dx,-1,2) {
		int nx = x+dx;
		int ny = y+dy;
		if(0<=nx && nx<W && 0<=ny && ny<H) nu[ny][nx]++;
	}
	deque<int> q;
	q.PB((H-1)*W+W-1);
	while(q.size()) {
		int idx = q.front();q.pop_front();
		w[idx/W][idx%W]='o';
		if(nu[idx/W][idx%W]==0) RANGE(dy,-1, 2)RANGE(dx,-1,2) {
			int nx = idx%W+dx;
			int ny = idx/W+dy;
			if(0<=nx && nx<W && 0<=ny && ny<H && w[ny][nx]!='o') q.PB(ny*W+nx);
		}
	}
	REP(y, H)REP(x,W)if(w[y][x]=='.')return 0;
	
//	REP(y, H)cout<<w[y]<<endl;
//	cout<<endl;
	return 1;
}

vector<string> ans;

int g(int W, int H, int M) {
	ans = vector<string>(H, string(W, '.'));
	ans[H-1][W-1] = 'c';
	if(W*H-M==1) {
		REP(y,H)REP(x,W)if(y!=H-1||x!=W-1)ans[y][x]='*';
		return 1;
	}
	if(W==1 || H==1) {
		if(W*H-M>=2) {
			int co=0;
			REP(y, H) REP(x, W) if(!(W-2<=x && H-2<=y) && co<M) {ans[y][x] = '*';co++;}
			return 1;
		}
	}
	// W>=2 && H>=2 here
	
	int rest = W*H-M;
	int ok=0;
	RANGE(mw, 2, W+1) RANGE(mh, 2, H+1) {
		if(mw*mh < rest) continue;
		int Free = rest - (mw*2+mh*2-4);
		if(Free<0) continue;
		REP(y,H)REP(x,W)ans[y][x]='*';
		RANGE(y, H-2, H) RANGE(x, W-mw, W) ans[y][x]='.';
		RANGE(x, W-2, W) RANGE(y, H-mh, H) ans[y][x]='.';
		for(int y=H-3;y>=0;y--) for(int x=W-3;x>=0;x--) if(Free) {ans[y][x]='.';Free--;}
		ans[H-1][W-1] = 'c';
		ok=1;
		break;
	}
	return ok;
}

vector<string> nans;
int naive(int W, int H, int M) {
	if(W>5||H>5) {
		cout<<"SKIP"<<endl;
		return 0;
	}
	int ok=0;
	REP(bits, 1<<(W*H-1))if(POPCOUNT(bits)==M) {
		nans = vector<string>(H, string(W, '.'));
		nans[H-1][W-1] = 'c';
		REP(y, H) REP(x, W) {
			int idx = y*W+x;
			if(idx==W*H-1) break;
			if((bits>>idx)&1) nans[y][x]='*';
		}
//			REP(y, H) cout<<w[y]<<endl;
		// check
		if(check(nans, M)) {
			ok=1;
//			REP(y, H) cout<<w[y]<<endl;
			break;
		}
	}
	return ok;
}

int main() {
	if(0)
	{
		RANGE(W, 1, 6)
		RANGE(H, 1, 6)
		REP(M, W*H) {
			int tr = g(W, H, M);
			int ref = naive(W, H, M);
			if(tr!=ref) {
				cout<<W<<" "<<H<<" "<<M<<" "<<tr<<" ref: "<<ref<<endl;
				assert(tr==ref);
			}
			if(tr && !check(ans, M)) {
				cout<<W<<" "<<H<<" "<<M<<" "<<endl;
				cout<<"Try"<<endl;
				REP(y,H) cout<<ans[y]<<endl;
				cout<<"Naive"<<endl;
				REP(y,H) cout<<nans[y]<<endl;
				assert(0);
			}
//			if(ref) {
//				cout<<W<<" "<<H<<" "<<M<<" "<<endl;
//				cout<<"Naive"<<endl;
//				REP(y,H) cout<<nans[y]<<endl;
//			}
		}
		return 0;
	}
	
	int test_cases;
	cin>>test_cases;
	ll H,W,M;
	REP(ttt, test_cases) {
		cin>>H>>W>>M;
//		cout<<H<<" "<<W<<" "<<M<<endl;
		int res = g(W, H, M);
		cout<<"Case #"<<ttt+1<<":"<<endl;
		if(res) {
			REP(y,H) cout<<ans[y]<<endl;
		} else {
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}





