//Karol Kaszuba
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;

#define FOR(i,x,y) for(int i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(int i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)

LL pot[100];

LL nwd(LL a, LL b)
{
	if(a > b) swap(a, b);
	if(a == 0) return b;
	return nwd(b % a, a);
}

LL stoi(string a)
{
	LL res = 0;
	FOR(i, 0, SIZE(a) - 1)
	{
		res *= 10;
		res += (a[i] - '0');
	}
	return res;
}

LL qlog(LL a)
{
	LL res = 1, wyn = 0;
	while(res * 2 <= a)
	{
		res *= 2;
		wyn++;
	}
	return wyn;
}

void jebaj()
{
	string s, a = "";
	LL x, y;
	cin >> s;
	REP(i, SIZE(s))
	{
		if(s[i] != '/')
			a.PB(s[i]);
		else
		{
			x = stoi(a);
			a = "";
		}
	}
	y = stoi(a);
	LL d = nwd(x, y);
	x /= d;
	y /= d;
	
	LL p = qlog(x), q = qlog(y);
	
	if(pot[q] != y)
	{
		cout << "impossible\n";
		return;
	}
	
	cout << q - p << "\n";
}

void prepro()
{
	pot[0] = 1;
	FOR(i, 1, 60)
		pot[i] = pot[i - 1] * 2;
}

int main()
{
	IOSYNC;
	int t;
	//t = 1;
	cin >> t;
	
	prepro();
	REP(i, t) 
	{
		cout << "Case #" << i + 1 << ": ";
		jebaj();
	}
}
