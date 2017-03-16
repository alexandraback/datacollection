
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

int N,S,P;
int val[110];
int calc(){
	int ns = 0;
	int res = 0;
	FOR(i,0,N){
		if(val[i] >= P*3-2 && P <= val[i])++res;
		else if(ns != S && val[i] >= P*3-4 && P <= val[i]){
			++res;
			++ns;
		}
	}
	return res;
}
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cin >> N >> S >> P;
		FOR(i,0,N)cin >> val[i];
		cout <<"Case #" << tcc << ": " << calc() << endl;
	}
	return 0;
}
