#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

using namespace std;

typedef long long ll;

pair<int, int> go(int cnt, int h, int l, int r, int w)
{
	if(cnt) {
		pair<int, int> res;
		res.first = res.second = 0;

		if(l < h) {
			pair<int, int> test = go(cnt-1, h, l+1, r, w);
			res.first += test.first;
			res.second += test.second;
		}
		if(r < h) {
			pair<int, int> test = go(cnt-1, h, l, r+1, w);
			res.first += test.first;
			res.second += test.second;
		}

		return res;
	}
	else {
		if(l >= w) return mp(1,1);
		else return mp(0,1);
	}
}

void solve()
{ 
	int n,x,y;

	cin >> n >> x >> y;

	int depth = abs(x) + abs(y);

	int d0 = (depth - 1) * (depth) / 2;	
	int d1 = (depth + 1) * (depth + 2) / 2;

	if (n >= d1) {
		cout << 1.0 << endl;
		return;
	}

	if (n <= d0) {
		cout << 0.0 << endl;
		return;
	}

	if (y == depth) {
		if (n >= d1) cout << 1.0 << endl;
		else cout << 0.0 << endl;
		return;
	}

	int trycnt = n - d0;

	pair<int, int> res = go(trycnt, depth, 0, 0, y+1);
	printf("%.9lf\n", double(res.first) / double(res.second));

	//cout << double(res.first) / double(res.second) << endl;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  string ee;
  getline(cin,ee);

  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

