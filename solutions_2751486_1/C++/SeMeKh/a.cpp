#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <valarray>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cassert>
#include <bitset>

#define show(x) cerr << "# " << #x << " = " << (x) << endl

#define FR(i, a, b) for(__typeof(a) i = a; i != b; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOREACH(i, t) FR(i, t.begin(), t.end())
#define SZ(x) ((int) (x).size())
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef complex<double> point;


template<class T> ostream& operator << (ostream &o, const vector<T> &t)	
{
	o << "[" << SZ(t);
	int f = 0;
	FOREACH(i, t)
		o << (f++ ? ", " : ": ") << (*i);
	return o << "]";
}

template<class T1, class T2> ostream& operator << (ostream &o, const pair<T1, T2> &p)
{
	return o << "(" << p.F << ", " << p.S << ")";
}

bool isc(char c)
{
	return string("aeiou").find(c) == string::npos;
}

int main()
{
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		cout << "Case #" << T+1 << ": ";
		
		string s;
		int n;
		cin >> s >> n;
		
		ll ans = 0;

		int l = 0;
		int b = -1;
		FOR(i, SZ(s))
		{
			if(isc(s[i]))
				l++;
			else
				l = 0;

			if(l >= n)
				b = i - n + 1;
			
			if(b != -1)
				ans += b + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
