#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define S second
#define F first
using namespace std;
typedef long long LL;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef pair<ut,pr> ppr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr> PQ;
const int INF=1<<30;
const int SIZE=5+1e+5;
const LL p=7+1e9;

int main(){
	int T;
	cin >> T;
	FOR(j,1,T+1){
		cout << "Case #"<<j <<": ";
		LL B,M;
		cin >> B >> M;
		if(M>(1LL<<(B-2))){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		FOR(i,1,B+1){
			FOR(j,1,B+1){
				if(i==B) cout <<0;
				else if(j==B){
					if(M==(1LL<<(B-2)) || (i!=1 && (((1LL<<(i-2))&M)!=0))) cout << 1;
					else cout << 0;
				}
				else{
					if(i<j) cout <<1; 
					else cout << 0;
				}
			}
			cout << endl;
		}

	}

	return 0;
}