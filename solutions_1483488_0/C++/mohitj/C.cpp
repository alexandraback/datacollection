#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;

#define UN(c) SORT(c),v.erase(unique(c.begin(),c.end()),c.end())
#define SORT(c) sort(c.begin(), c.end())

typedef int myints;

int dig(int n) {
	int ans = 0;
	while(n) {
		++ans;
		n /= 10;
	}
	return ans;
}

int getSmallest (int i) {
	int s = i, st = i;
	const int isd = dig(s);
	int m = 1;
	for(int i_ = 1; i_ < isd; ++i_) m *= 10;
	do {
		const int u = st % 10;
		st = st / 10 + u * m;
		if( dig(st) == isd) s = std::min<int>(s, st);
	} while (st != i);
	return s;
}

int main()
{
	if( freopen("C-large.in", "rt", stdin) ) {
		freopen("C-large.out", "wt", stdout);
	} else 	if( freopen("C-small.in", "rt", stdin) ) {
		freopen("C-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		map<myints, int> myintset;
		int A, B;
		cin >> A >> B;
		for(int i = A; i <= B; ++i) {
			const int s = getSmallest(i);
			myintset[s]++;
		}
		int ans = 0;
		for(map<myints, int>::iterator it = myintset.begin(); it != myintset.end(); ++it) {
			const int n = it->second;
			ans += n * (n - 1) / 2;
		}
		cout << "Case #" << case_num << ": " << ans << endl;
	}
 	return 0;
}