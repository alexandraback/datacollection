#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 20;

char s1[MAXN], s2[MAXN], ans1[MAXN], ans2[MAXN];
char ts[2][MAXN];

ll ans, ss1, ss2;

ll get(int p, char *s, int t) {
	ll ret = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) 
		if (s[i] == '?') {
			ret = ret * 10 + (t>0?0:9);
			ts[p][i] = t>0?'0':'9';
		}
		else {
			ret = ret * 10 + s[i] - '0';
			ts[p][i] = s[i];
		}

	return ret;
}

void calc(char *p, char *q) {
	int t = p[0] - q[0];
	ll t1 = get(0, s1, t);
	ll t2 = get(1, s2, -t);
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << abs(t1-t2) << endl;
	//cout << t1 << endl;
	//cout << t2 << endl;
	//cout << "---------------" << endl;
	if (abs(t1-t2) < ans) {
		ans = abs(t1-t2);
		ss1 = t1;
		ss2 = t2;
		strcpy(ans1, ts[0]);
		strcpy(ans2, ts[1]);
	}
	else if(abs(t1-t2) == ans && (t1 < ss1 || (t1 == ss1 && t2 < ss2))) {
		ans = abs(t1-t2);
		ss1 = t1;
		ss2 = t2;
		strcpy(ans1, ts[0]);
		strcpy(ans2, ts[1]);
	}
}

void deal(char *s1, char *s2) {
	if (s1[0] == 0) {
		calc(s1, s2);
		return;
	}
	if (s1[0] != '?' && s2[0] != '?') {
		if (s1[0] != s2[0]) calc(s1, s2);
		else deal(s1+1, s2+1);
	}
	else if (s1[0] == '?' && s2[0] == '?') {
		s1[0] = '0', s2[0] = '1';
		calc(s1, s2);
		s1[0] = '1', s2[0] = '0';
		calc(s1, s2);
		s1[0] = '0', s2[0] = '0';
		deal(s1+1, s2+1);
	}
	else if(s1[0] != '?' && s2[0] == '?') {
		if (s1[0] !='9') {
			s2[0] = s1[0] + 1;
			calc(s1, s2);
		}
		if (s1[0] !='0') {
			s2[0] = s1[0] - 1;
			calc(s1, s2);
		}
		s2[0] = s1[0];
		deal(s1+1, s2+1);
	}
	else if(s1[0] == '?' && s2[0] != '?') {
		if (s2[0] !='9') {
			s1[0] = s2[0] + 1;
			calc(s1, s2);
		}
		if (s2[0] !='0') {
			s1[0] = s2[0] - 1;
			calc(s1, s2);
		}
		s1[0] = s2[0];
		deal(s1+1, s2+1);
	}
}

void work() {
	ans = (ll)1e18;
	ts[0][strlen(s1)] = 0;
	ts[1][strlen(s2)] = 0;
	deal(s1, s2);
	printf("%s %s\n", ans1, ans2);
}
	

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		scanf("%s %s", s1, s2);
		printf("Case #%d: ", tt);
		work();
	}
	return 0;
}
