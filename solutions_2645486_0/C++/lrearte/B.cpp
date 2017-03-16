#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define MAX 100000

long long N, E, R;
vector<int> tabla;
int seg[MAX], from[MAX], to[MAX], best[MAX];

int fil(int idx, int f, int t) {
	from[idx]=f; to[idx]=t;
	if (f+1==t) return best[idx]=f;
	int med=(f + t)/2;
	int pri=fil(2*idx+1, f, med);
	int sec=fil(2*idx+2, med, t);
	return best[idx]=(tabla[pri]>tabla[sec]?pri:sec);
}

int calc(int idx, int ff, int tt) {
	if (ff<=from[idx] && to[idx]<=tt) return best[idx];
	if (to[idx]<=ff || tt<=from[idx]) return -1;
	int pri=calc(2*idx+1, ff, tt);
	int sec=calc(2*idx+2, ff, tt);
	if (pri==-1) return sec;
	if (sec==-1) return pri;
	return tabla[pri]>tabla[sec]?pri:sec;
}

long long val(int fff, int ttt, long long A, long long B) {
	int maxi = calc(0, fff, ttt);
	long long maxAva = min(R * (maxi-fff) + A, E);
	long long minRem = max(0LL, B-(ttt-maxi)*R);
	if (maxAva < minRem) cerr<<"WRONG"<<endl;
	long long tmp = tabla[maxi]*(maxAva-minRem);
	//cout<<maxi<<" con: "<<(maxAva-minRem)<<" x "<<tabla[maxi]<<"   =>  "<<maxAva<<" and "<<minRem<<endl;
	if (fff < maxi) tmp += val(fff, maxi, A, maxAva);
	if (maxi+1 < ttt) tmp += val(maxi+1, ttt, minRem+R, B);
	return tmp;
}

int main() {
	int n;

	cin>>n;
	for (int caso = 1; caso <= n; caso++) {
		cin>>E>>R>>N;
		tabla=vector<int>(N);
		for (int i=0;i<N;i++) cin>>tabla[i];
		fil(0, 0, N);
		
		cout << "Case #" << caso << ": " << val(0, N, E, R) <<endl;
	}
	return 0;
}
