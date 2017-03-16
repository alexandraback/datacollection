#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define cl(t,v) memset((t),(v),sizeof(t))

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)

class FileReader : public ifstream {
public:
	FileReader( const string& filename ) { open( filename.c_str(), ios_base::in ); }
	int readInt() { int x = 0; *this >> x; return x; }
	vector<int> readInts( int n ) { vector<int> v(n); for ( int i = 0; i < n; i++ ) v[i] = readInt(); return v; }
	string readLine() { char buf[20000]; getline( buf, sizeof(buf) ); return buf; }
	string readString() { string x; *this >> x; return x; }
	vector<string> readStrings( int n ) { vector<string> v; for ( int i = 0; i < n; i++ ) v.push_back( readString() ); return v; }
	__int64 readInt64() { __int64 x; *this >> x; return x; }
};

class FileWriter : public ofstream {
public:
	FileWriter( const string& filename ) { open( filename.c_str(), ios_base::out ); }
};

int main() {
	FileReader fin ("B-small-attempt0.in");
	FileWriter fout ("out.txt");

	int caseCount;
	fin >> caseCount;
	fin.readLine();
	rep(cc,caseCount) {
		/*input*/
		int x,y;
		fin >> x >> y;
		fin.readLine();
		/*solve*/
		/*output*/
		stringstream ss;
		ss << "Case #" << cc + 1 << ": ";
		if (x > 0) rep(i,x) {ss << "WE";}
		else rep(i,-x) {ss << "EW";}
		if (y > 0) rep(i,y) {ss << "SN";}
		else rep(i,-y) {ss << "NS";}
		ss << endl;
		fout << ss.str().c_str();
		cout << ss.str().c_str();
	}
	return 0;
}
