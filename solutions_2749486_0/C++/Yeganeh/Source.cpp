#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) decltype(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

void solve(){
	int A;
	int B;
	cin >> A >> B;

	int x = 0;
	int y = 0;

	FOR(move,1,500){
		if(x<A && A>0){
			if(x+move<=A){
				cout << "E";
				x += move;
			}else{
				cout << "W";
				x -= move;
			}
		}else if(x>A && A<0){
			if(x-move>=A){
				cout << "W";
				x -= move;
			}else{
				cout << "E";
				x += move;
			}
		}else if(y < B && B > 0){
			if(y+move<=B){
				cout << "N";
				y += move;
			}else{
				cout << "S";
				y -= move;
			}
		}else if(y > B && B < 0){
			if(y-move>=B){
				cout << "S";
				y -= move;
			}else{
				cout << "N";
				y += move;
			}
		}
	}
	/*double p[100001];
	int i = 0;
	double pr = 1.0;
	FOR (i, 0, A) cin >> p[i];
	FOR (i, 0, A){
		pr *= p[i];
	}*/
}
int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
		cout << "\n";
    }
}