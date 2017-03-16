//Paweł Michalak, II UWr
#include<cstring>
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

const int MAXN = 1000100;
char A[MAXN];
slong N;
bool B[256];
int K;
vector<int> T;

void read_data()
{
	T.clear();
	scanf("%s %d", A+1, &K);
	N = strlen(A+1);
}

int result()
{
	int a = 0;
	FORD(i,N,1) 
	{
		if(B[(int)A[i]]) ++a;
		if(!B[(int)A[i]]) a = 0;
		if(a >= K) T.push_back(i);
	}
	//cout << T;
	reverse(ALL(T));
	slong result = 0;
	FOR(i,1,N)
	{
		if(lower_bound(ALL(T), i) == T.end()) continue;
		int t = *lower_bound(ALL(T), i);
		result += (N-(t+K)+2);
		//cout << i << " " << t << " " << (N-(t+K)+2) << endl;
	}
	return result;
}

int main()
{
	B['a'] = B['e'] = B['i'] = B['o'] = B['u'] = true;
	FORW(i,0,256) B[i] = !B[i];
	int z;
	scanf("%d", &z);
	FOR(i,1,z)
	{
		read_data();
		printf("Case #%d: %d\n", i, result());
	}
    return 0;
}
