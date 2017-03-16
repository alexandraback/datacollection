#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))
#define each(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define PB push_back
#define MP make_pair
#define X first
#define Y second

template<class T> void fmax(T &a, T b) { if (a < b) a = b; }
template<class T> void fmin(T &a, T b) { if (a > b) a = b; }


string s[4];

bool find(char C) {
	bool F;
	rep(i, 4) {
		F = true;
		rep(j, 4)
			F &= s[i][j] == C || s[i][j] == 'T';
		if (F) return true;

		F = true;
		rep(j, 4)
			F &= s[j][i] == C || s[j][i] == 'T';
		if (F) return true;
	}
	
		F = true;
		rep(j, 4)
			F &= s[j][j] == C || s[j][j] == 'T';
		if (F) return true;

		F = true;
		rep(j, 4)
			F &= s[3-j][j] == C || s[3-j][j] == 'T';
		if (F) return true;

	return false;
}

int main() {
	int CNT;
	cin >> CNT;
	rep(cnt, CNT) {
		int sum = 0;
		rep(i, 4) {
			cin >> s[i];
			rep(j,4)
				sum += s[i][j] == '.';
		}
		cout << "Case #" << cnt+1 << ": ";
		if (find('O'))
			cout << "O won";
		else if (find('X'))
			cout << "X won";
		else if (sum)
			cout << "Game has not completed";
		else
			cout << "Draw";
		cout << endl;
	}
}