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
#include <sstream>

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

#define MAXN 2000010

int tcase,A,B;
int au[MAXN];

int main()
{
	cin >> tcase;
	FOR(t,1,tcase)
	{
		RESET(au,0);
		cin >> A >> B;
		long long res = 0;
		int mul = 1;
		int tmp = A;
		int cy = 0;
		while(tmp > 0)cy++,mul *= 10,tmp /= 10;
		mul /= 10;
		FOR(i,A,B)
		{
			int split = 10;
			int split2 = mul;
			REP(j,cy-1)
			{
				int a = (i%split)*split2+i/split;
				if(a > i && a <= B && au[a] != i)
				{
					res++;
					au[a] = i;
				}
				split *= 10;
				split2 /= 10;
			}
		}
		cout << "Case #" << t << ": " << res << endl;
	}
	return 0;
}
