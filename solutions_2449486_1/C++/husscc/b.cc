#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <memory.h>

using namespace std;
#define REP1(i,n) for((i)=1;(i)<(int)(n);(i)++)
#define REP0(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define RITR(c,itr) for(__typeof((c).begin()) itr=(c).begin();(itr)!=(c).end();(itr)++)
typedef pair<int, int> PR;
int lawn[101][101], done[101][101], N, M, T;
struct comp{
	bool operator()(const PR &p1, const PR &p2) const{
		return lawn[p1.first][p1.second] < lawn[p2.first][p2.second];
	}
};
bool solve(){
	memset(done, 0, sizeof(done));
	int i, j, k; vector<PR> v;
	REP0(i, N){
		REP0(j, M) v.push_back(PR(i, j));
	}
	sort(v.begin(), v.end(), comp());
	REP0(i, v.size()){
		if(done[v[i].first][v[i].second]) continue;
		int h = lawn[v[i].first][v[i].second], can = 0;
		REP0(j, N){if(lawn[j][v[i].second] > h) break;}
		if(j == N){
			can = 1; 
			REP0(j, N) done[j][v[i].second] = true;
		}
		REP0(j, M) {if(lawn[v[i].first][j] > h) break;}
		if(j == M){
			can = 1;
			REP0(j, M) done[v[i].first][j] = true;
		}
		if(can == 0) return false;
	}
	return true;
}

int main(){
	cin>>T; int i, j, k;
	REP1(i, T+1){
		cin>>N>>M;
		REP0(j, N){
			REP0(k, M) cin>>lawn[j][k];
		}
		printf("Case #%d: ", i);
		if(solve()) printf("YES\n");
		else printf("NO\n");
	}
}