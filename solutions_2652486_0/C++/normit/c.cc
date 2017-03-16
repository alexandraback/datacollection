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
	int r, n, m, K;

	cin >> r >> n >> m >> K;
	REP(i,r) {
		cout << endl;
		ll prod[20];
		REP(j,K) {
			cin >> prod[j];
		}
		bool success = false;
		for(int i0 = 2; i0 <= m; ++i0) {
			if(success) break;
			for(int i1 = 2; i1 <= m; ++i1) {
				if(success) break;
				for(int i2 = 2; i2 <= m; ++i2) {
					bool check = true;
					REP(j, K) {
						if(prod[j] == 1) continue;
						if(prod[j] == i0 || prod[j] == i1 || prod[j] == i2) continue;
						if(prod[j] == i0 * i1 || prod[j] == i0 * i2 || prod[j] == i1 * i2) continue;
						if(prod[j] == i0 * i1 * i2) continue;
						//cout << i0 << " " << i1 << " " << i2 << " " << prod[j] << endl;
						check = false; 
						break;
					}
					if(check) {
						success = true;
						cout << i0 << i1 << i2;
						break;
					}
				}
			}
		}
		// print solution
	}
	cout << endl;
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

