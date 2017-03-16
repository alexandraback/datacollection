/*********************************************
Author:		Weichao Luo (lwc626@hotmail.com)
FileName:	A.cpp
*********************************************/

#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<utility>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
 
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define EMPTY(A,n) memset(A,(n),sizeof(A))
#define NINF 0x80000000
#define PINF 0x7fffffff
#define NLINF (1LL<<60)//0x8000000000000000
#define PLINF (1LL<<55)//0x7ffffffffffffffLL
#define FOR(i, n) for(int i=0;i<(n);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
 
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<pair<string,int> > VSI;
typedef vector<pair<int,string> > VIS;
typedef vector<PII> VII;
typedef map<int,int> MII;
typedef map<string,string> MSS;
typedef map<string ,int > MSI;
typedef map<int , string > MIS;
typedef priority_queue<char,vector<char>,greater<char> > PCG;
typedef long long LL;
 
template<class Ta,class Tb> inline void checkmin(Ta &a,Tb b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lowbit(T n){return n&(-n);}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)
{
	if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
	if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
	if(b==0){x=1;y=0;return a;}
	else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}
}
 
const double pi=acos(-1.0);
const double ei=2.718281828459;
const double eps=(1e-5);
const int dx[8]={-1,0,1,0,-1,1,1,-1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

const int MAXN = 205;
const int MAXM = 50010 ;

bool guess(char c, string board[]) {
	map<char, int> mci;
	FOR(i, 4) {
		mci.clear();
		FOR(j, 4)
			mci[board[i][j]] ++;
		if(mci[c] == 4 || mci[c] == 3 && mci['T'] == 1)
			return true;
		mci.clear();
		FOR(j, 4)
			mci[board[j][i]] ++;
		if(mci[c] == 4 || mci[c] == 3 && mci['T'] == 1)
			return true;
	}
	int sx = 0, sy = 0;
	mci.clear();
	FOR(i, 4) {
		mci[board[sx][sy]] ++;
		sx += 1;
		sy += 1;
	}
	if(mci[c] == 4 || mci[c] == 3 && mci['T'] == 1)
			return true;
	mci.clear();
	sx = 0, sy = 3;
	FOR(i, 4) {
		mci[board[sx][sy]] ++;
		sx += 1;
		sy += -1;
	}
	if(mci[c] == 4 || mci[c] == 3 && mci['T'] == 1)
			return true;
	return false;
}
int main(int argc, char const *argv[]){
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int cases ; 
	cin >> cases;
	//cout << cases << endl;
	//cases = 1000;
	FORE(tc, 1,cases) {

		//break;
		string board[4];
		bool over = true;
		FOR(i, 4){
			cin >> board[i];
			FOR(j, 4) if(board[i][j] == '.') over = false;
		}
		cout << "Case #" << tc << ": ";
		if (guess('X',board)) {
			cout << "X won" << endl;
		} else if (guess('O',board)) {
			cout << "O won" << endl;
		} else if (over){
			cout << "Draw" << endl;
		} else {
			cout << "Game has not completed" << endl;
		}
	}
	return 0;
}