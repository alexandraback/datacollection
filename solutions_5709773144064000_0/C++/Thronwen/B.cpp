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
#include <iomanip>

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

double need[2000];
double nextF[2000];
double C,F,X;
double base = 2.0;
int main() {
	int T;
	cin >> T;
	FOR(cas,1,T+1){
		cin >> C >> F >> X;
		nextF[0] = C/base;
		need[0] = X/base;
		int i = 1;
		double min = need[0];
		while(true){
			nextF[i] = C/(base+F*i);
			need[i] = 0.;
			FOR(f,0,i){
				need[i]+=nextF[f];
			}
			need[i]+=X/(base+F*i);
			if(need[i] < min) min = need[i];
			else if(need[i] > min) break;
			i++;
		}
		cout << fixed << setprecision(7)<< "Case #" << cas << ": " << min << endl;
	}
}