#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <ctime>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

const int MAXN = 101;
const long long MOD = 1000000007ll;

int N;
vector<string> car;
map<pair<pair<int, char>, int>, long long> memo;

long long solve(int seen, char last, int ch)
{
	long long ret = 0;
	if (ch == (1 << N) - 1) return 1;
	
	auto it = memo.find(make_pair(make_pair(seen, last), ch) );
	if (it != memo.end() ) {
		return it->second;
	}
	
	for (int i = 0; i < N; ++i) {
		if (ch & (1 << i) ) continue;
		bool ok = true;
		for (int j = 0; j < car[i].size(); ++j) {
			if ( (seen & (1 << (car[i][j] - 'a') ) ) || car[i][j] == last && j > 0 && car[i][j] != car[i][j - 1]) {
				ok = false;
				continue;
			}
		}
		if (ok) {
			ch |= 1 << i;
			int newseen = seen;
			int newlast = car[i][car[i].size() - 1];
			if (last != newlast) {
				newseen |= 1 << (last - 'a');
				for (int j = 0; j < car[i].size(); ++j) {
					if (car[i][j] == newlast) continue;
					newseen |= 1 << (car[i][j] - 'a');
				}
			}
			ret = (ret + solve(newseen, newlast, ch) ) % MOD;
			ch -= 1 << i;
		}
	}
	//printf("  solve(%s, %d) -> %d\n", prev.c_str(), ch, (int) ret);
	
	memo[make_pair(make_pair(seen, last), ch) ] = ret;
	
	return ret;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		
		car.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> car[i];
		}
		memo.clear();
		
		long long ans = 0;
		ans = solve(0, -1, 0);
		printf("Case #%d: %d\n", t, (int) ans);
		
		
	}
	
    return 0;
}
