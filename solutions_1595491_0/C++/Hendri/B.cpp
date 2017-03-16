#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>

//Hendri's Template
#define REP(i, n) for(int i = 0, _n = (n); i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(A,v) memset(A, v, sizeof(A))
#define DEBUG(x) cout << #x << " = " << x << endl;

#define MP make_pair
#define PB push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

template<class T> inline T MIN(T a, T b){return a < b?a:b;}
template<class T> inline T MAX(T a, T b){return a > b?a:b;}

template<class T> inline void getInt(T& x)
{
	char c;
	int mul = 1;
	while((c = getchar()) != EOF)
	{
		if(c == '-')mul = -1;
		if(c >= '0' && c <= '9')
		{
			x = c-'0';
			break;
		}
	}
	if(c == EOF){x = EOF;return;}
	while(c = getchar())
	{
		if(c >= '0' && c <= '9')
		{
			x = (x<<1)+(x<<3)+(c-'0');
		}
		else break;
	}
	x *= mul;
}
//End of Hendri's Template

#define inf 999999

int tcase,N,S,p;
int kya[110][110];
int ups[110];

inline bool ok(int x)
{
	return x >= 0 && x <= 10;
}

int muach(int x,int l)
{
	if(l < 0) return -inf;
	if(kya[x][l] != -1)return kya[x][l];
	if(x == N)return kya[x][l] = l == 0 ? 0 : -inf;
	int ret = -inf;
	REP(i,11)
	{
		for(int j = -2; j <= 2; j++)
		{
			int satu = i;
			int dua = i+j;
			int tiga = ups[x]-satu-dua;
			int tinggiest = MAX(satu,MAX(dua,tiga));
			int rendahest = MIN(satu,MIN(dua,tiga));
			int ganteng = tinggiest >= p ? 1 : 0;
			if(!ok(dua) || !ok(tiga)) continue;
			if( tinggiest - rendahest > 2 ) continue;
			else if( tinggiest - rendahest == 2 )
				ret = MAX(ret,ganteng + muach(x+1,l-1));
			else ret = MAX(ret,ganteng + muach(x+1,l));
		}
	}
	return kya[x][l] = ret;
}

int main()
{
	cin >> tcase;
	FOR(t,1,tcase)
	{
		cin >> N >> S >> p;
		REP(i,N)cin >> ups[i];
		RESET(kya,-1);
		cout << "Case #" << t << ": " << muach(0,S) << endl;;
	}
	return 0;
}
