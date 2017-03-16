#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int testNum, num[300], digit[11];
string ss[10] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string str;
void solve(int n, int v) {
	digit[n] += v;
	for (int i=0; i<ss[n].size(); ++i) {
		num[ss[n][i]] -= v;
	}
}

int main () {
	scanf("%d", &testNum);
	for (int tn=1; tn<=testNum; ++tn) { 
		cin >> str;
		memset(num, 0, sizeof(num));
		memset(digit, 0, sizeof(digit));

		for (int i=0; i<str.size(); ++i)
			num[str[i]]++;

		solve(0, num['Z']);
		solve(2, num['W']);
		solve(4, num['U']);
		solve(6, num['X']);
		solve(8, num['G']);
		solve(1, num['O']);
		solve(3, num['R']);
		solve(5, num['F']);
		solve(7, num['V']);
		solve(9, num['E']);

		printf("Case #%d: ",tn);
		for (int i=0; i<10; ++i)
			cout << string(digit[i], '0'+i);
		cout << endl;
	}
	return 0;
}


