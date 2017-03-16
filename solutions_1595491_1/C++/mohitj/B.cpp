#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define UN(c) SORT(c),v.erase(unique(c.begin(),c.end()),c.end())
#define SORT(c) sort(c.begin(), c.end())

int main()
{
	if( freopen("B-large.in", "rt", stdin) ) {
		freopen("B-large.out", "wt", stdout);
	} else 	if( freopen("B-small.in", "rt", stdin) ) {
		freopen("B-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		int N, S, p;
		cin >> N >> S >> p;
		int ans = 0;
		for(int i = 0; i < N; ++i) {
			int score;
			cin >> score;
			if( score >= 3 * p - 2) ++ans;
			else if( (S > 0) && (score >= 2) && ( score >= 3 * p - 4) ) {
				--S;
				++ans;
			}
		}

		cout << "Case #" << case_num << ": " << ans << endl;
	}
 	return 0;
}