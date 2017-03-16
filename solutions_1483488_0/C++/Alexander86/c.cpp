
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
int A, B;
int calc(){
	int dig = 0, mul = 1;
	while(mul <= B){
		++dig;
		mul *= 10;
	}
	mul /= 10;
	int res = 0;
	FOR(i,A,B+1){
		int num = i;
		set<int> oth;
		FOR(j,1,dig){
			int nnum = num / 10;
			num = nnum + (num - nnum * 10) * mul;
			if(num > i && num <= B)oth.insert(num);
		}
		res += sz(oth);
	}
	return res;
}
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cin >> A >> B;
		cout <<"Case #" << tcc <<": " << calc() << endl;
	}
	return 0;
}

