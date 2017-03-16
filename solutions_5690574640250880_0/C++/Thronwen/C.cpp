#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

const double PI = 2.0 * acos(0.0);

string int_to_str(int v) {
	ostringstream os;
	os << v;
	return os.str();
}

int str_to_int(string s) {
	istringstream is(s);
	int v;
	is >> v;
	return v;

}

char field[50][50];
int m, r, c;


void reset(){
	FOR(i, 0, r) FOR(j, 0, c){
		field[i][j]='.';
	}
}

bool check(){
	bool ret = true;
	FOR(i, 0, r){
		bool allm=true;
		bool row = false;
		FOR(j, 0, c){
			if(field[i][j]=='.'){
				allm=false;
				if(j <= c-2 || c==1) row = true;
			}
		}
		if(!row&&!allm) return false;

	}
	FOR(i, 0, c){
		bool allm= true;
		bool col = false;
		FOR(j, 0, r){
			if(field[j][i]=='.'){
				allm=false;
				if(j <=r-2||r==1) col = true;
			}
		}
		if(!col&&!allm)return false;
	}
	return ret;
}

bool build(int curR, int curC, int ml){
	if(curC==c){
		curR++;
		curC=0;
	}
	if(curR==r && !ml) return check();
	if(curR==r&&ml) return false;
	if((curR==0 || field[curR-1][curC]=='*') && (curC==0 || field[curR][curC-1] =='*')
		&& ml>0){
		field[curR][curC]='*';
		if(build(curR, curC+1, ml-1)){
				return true;
		}
	}
	field[curR][curC]='.';
	if(build(curR, curC+1, ml)) return true;
	return false;
}

int main() {
	int t;
	cin >> t;
	FOR(cas, 1, t+1){
		cin >> r >> c >> m;
		reset();
		cout << "Case #" << cas << ":" << endl;
		if(c*r==m+1){
			FOR(i, 0, r){
				FOR(j, 0, c){
					field[i][j] = '*';
				}
			}
			field[0][0] = 'c';
			FOR(i, 0, r){
				FOR(j, 0, c){
					cout << field[i][j];
				}
				cout << endl;
			}
		}else if(build(0,0,m)){
			field[r-1][c-1]='c';
			FOR(i, 0, r){
				FOR(j, 0, c){
					cout << field[i][j];
				}
				cout << endl;
			}
		}else {
			cout << "Impossible" << endl;
		}
	}
}