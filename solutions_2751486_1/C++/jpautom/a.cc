#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define REP(i,n) for (int i(0),_n(n); i < _n; ++i)
#define FOR(i,a,b) for (int i(a),_b(b); i < _b; ++i)
#define FORD(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair((a),(b))
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define debug if(1)printf

int TCases;
int N;
int L;
vector<int> vv;
vector<int> pos;

bool isv(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

void read_case() {
	vv.clear();
	pos.clear();
	int last_mark = 0;
	bool last_v = true;
		
	char c;
	scanf(" ");
	int i;
	for (i=0; ; i++) {
		scanf("%c", &c);
		if (c==' ') {
			vv.PB(i-last_mark);
			break;
		}
		bool v = isv(c);
		if (v!=last_v) {
			vv.PB(i - last_mark);
			last_mark = i;
			last_v = v;
		}
	}
	L = i;
	cin >> N;
	
	
	for (int acc=0, i=0 ; i<vv.size(); i++) {
		if (i%2==1) {
			if (vv[i]>=N) {
				for (int j=0; j<=vv[i]-N; j++) {
					pos.PB(acc+j);
				}
			}
		}
		acc+=vv[i];
	}
}

int next_seq(int p) {
	if (pos.size() == 0 || p>pos[pos.size()-1]) return -1;

	vector<int>::iterator it = lower_bound(pos.begin(), pos.end(), p);
	return *it;
}

void solve_case() {
	long long res = 0;
	for (int i=0; i<L; i++) {
		int p = next_seq(i);
		//printf("pos %d  next %d\n", i, p);
		
		if (p<0) break;
		res += L-(p+N)+1;
	}
	cout << res << endl;

}


	

int main() {
	cin >> TCases;
	for (int nCase=1; nCase<=TCases; nCase++) {
		read_case();
		cout <<"Case #" << nCase << ": " ;
		solve_case();
	}
	return 0;
}