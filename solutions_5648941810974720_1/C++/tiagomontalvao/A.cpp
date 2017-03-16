#include <bits/stdc++.h>
using namespace std;

#define INF 0X3F3F3F3F
#define INFL 0x3F3F3F3F3F3F3F3FLL
#define MOD 1000000007
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sz(X) int((X).size())
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define pow2(X) ((X)*(X))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		string str;
		cin >> str;
		vi freq(26, 0), num(10, 0);
		for (int i = 0; i < sz(str); i++)
			freq[str[i]-'A']++;
		for (int i = 0; i < freq['Z' - 'A']; i++) {
			num[0]++;
			freq['E'-'A']--;
			freq['R'-'A']--;
			freq['O'-'A']--;
		}
		freq['Z'-'A'] = 0;
		for (int i = 0; i < freq['W' - 'A']; i++) {
			num[2]++;
			freq['T'-'A']--;
			freq['O'-'A']--;
		}
		freq['W'-'A'] = 0;
		for (int i = 0; i < freq['G' - 'A']; i++) {
			num[8]++;
			freq['E'-'A']--;
			freq['I'-'A']--;
			freq['H'-'A']--;
			freq['T'-'A']--;
		}
		freq['G'-'A'] = 0;
		for (int i = 0; i < freq['X' - 'A']; i++) {
			num[6]++;
			freq['S'-'A']--;
			freq['I'-'A']--;
		}
		freq['X'-'A'] = 0;
		for (int i = 0; i < freq['H' - 'A']; i++) {
			num[3]++;
			freq['T'-'A']--;
			freq['R'-'A']--;
			freq['E'-'A']--;
			freq['E'-'A']--;
		}
		freq['H'-'A'] = 0;
		for (int i = 0; i < freq['R' - 'A']; i++) {
			num[4]++;
			freq['F'-'A']--;
			freq['O'-'A']--;
			freq['U'-'A']--;
		}
		freq['R'-'A'] = 0;
		for (int i = 0; i < freq['F' - 'A']; i++) {
			num[5]++;
			freq['I'-'A']--;
			freq['V'-'A']--;
			freq['E'-'A']--;
		}
		freq['F'-'A'] = 0;
		for (int i = 0; i < freq['I' - 'A']; i++) {
			num[9]++;
			freq['N'-'A']--;
			freq['N'-'A']--;
			freq['E'-'A']--;
		}
		freq['I'-'A'] = 0;
		for (int i = 0; i < freq['O' - 'A']; i++) {
			num[1]++;
			freq['N'-'A']--;
			freq['E'-'A']--;
		}
		freq['O'-'A'] = 0;
		for (int i = 0; i < freq['S' - 'A']; i++) {
			num[7]++;
			freq['E'-'A']--;
			freq['V'-'A']--;
			freq['E'-'A']--;
			freq['N'-'A']--;
		}
		freq['S'-'A'] = 0;
		printf("Case #%d: ", t);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < num[i]; j++)
				printf("%d", i);
		}
		puts("");
	}
	return 0;
}