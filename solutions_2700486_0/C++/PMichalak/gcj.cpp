//Paweł Michalak, II UWr
#include<fstream>
#include<cassert>
#include<bitset>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<string>
#include<cmath>
#define ALL(X) X.begin(),X.end()
#define SIZE(X) ((int)X.size())
#define FOR(I,A,B) for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B) for(int (I) = (A); (I) < (B); (I)++)
#define FORD(I,A,B) for(int (I) = (A); (I) >= (B); (I)--)
#define FOREACH(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); ++a)
#define LBOUND(P,R,PRED) ({typeof(P) X=P,RRR=(R), PPP = P; while(PPP<RRR) {X = (PPP+(RRR-PPP)/2); if(PRED) RRR = X; else PPP = X+1;} PPP;})
#define CONTAIN(C,X) (C.find(X) != C.end())
#define CLEAR(X) memset(X, 0, sizeof(X))

using namespace std;
typedef signed long long slong;
const slong Infinity = 1000000001;

typedef long double ldouble;
const ldouble Epsilon = 0.000000001;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T,U>&p) {return os << "(" << p.first << "," << p.second << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& V) {os << "["; FOREACH(i, V) os << *i << (i-V.begin()+1==SIZE(V)?"":","); os << "]\n"; return os; }
template<typename T> ostream& operator << (ostream &os, const set<T>& S) {os << "("; FOREACH(i, S) os << *i << (*i==*S.rbegin()?"":","); os << ")\n"; return os; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& M){os << "{"; FOREACH(i, M) os << *i << (i->first==M.rbegin()->first?"":","); os << "}\n"; return os; }

const int MAXN = 4000;
int N, X, Y;
bool A[MAXN][MAXN];
bool D[MAXN];

void read_data()
{
	scanf("%d %d %d", &N, &X, &Y);
	int tx = (X+Y)/2+10;
	int ty = (Y-X)/2+10;
	X = tx;
	Y = ty;
}

int P[MAXN];
int Q[MAXN];

inline bool ok()
{
	FOR(i,1,N)
	{
		int x=18, y=18;
		while(x+y > 20 and (!A[x-1][y] or !A[x][y-1]))
		{
			if(!A[x-1][y-1] and !(x+y==21)) {--x; --y;}
			else if(A[x-1][y] and A[x][y-1]) break;
			else if(A[x-1][y]) --y;
			else if(A[x][y-1]) --x;
			else if(D[i]) --y;
			else --x;
		}
		A[x][y] = true;
		P[i] = x;
		Q[i] = y;
	}
	bool result = A[X][Y];
	//if(!D[1] and D[2] and !D[3]) FOR(q,1,3) cout << make_pair(P[q],Q[q]);
	FOR(i,1,N) 
	{
		A[P[i]][Q[i]] = false;
	}
	return result;
}

ldouble result()
{
	if(abs(X)+abs(Y) > 30) return 0;
	int r=0;
	FORW(i,0,1<<N) 
	{
		FORW(j,0,N) D[j+1] = ((i&(1<<j))!=0);
		if(ok()) 
		{
			//cout << bitset<3>(i) << endl;
			++r;
		}
	}
	return ldouble(r)/ldouble(1<<N);
}

int main()
{
	int t;
	scanf("%d", &t);
	FOR(i,1,t)
	{
		read_data();
		printf("Case #%d: %.10Lf\n", i, result());
	}
    return 0;
}
