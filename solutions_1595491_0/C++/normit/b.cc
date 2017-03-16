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

struct Tri {
	int total;
	bool a, b;
};

int go(int i, int s, int n, Tri t[]) {
	if(i >= n) return (s == 0) ? 0 : -1000;
	int a0 = -1000;
	if(s > 0 && t[i].total >= 2 &&
		t[i].total <= 28) {
		a0 = go(i+1, s-1, n, t) + t[i].a;
	}
	int a1 = go(i+1, s, n, t) + t[i].b;
	return max(a0,a1);
}

void solve()
{
	int n, s, p;
	Tri t[110];
	cin >> n >> s >> p;
	REP(i, n) {
		cin >> t[i].total;
		int min_a = t[i].total / 3;
		int min_b = min_a;
		int kind = t[i].total % 3;
		switch(kind) {
		case 0:
			min_a += 1;
			break;
		case 1:
			min_a += 1;
			min_b += 1;
			break;
		case 2:
			min_a += 2;
			min_b += 1;
			break;
		}
		t[i].a = (min_a >= p);
		t[i].b = (min_b >= p);
	}	
	cout << go(0, s, n, t) << endl;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

