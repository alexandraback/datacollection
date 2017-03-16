#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

void Solve()
{
	int n; cin >> n;
	vector<double> a(n), b(n);
	FOR(i, n) cin >> a[i];
	FOR(i, n) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int x = 0, y = 0;
	{
		int bcnt = 0;
		int i = 0, j = 0;
		for(; i < n && j < n; ++i){
			while(j < n && a[i] > b[j]) ++j;
			if(j < n){
				bcnt++;
				++j;
			}
		}
		y = n - bcnt;
	}
	{
		int ai = n-1;
		int acnt = 0;
		for(; ai >= 0; --ai){
			if(a[ai] < b[ai]) break;
			++acnt;
		}
		x = acnt;
		a.resize(ai+1);
		b.resize(ai+1);

		reverse(b.begin(), b.end());
		int i = 0, j = 0;
		int bcnt = 0;
		const int n2 = a.size();
		for(; i < n2; ++i, ++j){
			if(b[i] > a[j]){
				++bcnt;
			}else{
				break;
			}
		}
		x += n2 - bcnt;
	}
	cout << x << " " << y << endl;
}

int main()
{
	int T; cin >> T;
	FOR(t, T){
		cout << "Case #" << t+1 << ": ";
		Solve();
	}
	return 0;
}
