//Paweł Michalak, II UWr
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

int A[1010][1010];
int M, N;

void read_data()
{
	scanf("%d %d", &M, &N);
	FOR(i,1,M) FOR(j,1,N) scanf("%d", &A[i][j]);
}

string result()
{
	FOR(i,1,M) FOR(j,1,N)
	{
		bool x = true;
		FOR(t,1,M) if(A[t][j] > A[i][j]) x = false;
		
		bool y = true;
		FOR(t,1,N) if(A[i][t] > A[i][j]) y = false;
		
		if(!x and !y) return "NO\n";
	}
	return "YES\n";
}

int main()
{
	int z;
	scanf("%d", &z);
	FOR(i,1,z)
	{
		read_data();
		printf("Case #%d: %s\n", i, result().c_str());
	}
    return 0;
}
