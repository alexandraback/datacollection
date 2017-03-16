#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
using namespace std;

#define UN(c) SORT(c),v.erase(unique(c.begin(),c.end()),c.end())
#define SORT(c) sort(c.begin(), c.end())

int N;
int a[1000], b[1000];
int c[1000];

int main()
{
	if( freopen("B-large.in", "rt", stdin) ) {
		freopen("B-large.out", "wt", stdout);
	} else 	if( freopen("B-small.in", "rt", stdin) ) {
		freopen("B-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;
	cerr << "Total test cases: " << T << endl;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		cin >> N;
		int stars = 0, games = 0, dw = 0;;
		for(int i = 0; i < N; ++i) {
			cin >> a[i] >> b[i];
			c[i] = 0;
			if(b[i] <= stars) {
				stars += 2;
				++games;
				c[i] = 2;
				++dw;
			}
		}

		bool played = false;
		do
		{
			played = false;
			bool d = false;
			do {
				d = false;
				for(int i = 0; i < N; ++i) {
					if(c[i] != 2 && b[i] <= stars) {
						stars += 2-c[i];
						++games;
						c[i] = 2;
						played = true;
						d = true;
						++dw;
					}
				}
			} while(d);
			int t = -1, m = 0;
			for(int i = 0; i < N; ++i) {
				if(c[i] == 0 && a[i] <= stars) {
					if(b[i] > m) {
						t = i;
						m = b[i];
					}
				}
			}
			if(t != -1) {
				++stars;
				++games;
				c[t] = 1;
				played = true;
			}
		} while(played && (dw < N) );
		if(dw != N) cout << "Case #" << case_num << ": " << "Too Bad" << endl;
		else cout << "Case #" << case_num << ": " << games << endl;
	}
 	return 0;
}