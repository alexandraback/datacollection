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

/*
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
*/

void solve()
{
	int n, s, p;
	cin >> n >> s >> p;

	int count_always = 0;
	int count_yes = 0;

	REP(i, n) {
		int t;
		cin >> t;
		int max_no = t / 3;
		int max_yes = t / 3;
		int kind = t % 3;
		switch(kind) {
		case 0:
			max_yes += 1;
			break;
		case 1:
			max_yes +=  1;
			max_no += 1;
			break;
		case 2:
			max_yes += 2;
			max_no += 1;
			break;
		}
		if(max_no >= p) ++count_always;
		else if(t >= 2 && t <= 28 && max_yes >= p) ++count_yes;
	}	
	cout << min(count_yes, s) + count_always << endl;
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

