#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ForC(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n-1); i >= 0; i--)

using namespace std;
const double PI = acos(-1.0);

typedef long long ll;
typedef pair<int, int> pii;

int main (void) {
	int t;
	scanf("%d\n", &t);
	for (int cases = 1; cases <=t ; cases++) {
		string str;
		cin >> str;
		deque <char> r;
		r.pb(str[0]);
		for (int i = 1; i < str.size(); i++) {
			if (str[i] < r.front()) r.pb(str[i]);
			else r.push_front(str[i]);
		}
		printf("Case #%d: ", cases);
		while (!r.empty()) {
			printf("%c", r.front());
			r.pop_front();
		}
		printf("\n");

	}
	return 0;
}
