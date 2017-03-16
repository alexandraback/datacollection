#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long int LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const int INF = 1000000001;
const LD EPS = 10e-9;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define abs(a) ((a)<0 ? -(a) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int tc;
string s;
LL licz, mian;

bool pow2(LL x)
{
	return (x&(x-1)) == 0;
}

LL nwd(LL a, LL b)
{
	while(b != 0)
	{
		LL c = a%b;
		a = b;
		b = c;
	}	
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> tc;
	FOR(t, 1, tc)
	{
		cin >> s;
		int slash = s.find('/');
		string _licz = s.substr(0, slash);
		string _mian = s.substr(slash+1);
		
		stringstream l(_licz), m(_mian);
		l >> licz;
		m >> mian;
		
		LL gcd = nwd(licz, mian);
		licz /= gcd;
		mian /= gcd;
		
		//cout << licz << " " << mian << " -> " << nwd(licz, mian) << endl;
		
		if(!pow2(mian))
		{
			cout << "Case #" << t << ": impossible" << endl;
			continue;	
		}
		
		int res = 1;
		while(2*licz < mian && res < 40)
		{
			licz *= 2;
			res++;
		}
		if(res == 40 && 2*licz != mian)
		{
			cout << "Case #" << t << ": impossible" << endl;
			continue;	
		}
		
		/*if(licz%2)
		{
			licz *= 2;
			mian *= 2;	
		} 
		
		int res = -1;
		while(mian%2 == 0)
		{
			res++;
			mian /= 2;
		}*/
		
		if(res > 40) cout << "Case #" << t << ": impossible" << endl;
		else cout << "Case #" << t << ": " << res << endl;
	}
	//system("pause");
	return 0;
}

