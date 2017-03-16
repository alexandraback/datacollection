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

int war(vector<double> nao, vector<double> ken) {
	int N=nao.size();
	int win=0;
	REP(i, N) {
		int li=-1;
		REP(j, N) {
			//naoより高い最小のやつを出す
			if(nao[i]<ken[j]) {li=j;break;}
		}
		if(li==-1) {
			// どうせ負けるので相手は一番弱いやつをだす
			li=-1;
//			REP(j, N) if(ken[j]>0)if(li==-1 || ken[li]>ken[j]) li=j;
			REP(j, N) if(ken[j]>0)if(li==-1 || ken[li]<ken[j]) li=j;
			win++;
		}
		ken[li]=-1;
	}
	return win;
}

int dwar(vector<double> nao, vector<double> ken_orig) {
	int N=nao.size();
	int Max = 0;
	vector<double> best_nao;
	vector<int> best_res;
	vector<double> best_kenout;
	do {
		int win = 0;
		vector<double> ken(ken_orig);
		vector<int> res(ken.size());
		vector<double> kenout(ken.size());
		REP(i, N) {
			int li=-1;//larger
			REP(j, N) if(nao[i]<ken[j]) {li=j;break;}
			if(li==-1) {
				// どうせ負けるので相手は一番弱いやつをだす
				li=-1;
//				REP(j, N) if(ken[j]>0)if(li==-1 || ken[li]>ken[j]) li=j;
				REP(j, N) if(ken[j]>0)if(li==-1 || ken[li]<ken[j]) li=j;
				win++;
				assert(li>-1);
				res[i]=1;
			} else {
				//こっちが負けるので一番高いやつを出させる
				REP(j, N) if(ken[li]<ken[j]) {li=j;}
			}
			assert(li>=0);
			kenout[i] = ken[li];
			ken[li]=-1;
		}
//		cout<<nao<<endl;
//		cout<<"  "<<res<<" -> "<<win<<endl;
//		cout<<"  "<<kenout<<endl;
		if(Max<win) {
			best_nao = nao;
			best_res = res;
			best_kenout = kenout;
		}
		Max=max(Max,win);
	} while(next_permutation(ALL(nao)));
	cout<<best_nao<<endl;
	cout<<"  "<<best_res<<" -> "<<Max<<endl;
	cout<<"  "<<best_kenout<<endl;
	return Max;
}

int dwar_fast(vector<double> nao, vector<double> ken_orig) {
	int N=nao.size();
	int Max = 0;
	
	vector<double> best_nao;
	vector<int> best_res;
	vector<double> best_kenout;
	REP(nl, N+1) {
		vector<double> nao_t(N);
		vector<double> ken(ken_orig);
		vector<int> res(ken.size());
		vector<double> kenout(ken.size());
		int win = 0;
		REP(i, N) {
			int cn = i<nl ? i : N-(i-nl)-1;
			nao_t[i]=nao[cn];
			int li=-1;//larger
			REP(j, N) if(nao[cn]<ken[j]) {li=j;break;}
			if(li==-1) {
				// どうせ負けるので相手は一番弱いやつをだす
				li=-1;
//				REP(j, N) if(ken[j]>0)if(li==-1 || ken[li]>ken[j]) li=j;
				REP(j, N) if(ken[j]>0)if(li==-1 || ken[li]<ken[j]) li=j;
				win++;
				assert(li>-1);
				res[i]=1;
			} else {
				//こっちが負けるので一番高いやつを出させる
				REP(j, N) if(ken[li]<ken[j]) {li=j;}
			}
			assert(li>=0);
			kenout[i] = ken[li];
			ken[li]=-1;
		}
//		cout<<"NL "<<nl<<endl;
		if(Max<win) {
			best_nao = nao_t;
			best_res = res;
			best_kenout = kenout;
		}
		Max = max(Max, win);
	}
//	cout<<best_nao<<endl;
//	cout<<"  "<<best_res<<" -> "<<Max<<endl;
//	cout<<"  "<<best_kenout<<endl;
	return Max;
}

/*
nao 0.186 0.3 0.389 0.557 0.832 0.899 0.907 0.959 0.992 
ken 0.215 0.271 0.341 0.458 0.52 0.521 0.7 0.728 0.916 

0.186 0.992 0.959 0.907 0.899 0.832 0.557 0.389 0.3 

*/
int main() {
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll N;
	REP(ttt, test_cases) {
		cin>>N;
		vector<double> nao(N), ken(N);
		REP(i, N) cin>>nao[i];
		REP(i, N) cin>>ken[i];
		sort(ALL(nao));
		sort(ALL(ken));
//		cout<<"nao "<<nao<<endl;
//		cout<<"ken "<<ken<<endl;
		int w = war(nao,ken);
//		int dw = dwar(nao,ken);
		int dwf = dwar_fast(nao,ken);
//		if(dw!=dwf) {
//			cout<<dw<<" "<<dwf<<endl;
//			assert(dw==dwf);
//		}
		cout<<"Case #"<<ttt+1<<": "<<dwf<<" "<<w<<endl;
	}
	return 0;
}








