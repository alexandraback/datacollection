#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

void main(int argc, char *argv[]){//GCJTemp
	int Test;
	ifstream ifs("as.in");
	FILE *ofp = fopen("as.out", "w");
	ifs >> Test;
	REP(test, Test){
		int A, B;
		ifs >> A >> B;
		double ret = 5*B;
		vector<double> P(A+1);
		P[0] = 1.0;
		REP(i, A)ifs >> P[i+1];
		REP(i, A)P[i+1] *= P[i];
		REP(i, A+1){
			int cnt1 = A+B-2*i+1;
			int cnt2 = cnt1 +B+1;
			ret = min(ret, P[i]*cnt1+(1-P[i])*cnt2);
		}
		ret = min(ret, B+2.0);
		fprintf(ofp, "Case #%d: %.8f\n", test+1, ret);
	}
}