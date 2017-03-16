#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int TC;
int cnt[32];
int num[10];

string s[10];

int main() {
    s[0] = "ZERO"; //'Z'
    s[1] = "ONE"; //last
    s[2] = "TWO"; //'W'
    s[3] = "THREE"; //'R' after 4
    s[4] = "FOUR"; //'U'
    s[5] = "FIVE"; //'F' after 4
    s[6] = "SIX"; //'X'
    s[7] = "SEVEN"; //'V' after 5
    s[8] = "EIGHT"; //'H' after 3
    s[9] = "NINE"; //'I' after 8

    string cr = "ZNWRUFXVHI";

    scanf("%d", &TC);

    vi ord = {0, 2, 4, 6, 3, 5, 8, 7, 9, 1};

    for (int tc = 1; tc <= TC; ++tc) {
	printf("Case #%d: ", tc);

	rep(i, 32) cnt[i] = 0;
	rep(i, 10) num[i] = 0;

	string _t;
	cin >> _t;
	rep(i, _t.size()) ++cnt[_t[i] - 'A'];

	for (int i : ord) {
	    int p = cr[i] - 'A';
	    num[i] = cnt[p];

	    rep(j, s[i].size()) cnt[s[i][j] - 'A'] -= num[i];
	}

	rep(i, 10) rep(j, num[i]) cout << i;
	    
	cout << endl;
    }

    return 0;
}
