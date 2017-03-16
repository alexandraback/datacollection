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
		int n, nd=0;
		int S1=0;
		int S2=0;
		ifs >> n;
		VI s(n);
		REP(i, n){
			ifs >> s[i];
			S1 += s[i];
		}
		S2=S1*2;
		int flag = 1;
		double L;
		nd = n;
		while(flag){
			flag = 0;
			L = (S2*1.0)/nd;
			REP(i, n){
				if(s[i] > L && s[i] > 0){
					nd--;
					S2 -= s[i];
					s[i]*=-1;
					flag = 1;
					break;
				}
			}
		}
		L = (S2*1.0)/nd;
		fprintf(ofp, "Case #%d:", test+1);
		REP(i, n){
			double ret=((S2*1.0)/nd-s[i])*100.0/S1;
			if(s[i]<0 || ret<0.0)ret = 0.0;
			fprintf(ofp, " %.8f", ret);
		}
		fprintf(ofp, "\n");		
	}
	fclose(ofp);
}