#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
const int INF = (int)1E9;

#define MAXN 1005
int N;
double a[MAXN], b[MAXN];
bool u[MAXN], v[MAXN];
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		cin >> N;
		REP(i,0,N) cin >> a[i];
		REP(i,0,N) cin >> b[i];
		sort(a, a+N);
		sort(b, b+N);
		int ai = 0, bi = N-1;
		int ansd = 0, ansc = 0;
		
		FILL(u, 0); FILL(v, 0);
		REP(i,0,N){
			for(int j=N-1; j>=0; j--){
				if(!u[j] && b[j] < a[i]){
					u[j] = 1;
					ansd ++;
					break;
				}
			}
			bool can = 0;
			REP(j,0,N){
				if(!v[j] && a[i] < b[j]){
					v[j] = 1;
					can = 1;
					break;
				}
			}
			if(!can) ansc ++;
		}
		printf("Case #%d: %d %d\n", csn, ansd, ansc);

	}
	return 0;
}