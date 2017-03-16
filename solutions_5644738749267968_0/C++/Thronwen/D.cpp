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

const int MAXN = 1000;
vector<double> val[2];
double diff = 5e-6;
int n;

int calcDeceit(){
	int ret = 0;
	int f=n-1, b=0;
	while(f>=0){
		if(val[0][f]<val[1][f+b]){
			f--;
			b++;
		}else{
			ret++;
			f--;
		}
	}
	return ret;
}

int calcWar(){
	int ret = 0;
	int f=0, b=0;
	while(f<n){
		if(val[0][f] < val[1][f-b]){
			f++;
		}else{
			f++;
			b++;
			ret++;
		}
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	FOR(cas, 1, t+1){
		cin >> n;
		FOR(i, 0, 2) val[i].clear();
		FOR(j, 0, 2) FOR(i, 0, n) {
			double next;
			cin >> next;
			val[j].push_back(next);
		}
		FOR(i, 0, 2) sort(val[i].begin(), val[i].end()), 
			reverse(val[i].begin(), val[i].end());
		int d = calcDeceit();
		int w = calcWar();

		cout <<"Case #" << cas <<": " << d << " " << w <<endl;
	}
}