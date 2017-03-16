// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

#define MAXL (10004)

int T, L;
LL X;
string S;

int F[8][8];
const int I = 2;
const int J = 3;
const int K = 4;
const string ans[2] = {"NO", "YES"};

int A[MAXL];
int B[MAXL];

inline int sgn(int &a)
{
	if(a > 0) return 1;
	else
	{
		a = -a;
		return -1;
	}
}
inline int f(int a, int b)
{
	int s = sgn(a) * sgn(b);
	return s * F[a][b];
}

inline int g(char c)
{
	return c - 'g';
}

int main()
{
	F[1][1] = 1;
	F[1][I] = I;
	F[1][J] = J;
	F[1][K] = K;
	F[I][1] = I;
	F[I][I] = -1;
	F[I][J] = K;
	F[I][K] = -J;
	F[J][1] = J;
	F[J][I] = -K;
	F[J][J] = -1;
	F[J][K] = I;
	F[K][1] = K;
	F[K][I] = J;
	F[K][J] = -I;
	F[K][K] = -1;

	cin >> T;
	FOR(tt,1,T+1)
	{
		cin >> L >> X;
		cin >> S;

		int t = 1;
		FOR(i,0,L) A[i] = t = f(t, g(S[i]));
		t = 1;
		ROF(i,L-1,-1) B[i] = t = f(g(S[i]), t);
		int C = A[L-1];

		int y = 0;

		int r = 1;
		int c = C;
		LL x = X;
		while(x > 0)
		{
			if(x&1) r = f(r,c);
			c = f(c,c);
			x >>= 1;
		}
		if(r == -1)
		{
			LL a1 = X;
			int a2 = 0;
			t = 1;
			FOR(i,0,8)
			{
				int z = 0;
				FOR(j,0,L)
				{
					if(f(t,A[j]) == I)
					{
						z = 1;
						a1 = i;
						a2 = j+1;
						break;
					}
				}
				if(z) break;
				t = f(t,C);
			}

			LL b1 = X;
			int b2 = 0;
			t = 1;
			FOR(i,0,8)
			{
				int z = 0;
				ROF(j,L-1,-1)
				{
					if(f(B[j],t) == K)
					{
						z = 1;
						b1 = i;
						b2 = L-j;
						break;
					}
				}
				if(z) break;
				t = f(t,C);
			}
			a1 += b1;
			a2 += b2;
			a1 += a2 / L;
			if(a1 < X) y = 1;
		}

		printf("Case #%d: %s\n", tt, ans[y].c_str());
	}

	return 0;
}
