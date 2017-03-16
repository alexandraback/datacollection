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
	FileReader fin ("C-small-attempt3.in");
	FileWriter fout ("out.txt");

	int caseCount;
	int mp[50][50];
	string tp=".*c";
	fin >> caseCount;
	fin.readLine();
	rep(cc,caseCount) {
		/*input*/
		int R, C, M, flag, rot;
		flag = 0;
		fin >> R >> C >> M;
        int mx = (R>C)?R:C;
	    int resd=R*C-M;
		/*solve*/
		/*if (resd==1) {
        } else if (resd==4) {
        } else */
        if (R==1 || C==1) {
            if (M+1>mx) flag = 1;
            else flag = 2;
		} else if (R==2 || C==2) {
		    if ((resd%2==1 && resd!=1) || resd==2) flag=1;
		    else {
                if (C>R) {
                    int tt=R;
                    R=C;
                    C=tt;
                    rot=1;
                } else rot=0;
                cl(mp,0);
                rep(i,M/2) rep(j,2) mp[R-i-1][j]=1;
                mp[0][0]=2;
                if (resd==1) mp[0][1]=1;
		    }
		} else {
		    if (resd<8 && resd !=1 && resd !=4 && resd != 6) flag = 1;
            else {
                if (C>R) {
                    int tt=R;
                    R=C;
                    C=tt;
                    rot=1;
                } else rot=0;
                int ci=R-1;
                int ca=M/C;
                cl(mp,0);
                if (ca>R-3) ca = R-3;
                M-=ca*C;
                rep(i,ca) {
                    rep(j,C) mp[ci][j]=1;
                    ci--;
                }
                if (ca==R-3) {
                    int tm=M/3;
                    M-=tm*3;
                    rep(i,tm) rep(j,3) mp[j][C-i-1]=1;
                    if (tm<C-1) rep(i,M) mp[2][C-tm-i-1]=1;
                    else {
                        mp[1][0]=1;
                        mp[2][0]=1;
                    }
                } else if (M>1) {
                    rep(i,M-1) mp[ci][C-i-1]=1;
                    mp[ci-1][C-1]=1;
                } else if (M==1) {
                    mp[ci][C-1]=1;
                }
                mp[0][0]=2;
            }
		}
		/*output*/
		stringstream ss;
		ss << "Case #" << cc + 1 << ":" << endl;
		if (flag==1) ss << "Impossible\n";
		if (flag==2) {
            string t = (R>C)?"\n":"";
            rep(i,M) ss << '*' << t;
            rep(i,mx-M-1) ss << '.' << t;
            ss<<"c\n";
		}
		if (flag==0) {
            if (rot==0) {
                rep(i,R) {
                    rep(j,C) ss << tp[mp[i][j]];
                    ss << endl;
                }
            }else{
                rep(i,C) {
                    rep(j,R) ss << tp[mp[j][i]];
                    ss << endl;
                }
            }
		}
		fout << ss.str().c_str();
		cout << ss.str().c_str();
	}
	return 0;
}
