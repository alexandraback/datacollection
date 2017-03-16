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

void factorize(ll n, int& a, int &b, int &c, int &d)
{
	a = b = c = d = 0;
	while(n > 1) {
		if (n % 2 == 0) {
			n /= 2;
			++a;
		}
		if (n % 3 == 0) {
			n /= 3;
			++b;
		}
		if (n % 5 == 0) {
			n /= 5;
			++c;
		}
		if (n % 7 == 0) {
			n /= 7;
			++d;
		}
	}
}

void solve()
{ 
	int r, n, m, K;

	cin >> r >> n >> m >> K;
	REP(i,r) {
		cout << endl;
		ll prod[20];
		int ma=0,mb=0,mc=0,md=0;

		REP(j,K) {
			cin >> prod[j];
			int a,b,c,d;
			factorize(prod[j], a,b,c,d);
			if(a > ma) ma = a;
			if(b > mb) mb = b;
			if(c > mc) mc = c;
			if(d > md) md = d;
		}
		int fill_n = n;
		while(md) {
			cout << 7;
			--md;
			--fill_n;
		}
		while(mc) {
			cout << 5;
			--mc;
			--fill_n;
		}
		REP(j,K) {
			if(prod[j] == 2) {
				cout << 2;
				--ma;
				--fill_n;
			}
			if(prod[j] == 3) {
				cout << 3;
				--mb;
				--fill_n;
			}
		}

		while(ma+mb > fill_n && fill_n) {
			if(ma > mb) {
				if(ma+mb - 2 >= fill_n) {
					cout << 8;
					ma -= 3;
					--fill_n;
				}
				else {
					cout << 4;
					ma -= 2;
					--fill_n;
				}
			}
			else {
				if(ma && mb) {
					cout << 6;
					--ma;
					--mb;
					--fill_n;
				}
			}
		}
		while(mb) { --mb; --fill_n; cout << 3; }
		while(ma) { --ma; --fill_n; cout << 2; }
		while(fill_n) {
			--fill_n;
			cout << rand() % 6 + 2;
		}
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

