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

const int MAXN = 1213;
int A[MAXN];
bool Q[MAXN];
int N;
int T;

void read_data()
{
	scanf("%d %d", &T, &N);
	FOR(i,1,N) scanf("%d", A+i);
	sort(A+1,A+N+1);
}

slong DP[MAXN][MAXN];
//DP[i][j] = jaką największą kulkę uzyskam wykonując i operacji i przechodząc przez pierwsze j klocków

int result()
{
	FORW(i,0,MAXN) FORW(j,0,MAXN) DP[i][j] = -Infinity;
	DP[0][0] = T;
	FOR(i,0,N) FOR(j,1,N)
	{
		DP[i][j] = -Infinity;
		//mogłem dodać nową kulkę, tak dużą jak tylko da się zjeść, no bo nie mniejszą przecież
		//if(DP[i-1][j] > 0) 
		if(i != 0) DP[i][j] = max(DP[i][j], 2*DP[i-1][j]-1);
		
		//mogłem sobie zjeść następną, po prostu (o ile jesteśmy już więksi)
		if(DP[i][j-1] > A[j]) DP[i][j] = max(DP[i][j], DP[i][j-1] + A[j]);
		
		//możemy usunąć nie przechodzić przez następną kulkę, kosztuje to tylko jedną oeprację
		//if(DP[i-1][j-1] > 0) 
		if(i != 0) DP[i][j] = max(DP[i][j], DP[i-1][j-1]);
	}
	
//	FOR(i,1,N) FOR(j,1,N) cout << make_pair(i,j) << " " << DP[i][j] << endl;
	FOR(i,0,N) if(DP[i][N] > 0) return i;
	return -1;
}

int main()
{
	int t;
	scanf("%d", &t);
	FOR(i,1,t)
	{
		read_data();
		printf("Case #%d: %d\n", i, result());
	}
    return 0;
}
