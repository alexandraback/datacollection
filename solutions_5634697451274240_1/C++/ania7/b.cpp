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

char s[1111];

void test() {
	scanf("%s", s);
	int n = 1, res=0;
	for (int i = 1; s[i]; i++) if (s[i] != s[i-1]) n++;
	bool pl = s[0]=='+';
	while (n>1 || !pl) {
		if (n&1) {
			if (pl) {
				n--;
			} else {
				res++;
				pl=1;
			}
		} else {
			if (pl) {
				res++;
				pl=0;
			} else {
				n--;
			}
		}
	}
	printf("%d\n", res);
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
