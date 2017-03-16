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

void solve()
{ 
	int e,r,n;
	ll v[20000];

	cin >> e >> r >> n;
	REP(i, n) {
		cin >> v[i];
	}

	ll dy[20][20];
	REP(i, e+1) {
		dy[0][i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		REP(j, e+1) dy[i][j] = 0;
		REP(j, e+1) {
			REP(k, e+1) {
				int energy = k + r;
				if(energy > e) energy = e;
				int base = dy[i-1][k];
				REP(l, e+1) {
					if(l > energy) break;
					int test = base + v[i-1] * (energy - l);
					if(test > dy[i][l]) dy[i][l] = test;
				}
			}
		}
	}
	/*
	REP(i, n+1) {
		REP(j, e+1) {
			cout << dy[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << dy[n][0] << endl;
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

