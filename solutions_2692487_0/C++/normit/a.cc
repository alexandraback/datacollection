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
	int a,n;
	cin >> a >> n;

	int motes[200];

	REP(i, n) {
		cin >> motes[i];
	}

	if (a == 1) {
		cout << n << endl;
		return;
	}

	sort(motes, motes+n);

	int min_sol = n;

	int added = 0;

	REP(i, n) {
		min_sol = min(min_sol, added + n-i);

		if (a > motes[i]) a += motes[i];
		else {
			while(a <= motes[i]) {
				++added;
				a += (a-1);
			}
			a += motes[i];
		}
	}
	min_sol = min(min_sol, added);

	cout << min_sol << endl;
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

