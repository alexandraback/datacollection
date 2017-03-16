
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

void impossible(){
	cout << "Impossible\n";
}

void calc(){
	cout << endl;
	int R, C, M;
	cin >> R >> C >> M;
	cerr << R << " " << C <<  " "<< M << endl;
	if(R*C <= M)return impossible();
	if(min(R,C) == 1){
		FOR(r,0,R){
			FOR(c,0,C){
				if(r+c == 0)cout << "c";
				else if(r+c < R * C -M) cout << ".";
				else cout << "*";
			}
			cout << endl;
		}
		return;
	}
	if(R*C == M+1){
		FOR(r,0,R){
			FOR(c,0,C){
				if(r+c == 0)cout << "c";
				else cout << "*";
			}
			cout << endl;
		}
		return;
	}
	if(R*C - M <= 3)return impossible();
	if(min(R,C) == 2){
		if(M%2)return impossible();
		FOR(r,0,R){
			FOR(c,0,C){
				if(r+c == 0)cout << "c";
				else if((max(r,c)+1)*2 > R*C - M)cout << "*";
				else cout << ".";
			}
			cout << endl;
		}
		return;
	}
	if(R * C - M == 5 || R * C - M == 7)return impossible();
	if(R * C - M <= 6){
		assert(R * C - M == 6 || R * C - M == 4);
		FOR(r,0,R){
			FOR(c,0,C){
				if(r+c == 0)cout << "c";
				else if(max(r,c) <= 1) cout << ".";
				else if(r <= 1 && c == 2 && R * C - M == 6) cout << ".";
				else cout << "*";
			}
			cout << endl;
		}
		return;
	}
	vector<string> output(R,string(C,'*'));
	FOR(r,0,3)FOR(c,0,3)output[r][c] = '.';
	output[2][2] = '*';
	output[0][0] = 'c';
	int F = R * C - M - 8;
	FOR(r,3,R)if(F >= 2){
		FOR(c,0,2)output[r][c] = '.';
		F-=2;
	}
	FOR(c,3,C)if(F >= 2){
		FOR(r,0,2)output[r][c] = '.';
		F -= 2;
	}
	FOR(r,2,R)FOR(c,2,C)if(F > 0){
		output[r][c] = '.';
		--F;
	}
	FOR(r,0,R)cout << output[r] << endl;
}

int main() {
	int TC;
	cin >> TC;
	FOR(T,1,TC+1){
		cout << "Case #" << T << ": ";
		calc();
	}
	return 0;
}
