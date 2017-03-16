#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
#define Sz size()
#define mp make_pair
#define foreach(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define Say(x) cerr << #x << " = " << x << endl
#define For(i, n) for(int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vint;
typedef pair <int,int> pii;

const int M = 100 + 4, Inf = 1e9 + 10;

/////////////////////////////////////////////////////////////////////////
string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char uc[10] = {'X', 'G', 'Z', 'S', 'W', 'V', 'H', 'U', 'O', 'I'};
int un[10] = {6, 8, 0, 7, 2, 5, 3, 4, 1, 9};
int main()
{
	ios::sync_with_stdio(0);
	int n;
	int cnt[27], ans[10];
	cin >> n;
	for (int t = 1; t <= n; t ++) {
		string s;
		cin >> s;
		memset(cnt, 0, sizeof cnt);
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < s.size(); i++)
			cnt[s[i] - 'A'] ++;
		for (int i = 0; i < 10; i++) {
			ans[un[i]] = cnt[uc[i] - 'A'];
			for (int j = 0; j < num[un[i]].size(); j++)
				cnt[num[un[i]][j] - 'A'] -= ans[un[i]];
		}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < 10; i ++)
			for (int j = 0; j < ans[i]; j++)
				cout << i;
		cout << endl;
	}
	return 0;
}
