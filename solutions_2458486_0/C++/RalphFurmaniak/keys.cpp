#include <map>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <valarray>
using namespace std;

typedef valarray<int> V;

int K,N;
V cnt(300);
int Ti[300];
vector<V> cnti;

int dp[1<<20];

bool doit(int msk, bool print=false) {
	int& ret=dp[msk];
	if(!print) if(ret) return ret>0;
	V cur(300);
	cur += cnt;
	if(msk+1 == (1<<N)) return ret=1;
	for(int i=0; i<N; i++) if(msk&(1<<i)) {
		cur += cnti[i];
		cur[Ti[i]]--;
	}
	for(int i=0; i<N; i++) if(msk&(1<<i)); else if(cur[Ti[i]]>0) {
		if(doit(msk|(1<<i))) {
			if(print) {
				cout << " " << i+1;
				doit(msk|(1<<i),true);
			}
			return ret=1;
		}
	}
	ret=-1;
	return false;
}

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ":";
		cin >> K >> N;
		for(int i=0; i<200; i++) cnt[i]=0;
		for(int i=0; i<K; i++) { int j; cin >> j; cnt[j]++; }
		cnti.clear();
		cnti = vector<V>(50, V(300));
		memset(dp,0,sizeof(dp));
		for(int i=0; i<N; i++) {
			int Ki;
			cin >> Ti[i] >> Ki;
			for(int j=0; j<Ki; j++) {
				int k; cin >> k;
				cnti[i][k]++;
			}
		}
		if(!doit(0)) cout << " IMPOSSIBLE" << endl;
		else {
			doit(0,true);
			cout << endl;
		}
	}
}
