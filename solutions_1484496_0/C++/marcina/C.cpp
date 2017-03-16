#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 27
int N, a[MAXN];

void out(int i){
			REP(j,N)
				if(i&(1<<j))
					cout << a[j] << " ";
			cout << endl;
}

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		cin >> N;
		REP(i,N) cin >> a[i];
		//sol
		map<int, int> M;
		REP(i,(1<<N)) if(i){
			int s = 0;
			REP(j,N)
				if(i&(1<<j))
					s += a[j];
			if(M.count(s)){
				cout << "Case #" << t << ":" << endl;
				out(M[s]);
				out(i);
				break;
			}
			M[s]=i;
		}
		//out
	}
    return 0;
}
