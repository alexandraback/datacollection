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

char A[5][5];

void read_data()
{
	FOR(i,1,4) FOR(j,1,4)
	{
		char c;
		do scanf("%c", &c);
		while(c == ' ' or c == '\n');
		A[i][j] = c;
	}
}

bool is_O(int x, int y)
{
	return A[x][y] == 'O' or A[x][y] == 'T';
}

bool is_X(int x, int y)
{
	return A[x][y] == 'X' or A[x][y] == 'T';
}

bool solve(bool is(int,int))
{
	FOR(i,1,4) 
	{
		bool ok = true;
		FOR(j,1,4) if(!is(i,j)) ok = false;
		if(ok) return true;
	}
	
	FOR(i,1,4) 
	{
		bool ok = true;
		FOR(j,1,4) if(!is(j,i)) ok = false;
		if(ok) return true;
	}
	
	bool t = true;
	FOR(i,1,4) if(!is(i,i)) t = false;
	if(t) return true;
	
	bool q = true;
	FOR(i,1,4) if(!is(i,5-i)) q = false;
	if(q) return true;
	
	return false;
}

bool draw()
{
	FOR(i,1,4) FOR(j,1,4) if(A[i][j] == '.') return false;
	return true;
}

int main()
{
	int z;
	scanf("%d", &z);
	FOR(i,1,z)
	{
		read_data();
		if(solve(is_O)) printf("Case #%d: O won\n", i);
		else if(solve(is_X)) printf("Case #%d: X won\n", i);
		else if(draw()) printf("Case #%d: Draw\n", i);
		else printf("Case #%d: Game has not completed\n", i);
	}
    return 0;
}
