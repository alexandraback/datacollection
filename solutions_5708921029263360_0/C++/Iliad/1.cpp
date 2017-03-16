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

int x, y, z, k, m, mx, cur;
int cnt[3][5][5];
int ar[30][3];
int wow[30];
int ans[30];

inline bool add(int a, int b, int c, int d, int qq) {
	cnt[0][a][b] += d;
	cnt[1][a][c] += d;
	cnt[2][b][c] += d;
	cur += d;
	wow[qq] = d==1;
	if(cnt[0][a][b] > k || cnt[1][a][c] > k || cnt[2][b][c] > k)
		return false;
	return true;
}

void BT(int i) {
	if(m-i+cur <= mx)
		return;
	if(i==m) {
		mx = cur;
		rep(j, m)
			ans[j] = wow[j];
		return;
	}
	if(add(ar[i][0], ar[i][1], ar[i][2], 1, i))
		BT(i+1);
	add(ar[i][0], ar[i][1], ar[i][2], -1, i);

	BT(i+1);
}

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;
	rep(ii, nt) {
		cin >> x >> y >> z >> k;
		m = 0;
		rep(i, 3) rep(j, 5) rep(p, 5)
			cnt[i][j][p] = 0;
		rep(i, x) rep(j, y) rep(p, z) {
			ar[m][0] = i;
			ar[m][1] = j;
			ar[m][2] = p;
			++m;
		}
	//	cerr << "DAM " << m << endl;
		mx = 0;
		cur= 0;
		BT(0);
		cout << "Case #" << ii+1 << ": " << mx << endl;
		rep(i, m) if(ans[i])
			cout << ar[i][0]+1 << ' ' << ar[i][1]+1 << ' ' << ar[i][2]+1 << endl;
	}
}



