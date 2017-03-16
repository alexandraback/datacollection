#include<bits/stdc++.h>
#define ALL(X)      X.begin(),X.end()
#define FOR(I,A,B)  for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B) for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B) for(int (I) = (A); (I) >= (B); (I)--)
#define CLEAR(X)    memset(X,0,sizeof(X))
#define PB          push_back
#define MP          make_pair
#define X           first
#define Y           second
using namespace std;
typedef signed long long slong;
typedef long double ldouble;
const slong Infinity = 1000000100;
const ldouble Epsilon = 1e-9;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T,U>&p) {return os << "(" << p.X << "," << p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& V) { os << "["; FORW(i,0,size(V)) os << V[i] << ((i==size(V)-1) ? "" : ","); return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& S) {os << "("; for(auto i: S) os << i << (i==*S.rbegin()?"":","); return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& M){os << "{"; for(auto i: M) os << i << (i.X==M.rbegin()->X?"":","); return os << "}"; }
template<typename T, typename F> T lbound(T p, T q, F f) { static_assert(is_integral<T>::value, "integral type required"); while(p < q) { T r = p+(q-p)/2; if(f(r)) q = r; else p = r+1; } return p; }
template<typename T, typename F> T lboundl(T p, T q, F f) { static_assert(is_floating_point<T>::value, "floating point type required"); FOR(i,1,70) { T r = (p+q)/2; if(f(r)) q = r; else p = r; } return p; }
template<typename T, typename U> bool contain(T t, U u) { return t.find(u) != t.end(); }
template<typename T> int size(T t) { return t.size(); }

const int MAXN = 30;

vector<vector<int> > prefs(slong n)
{
	vector<vector<int> > R;
	vector<int> T;
	while(n != 0)
	{
		T.push_back(n%2);
		n /= 2;
	}
	reverse(ALL(T));
	R.push_back(T);
	FORD(i,size(T)-1,0) 
	{
		if(T[i] != 0) FORD(j,T[i]-1,0) 
		{
			--T[i];
			R.push_back(T);
		}
		T[i] = -1;
	}
	FORW(i,0,size(R))
	{
		reverse(ALL(R[i]));
		while(size(R[i]) != MAXN) R[i].PB(0);
	}
	return R;
}

vector<int> to_bits(slong n)
{
	vector<int> R(MAXN);
	FORW(i,0,MAXN) R[i] = ((n&(1<<i)) != 0);
	return R;
}	

int A, B, K;


void read_data()
{
	scanf("%d %d %d", &A, &B, &K);
	--A;
	--B;
	--K;
}

slong subresult(vector<int> X, vector<int> Y, vector<int> Z)
{
//	cout << endl << X << endl << Y << endl << Z << endl;
	slong result = 1;
	FORW(i,0,MAXN)
	{
		int x = X[i];
		int y = Y[i];
		int z = Z[i];
		int r = 0;
		FOR(a,0,1) if(x == -1 or x == a)
			FOR(b,0,1) if(y == -1 or y == b)
				FOR(c,0,1) if(z == -1 or z == c)
					if((a&b) == c)
						++r;
		result *= r;
	}	
	return result;
}

void solve()
{
	slong r = 0;
	vector<vector<int>> P = prefs(K);
	vector<vector<int>> X = prefs(A);
	vector<vector<int>> Y = prefs(B);
	for(auto &p: P) for(auto &x: X) for(auto &y: Y) r += subresult(x, y, p);
	printf("%lld", r);
}

int main()
{
//	cout << prefs(6) << endl; return 0;
	int z;
	scanf("%d", &z);
	FOR(_,1,z)
	{
		printf("Case #%d: ", _);
		read_data();
		solve();
		printf("\n");
//		return 0;
	}
	return 0;
}
