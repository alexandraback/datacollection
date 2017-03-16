
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

int war(vector<double> & v1, vector<double> & v2){
	int N = sz(v1);
	sort(all(v2));
	sort(all(v1));
	vector<bool> used(N,false);
	int res = 0;
	FOR(i,0,N){
		bool done = false;
		FOR(j,0,N)if(!used[j] && v2[j] > v1[i]){
			used[j] = true;
			done = true;
			++res;
			break;
		}
		if(!done){
			FOR(j,0,N)if(!used[j]){
				used[j] = true;
				break;
			}
		}
	}
	return res;
}

void calc(){
	int N;
	cin >> N;
	vector<double> v1(N), v2(N);
	FOR(i,0,N)cin >> v1[i];
	FOR(i,0,N)cin >> v2[i];
	cout << war(v2,v1) << " " << N-war(v1,v2) << endl;
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
