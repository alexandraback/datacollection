#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pI;
typedef pair<string, int> pSI;
typedef pair<int, string> pIS;

#define FOR(i,n) for(int i=0, upTo##i=n; i<upTo##i; ++i)
#define REVFOR(i,n) for(int i=(n)-1; i>=0; --i)
#define FOR2(i,b,n) for(int i=b; i<(n); ++i)
#define REVFOR2(i,b,n) for(int i=(n)-1; i>=b; --i)
#define SC(i) scanf("%d", i)
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define MIN(C) *min_element(ALL(C))
#define MAX(C) *max_element(ALL(C))
#define A first
#define B second


vi test(string val) {
	int t['Z' + 1] = { 0 };

	FOR(i, val.size()) {
		t[val[i]]++;
	}

	vi res;

	string s[] = { "ZERO", "SIX", "TWO", "FOUR", "EIGHT","SEVEN", "FIVE", "ONE",  "THREE", "NINE" };
	int v[] = { 0,6,2,4,8,7,5,1,3,9 };

	int sv[10]['Z' + 1] = { 0 };

	FOR(i, 10) {
		FOR(j, s[i].size()) {
			sv[i][s[i][j]]++;
		}
	}


	while (true) {
		bool stop = true;
		FOR(i, 10) {
			bool ok = true;
			string ss = s[i];
			FOR2(j, 'A', 'Z' + 1) {
				if (sv[i][j] > t[j])
				{
					ok = false;
					break;
				}
			}
			if (ok) {
				stop = false;
				res.push_back(v[i]);
				FOR2(j, 'A', 'Z' + 1) {
					t[j] -= sv[i][j];
				}
				break;
			}
		}

		if (stop) {
			break;
		}
	}

	//FOR2(j, 'A', 'Z' + 1) {
	//	if (t[j] != 0) {
	//		putchar(j);
	//	}
	//}

	return res;
}

void start() {
	int n; cin >> n;
	FOR(_i, n) {
		string x;
		cin >> x;

		vi res = test(x);
		sort(ALL(res));

		printf("Case #%d: ", _i + 1);
		FOR(i, res.size()) {
			printf("%d", res[i]);
		}
		printf("\n");
	}
}

int main(void) {
	start();

	return 0;
}
