
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

string calc(int N){
	if(N == 0) return "INSOMNIA";
	ll C = 0;
	set<char> used;
	while(used.size() < 10){
		C += N;
		ostringstream os;
		os << C;
		string S = os.str();
		for(char s: S)used.insert(s);
	}
	ostringstream os;
	os << C;
	return os.str();
}

int main() {
	int T;
	cin >> T;
	FOR(t,0,T){
		int N;
		cin >> N;
		cout << "Case #" << (t+1) << ": " << calc(N) << endl;
	}
	return 0;
}
