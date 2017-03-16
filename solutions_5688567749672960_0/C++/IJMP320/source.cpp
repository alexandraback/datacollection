#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,n) for(int i=a;i<(int)(n);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define F first
#define S second
const int INF = 2000000000;
const int DX[4]={0,1,0,-1}, DY[4]={-1,0,1,0};
struct P{int x;int y;P(int X=0,int Y=0){x=X;y=Y;}};

string IntToString(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

int a[1000001];

int main() {
	REP(i,1000001) a[i]=INF;
	REP(i,21) {
		a[i]=i;
	}
	FOR(i,1,1000000) {
		string s = IntToString(i);
		reverse(ALL(s));
		a[i+1] = min(a[i+1],a[i]+1);
		int t = atoi(s.c_str());
		a[t] = min(a[t], a[i]+1);
	}

	int T;
	cin >> T;
	REP(t,T) {
		ll N;
		cin >> N;
		printf("Case #%d: %d\n",t+1,a[N]);
	}
	return 0;
}
