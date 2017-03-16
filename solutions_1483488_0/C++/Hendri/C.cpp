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

#define inf 999999
#define MAXN 2000010

int tcase,A,B;
set<pii> se;

int main()
{
	cin >> tcase;
	FOR(t,1,tcase)
	{
		cin >> A >> B;
		se.clear();
		int res = 0;
		FOR(i,A,B)
		{
			stringstream ss;
			ss << i;
			string s = ss.str();
			FOR(j,1,s.length()-1)
			{
				string ke = s.substr(j)+s.substr(0,j);
				int mon = atoi(ke.c_str());
				stringstream ss2;
				ss2 << mon;
				if(mon < i && s.length() == ss2.str().length() && mon >= A && mon <= B )
				{
					se.insert(MP(mon,i));
				}
			}
		}
		cout << "Case #" << t << ": " << se.size() << endl;
	}
	return 0;
}
