#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

char nums[10][7] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char id[10] = {'Z', 'W', 'G', 'X', 'U', 'H', 'F', 'V', 'O', 'N'};
int who[10] = { 0 ,  2 ,  8 ,  6 ,  4 ,  3 ,  5 ,  7 ,  1 ,  9 };

char s[3333];
int cnt[333];

void test() {
	int n;
	scanf("%s", s);
	for (n=0; s[n]; n++) cnt[s[n]]++;
	vi res;
	FOR(i,10) {
		while (cnt[id[i]] > 0) {
			FOR(j,7) cnt[nums[who[i]][j]]--;
			res.push_back(who[i]);
		}
	}
	sort(res.begin(), res.end());
	FOR(i,SZ(res)) printf("%c", '0'+res[i]);
	printf("\n");
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	for (int i = 1; i <= ttn; i++) {
		printf("Case #%d: ", i);
		test();
	}
	return 0;
}
