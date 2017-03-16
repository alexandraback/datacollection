#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair

template<class P, class Q> inline bool mmin(P &a, Q b) { if (a > b){ a = b; return true;} return false;}
template<class P, class Q> inline bool mmax(P &a, Q b) { if (a < b){ a = b; return true;} return false;}

typedef long long LL;
typedef pair<int, int> pii;
typedef complex<double> point;

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

int n;
int ar[55][55];

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;
	rep(ii, nt) {
		cin >> n;
		LL x;
		cin >> x;
		LL y = 1;
		int k = n-2;
		for(int i=0; i<n-2 && y < x; ++i)
			y *=2, k--;
	//	cerr << y << ' ' << k << endl;
		cout << "Case #" << ii+1 << ": ";
		if(y < x)
			cout << "IMPOSSIBLE" << endl;
		else {
			rep(i, n)
				rep(j, n)
				ar[i][j] = 0;
			for(int i=1; i<n; ++i)
				for(int j=i+1; j<n; ++j)
					ar[i][j] = 1;
			if(k==0 && y==x) {
				for(int i=1; i<n; ++i)
					ar[0][i] = 1;
			}
			else {
				for(int i=k; i<n; ++i) {
					if(x >= y) {
						x -= y;
						ar[0][i] = 1;
					}
					y /= 2;
					if(y==0)
						y = 1;
				}
			}
			cout << "POSSIBLE" << endl;
			rep(i, n) {
				rep(j, n)
					cout << ar[i][j];
				cout << endl;
			}
		}
	}
}



