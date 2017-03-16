
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
#include <fstream>

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

void calc(){
	string in;
	cin >> in;
	string res;
	FOR(i,0,sz(in)){
		string next = in.substr(i,1);
		string res1 = next + res;
		string res2 = res + next;
		if(res1 > res2)res = res1;
		else res = res2;
	}
	cout << res << endl;
}

int main() {
	int T;
	cin >> T;
	FOR(t,0,T){
		cout << "Case #" << (t+1) << ": ";
		calc();
	}
	return 0;
}
