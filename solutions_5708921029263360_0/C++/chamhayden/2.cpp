#include <iostream>
#include <cstdio>
#include <vector>

#define FOR(i,s,n) for (int i = s; i < n; ++i)

#define MAX 11

using namespace std;

int jp[MAX][MAX];
int ps[MAX][MAX];
int sj[MAX][MAX];

vector<pair<pair<int,int>,int> > store;

void clear() {
	FOR(i,0,MAX) {
		FOR(j,0,MAX) {
			jp[i][j] = 0;
			ps[i][j] = 0;
			sj[i][j] = 0;
		}
	}
	store.clear();
}
void runTest(int caseNo) {
	int J, P, S, K;
	scanf("%d %d %d %d\n", &J, &P, &S, &K);
	///*debug*/cout << "J" << J << " P" << P << " S" << S << " K" << K << endl;
	FOR(j,1,J+1) {
		FOR(p,1,P+1) {
			FOR(s,1,S+1) {
				///*debug*/cout << j << " " << p << " " << s << endl;
				///*debug*/cout << "  jp[" << j << "][" << p << "] = " << jp[j][p] << endl;
				///*debug*/cout << "  ps[" << p << "][" << s << "] = " << ps[p][s] << endl;
				///*debug*/cout << "  sj[" << s << "][" << j << "] = " << sj[s][j] << endl;
				if (jp[j][p] < K
					&& ps[p][s] < K
					&& sj[s][j] < K)
				{
					jp[j][p]++;
					ps[p][s]++;
					sj[s][j]++;
					store.push_back(make_pair(make_pair(j,p),s));
				}
			}
		}
	}
	cout << "Case #" << caseNo << ": " << store.size() << endl;
	FOR(i,0,store.size()) {
		cout << store[i].first.first << " ";
		cout << store[i].first.second << " ";
		cout << store[i].second << endl;
	}
	///*debug*/cout << endl << endl;
}

int main () {
	int T;
	scanf("%d\n", &T);
	FOR(i,0,T) {
		clear();
		runTest(i+1);
	}
	return 0;
}