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

class myclass {
public:
    myclass(double a):num(0), role(0){}
    double num,role;
    bool operator < (const myclass &m)const {
        return num < m.num;
    }
};

int main() {
	FileReader fin ("D-small-attempt0.in");
	FileWriter fout ("out.txt");

	int caseCount;
	vector <myclass> q;
	fin >> caseCount;
	fin.readLine();
	rep(cc,caseCount) {
		/*input*/
		int n;
		fin >> n;
		rep(i,n){
		    myclass t(0);
		    fin >> t.num;
		    t.role = 0;
		    q.push_back(t);
		}
		rep(i,n){
		    myclass t(0);
		    fin >> t.num;
		    t.role = 1;
		    q.push_back(t);
		}
		/*solve*/
		sort(q.begin(),q.end());
		int t1, t2;
		int r1, r2;
		t1 = 0;
		t2 = 0;
		dwn(i,q.size()){
		    if (q[i].role == 1) t2++;
		    else if (t2 > 0) t2--;
		    else t1++;
		   // cout << q[i].num << ' ' << q[i].role << ' ' << t1 << ' ' << t2 << endl;
		}
		r1 = t1;
		t1 = 0;
		t2 = 0;
		rep(i,q.size()){
		    if (q[i].role == 1) t2++;
		    else if (t2 > 0) t2--;
		    else t1++;
		}
		r2 = n - t1;
		q.clear();
		/*output*/
		stringstream ss;
		ss << "Case #" << cc + 1 << ": " << r2 << ' ' << r1 << endl;
		fout << ss.str().c_str();
		cout << ss.str().c_str();
	}
	return 0;
}
