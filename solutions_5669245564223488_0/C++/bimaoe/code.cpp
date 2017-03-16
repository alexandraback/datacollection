#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#define mod 1000000007

using namespace std;

long long fat[101];
int first[26], mid[26], last[26], alleq[26], beg[26], end[26];

int val(char c) {
	return c-'a';
}

long long mult (long long a, long long b) {
	return (a*b)%mod;
}

void calcfat(void) {
	fat[0] = 1;
	for (int i = 1; i <= 100; i++) {
		fat[i] = mult(fat[i-1], i);
	}
}

int main (void) {
	int T, c;
	int i, j, n, tcnt;
	char s[100000];
	calcfat();
	scanf ("%d", &T);
	for (c = 1; c <= T; c++) {
		printf ("Case #%d: ", c);
		scanf ("%d", &n);
		memset(first, 0, sizeof first);
		memset(mid, 0, sizeof mid);
		memset(last, 0, sizeof last);
		memset(alleq, 0, sizeof alleq);
		memset(beg, -1, sizeof beg);
		memset(end, -1, sizeof end);
		vector<pair<int, int> > trains;
		tcnt = 0;
		for (i = 0; i < n; i++) {
			scanf ("%s", s);
			int len = strlen(s);
			bool eq = true;
			for (j = 1; j < len; j++)
				if (s[j] != s[j-1])	eq = false;
			if (eq)	alleq[val(s[0])]++;
			else {
				char l;
				first[val(s[0])]++;
				for (j = 1; j < len; j++) {
					if (s[j] != s[j-1]) {
						l = s[j];
						if(s[j-1] != s[0])	mid[val(s[j-1])]++;
					}
				}
				last[val(l)]++;
				beg[val(s[0])] = trains.size();
				end[val(l)] = trains.size();
				trains.push_back(make_pair(val(s[0]), val(l)));
				tcnt++;
			}
		}
		bool ok = true;
		for (i = 0; i < 26; i++) {
			if (first[i] > 1 || last[i] > 1 || mid[i] > 1)	ok = false; 
			if (mid[i]) {
				if (alleq[i] || first[i] || last[i])	ok = false;
			}
			//if (first[i]+mid[i]+last[i]+alleq[i])	printf ("%c %d %d %d %d\n", i+'a', first[i], mid[i], last[i], alleq[i]);
		}
		if (!ok) {
			printf ("0\n");
			continue;
		}
		int cnt = 0;
		long long ans = 1;
		for (i = 0; i < 26; i++) {
			long long currans = 1;
			if (first[i] && !last[i]) {
				cnt++;
				currans = 1;
				int curr = i;
				while (!(last[curr] && !first[curr])) {
					currans = mult(currans, fat[alleq[curr]]);
					int currtrain = beg[curr];
					curr = trains[currtrain].second;
					tcnt--;
				}
				currans = mult(currans, fat[alleq[curr]]);
			} else if (!first[i] && !last[i] && alleq[i]) { // blocos avulsos
				currans = fat[alleq[i]];
				cnt++;
			}
			ans = mult(ans, currans);
		}
		if(tcnt)	ans = 0;
		ans = mult(ans, fat[cnt]);
		printf ("%lld\n", ans);
	}
	return 0;
}