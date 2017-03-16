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

int T;
int X, R, C;

string W[3] = {"","GABRIEL", "RICHARD"};

int main()
{
	cin >> T;
	FOR(tt,1,T+1)
	{
		cin >> X >> R >> C;
		if(R > C) swap(R,C);

		int w = 0;
		if(R*C % X != 0 || X >= 7 || R < (X+1)/2 || C < X) w = 2;
		else
		{
			if(X <= 3) w = 1;
			else if(X == 4) w = (R == 2) ? 2 : 1;
			else if(X == 5) w = (R == 3 && C == 5) ? 2 : 1;
			else w = (R == 3) ? 2 : 1;
		}
		printf("Case #%d: %s\n", tt, W[w].c_str());
	}

	return 0;
}
