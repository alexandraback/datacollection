#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
using namespace std;
#define SZ(a) (int((a).size()))
#define FOR(i,n) for(int _n=(n),i=0;i<_n;++i)
#define FORI(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORSZ(i,c) FOR(i,SZ(c))
#define SET(t,x) memset((t),(x),sizeof(t))
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define PRINT(x) cout<<#x<<"="<<x<<"\n"
#define PRINTI(x,n) for(__typeof(n)i=0;i<(n);++i)cout<<(x)[i]<<" ";cout<<"\n"
#define PRINTIJ(x,n1,n2) for(__typeof(n1)i=0;i<(n1);++i,cout<<"\n")for(__typeof(n2)j=0;j<(n2);++j)cout<<(x)[i][j]<<" ";cout<<"\n"
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(),c.rend()
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define ABS(a) ( (a) >= 0 ? (a) : (-(a)))
#define PB push_back
#define MP make_pair
#define EPS 1e-11
#define EPS2 1e-9
#define D_EQ(a,b) ((a)>((b)-EPS) && (a)<((b)+EPS))
#define D_LT(a,b) ((a)<((b)-EPS))
#define D_LTEQ(a,b) ((a)<((b)+EPS))
#define D_GT(a,b) ((a)>((b)+EPS))
#define D_GTEQ(a,b) ((a)>((b)-EPS))
#define INF 100000000
typedef long long ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;

template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
template<class T>vector<T> split(const string& s){vector<T> v;istringstream is(s);T t;while(is>>t)v.PB(t);return v;}
//VS splitStr(const string& s, char delim='\0', bool keepEmpty=false){if(delim=='\0')return split<string>(s);VS v;istringstream is(s);string t;while(getline(is,t,delim))if(keepEmpty || t!="")v.PB(t);return v;}
VS splitStr(const string& s,const string& d="",bool keepEmpty=false){if(d.empty())return split<string>(s);VS v;string t;FOR(i,SZ(s))if(d.find(s[i])!=string::npos){if(keepEmpty||!t.empty()){v.PB(t);t="";}}else t+=s[i];if(!t.empty())v.PB(t);return v;}

int main()
{
	int T, R, C, W;
	cin >> T;
	FORI(caseNum, 1, T)
	{
		cin >> R >> C >> W;
		int turnsOnInitialRows = C/W;
		// int turnsOnLastRow = C/W + C%W + W - 1;
		int turnsOnLastRow = C/W + (W - 1);
		if (C%W > 0) ++turnsOnLastRow;
		int minTurns = turnsOnLastRow + turnsOnInitialRows*(R-1);
		cout << "Case #" << caseNum << ": " << minTurns << endl;
	}
    return 0;
}
