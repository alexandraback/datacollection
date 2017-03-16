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
	bool f = false;
	FOREACH(i, t)
		o << (f++ ? ", " : ": ") << (*i);
	return o << "]";
}

template<class T1, class T2> ostream& operator << (ostream &o, const pair<T1, T2> &p)
{
	return o << "(" << p.F << ", " << p.S << ")";
}

const int N = 4;
const int DC = 4;
const int DD[DC][2] = {{-1, +1}, {0, +1}, {+1, +1}, {+1, 0}};

char m[3*N][3*N];
char (*p)[3*N] = (char(*)[3*N])&m[N][N];

int main()
{
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		string res;

		FOR(i, 3*N)
			FOR(j, 3*N)
				m[i][j] = '.';

		FOR(i, N)
			FOR(j, N)
				cin >> p[i][j];

		bool cmp = true;
		FOR(i, N)
			FOR(j, N)
			{
				cmp &= (p[i][j] != '.');
				FOR(d, DC)
				{
					char ww[2] = {'X', 'O'};
					FOR(wC, 2)
					{
						char w = ww[wC];
						bool ok = true;
						FOR(t, N)
						{
							int ni = i + t * DD[d][0], nj = j + t * DD[d][1];
							ok &= (p[ni][nj] == w || p[ni][nj] == 'T');
						}
						if(ok)
						{
							res = string() + w + " won";
							goto hell;
						}
					}
				}
			}

		if(cmp)
			res = "Draw";
		else
			res = "Game has not completed";

hell:;
		 cout << "Case #" << T + 1 << ": " << res << endl;
	}
	return 0;
}
