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

char t[123];

void test() {
	int N,J;
	scanf("%d%d", &N, &J);
	for (int i = 2; i+4 <= N; i++) {
		printf("11");
		FOR(j,i-2) printf("0");
		printf("11");
		FOR(j,N-4-i) printf("0");
		printf("11 ");
		printf("3 2 3 2 7 2 9 2 3\n");
	}
	J -= N-5;
	FOR(i,N) t[i] = '0';
	FOR(i,10) t[i] = '1';
	t[N-1] = t[N-2] = '1';
	t[N] = 0;
	while (J--) {
		printf("%s 3 2 3 2 7 2 9 2 3\n", t);
		int last0=-1, last1=-1, cnt1=0;
		for (int i = N-3; i >= 0; i--) {
			if (t[i]=='1' && last0 == -1) cnt1++;
			if (t[i]=='0' && last0 == -1) last0 = i;
			if (t[i]=='1' && last0 != -1 && last1 == -1) last1 = i;
		}
		t[last1+1]='1';
		t[last1-1]='0';
		for (int i = last1+2; i < N-2; i++) t[i]='0';
		FOR(i,cnt1) t[last1+2+i] = '1';
	}
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	for (int i = 1; i <= ttn; i++) {
		printf("Case #%d:\n", i);
		test();
	}
	return 0;
}
