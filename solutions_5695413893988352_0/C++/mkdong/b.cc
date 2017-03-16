#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

typedef unsigned long long u64;

char c[100];
char j[100];
int n;

bool ok_same()
{
	for (int i=0; i<n; ++i) {
		if (c[i] != '?' && j[i] != '?' && c[i] != j[i])
			return false;
	}
	for (int i=0; i<n; ++i) {
		if (c[i] == '?' && j[i] == '?')
			c[i] = j[i] = '0';
		else if (c[i] == '?')
			c[i] = j[i];
		else if (j[i] == '?')
			j[i] = c[i];
	}
	return true;
}

bool cansame(int i)
{
	if (c[i] != '?' && j[i] != '?' && c[i] != j[i])
		return false;
	return true;
}

u64 best;
char bestc[111];
char bestj[111];

bool _less(char *small, char *big)
{
	for (int i=0; i<n; ++i) {
		if (small[i] < big[i])
			return true;
		if (small[i] > big[i])
			return false;
	}
	return false;
}

void update_best(int diff, char *cc, char *jj)
{
	//cout << diff << ' ' << cc << jj << endl;
	assert(diff > 0);
	if (diff > best)
		return;
	if (diff < best) {
		best = diff;
		strcpy(bestc, cc);
		strcpy(bestj, jj);
		return;
	}
	if (_less(bestc, cc))
		return;
	if (_less(cc, bestc)) {
		best = diff;
		strcpy(bestc, cc);
		strcpy(bestj, jj);
		return;
	}
	if (_less(bestj, jj))
		return;
	if (_less(jj, bestj)) {
		best = diff;
		strcpy(bestc, cc);
		strcpy(bestj, jj);
		return;
	}
	return;
}


void get(int bit)
{
	u64 ccv, jjv;
	char cc[20];
	char jj[20];
	strcpy(cc, c);
	strcpy(jj, j);
	if (cc[bit] != '?' && jj[bit] != '?') {
		if (cc[bit] > jj[bit]) {
			ccv = cc[bit] - '0';
			jjv = jj[bit] - '0';
			for (int i=bit+1; i<n; ++i) {
				if (cc[i] == '?')
					cc[i] = '0';
				if (jj[i] == '?')
					jj[i] = '9';
				ccv = ccv * 10 + cc[i] - '0';
				jjv = jjv * 10 + jj[i] - '0';
			}
			update_best(ccv - jjv, cc, jj);
		} else if (cc[bit] < jj[bit]) {
			ccv = cc[bit] - '0';
			jjv = jj[bit] - '0';
			for (int i=bit+1; i<n; ++i) {
				if (cc[i] == '?')
					cc[i] = '9';
				if (jj[i] == '?')
					jj[i] = '0';
				ccv = ccv * 10 + cc[i] - '0';
				jjv = jjv * 10 + jj[i] - '0';
			}
			update_best(jjv - ccv, cc, jj);
		} else return;
	} else if (cc[bit] != '?') {
		ccv = cc[bit] - '0';
		jjv = ccv - 1;
		if (ccv > 0) {
			// cc > jj
			jj[bit] = jjv + '0';
			for (int i=bit+1; i<n; ++i) {
				if (cc[i] == '?')
					cc[i] = '0';
				if (jj[i] == '?')
					jj[i] = '9';
				ccv = ccv * 10 + cc[i] - '0';
				jjv = jjv * 10 + jj[i] - '0';
			}
			update_best(ccv - jjv, cc, jj);
		}
		strcpy(cc, c);
		strcpy(jj, j);
		ccv = cc[bit] - '0';
		jjv = ccv + 1;
		if (jjv < 10) {
			jj[bit] = jjv + '0';
			for (int i=bit+1; i<n; ++i) {
				if (cc[i] == '?')
					cc[i] = '9';
				if (jj[i] == '?')
					jj[i] = '0';
				ccv = ccv * 10 + cc[i] - '0';
				jjv = jjv * 10 + jj[i] - '0';
			}
			update_best(jjv - ccv, cc, jj);
		}
	} else if (jj[bit] != '?') {
		jjv = jj[bit] - '0';
		ccv = jjv + 1;
		if (ccv < 10) {
			// cc > jj
			cc[bit] = ccv + '0';
			for (int i=bit+1; i<n; ++i) {
				if (cc[i] == '?')
					cc[i] = '0';
				if (jj[i] == '?')
					jj[i] = '9';
				ccv = ccv * 10 + cc[i] - '0';
				jjv = jjv * 10 + jj[i] - '0';
			}
			update_best(ccv - jjv, cc, jj);
		}
		strcpy(cc, c);
		strcpy(jj, j);
		jjv = jj[bit] - '0';
		ccv = jjv - 1;
		if (jjv > 0) {
			// jj > cc
			cc[bit] = ccv + '0';
			for (int i=bit+1; i<n; ++i) {
				if (cc[i] == '?')
					cc[i] = '9';
				if (jj[i] == '?')
					jj[i] = '0';
				ccv = ccv * 10 + cc[i] - '0';
				jjv = jjv * 10 + jj[i] - '0';
			}
			update_best(jjv - ccv, cc, jj);
		}
	} else {
		// both ?
		ccv = 1;
		jjv = 0;
		cc[bit] = ccv + '0';
		jj[bit] = jjv + '0';
		// cc > jj
		for (int i=bit+1; i<n; ++i) {
			if (cc[i] == '?')
				cc[i] = '0';
			if (jj[i] == '?')
				jj[i] = '9';
			ccv = ccv * 10 + cc[i] - '0';
			jjv = jjv * 10 + jj[i] - '0';
		}
		update_best(ccv - jjv, cc, jj);

		strcpy(cc, c);
		strcpy(jj, j);
		ccv = 0;
		jjv = 1;
		cc[bit] = ccv + '0';
		jj[bit] = jjv + '0';
		// jj > cc
		for (int i=bit+1; i<n; ++i) {
			if (cc[i] == '?')
				cc[i] = '9';
			if (jj[i] == '?')
				jj[i] = '0';
			ccv = ccv * 10 + cc[i] - '0';
			jjv = jjv * 10 + jj[i] - '0';
		}
		update_best(jjv - ccv, cc, jj);
	}
}

void solve(int no)
{
	scanf(" %s", c);
	scanf(" %s", j);
	n = strlen(c);
	if (ok_same()) {
		printf("Case #%d: %s %s\n", no, c, j);
		return;
	}
	best = (u64)-1;
	for (int i=0; i<n; ++i) {
		// enum the first bit that is not same
		get(i);
		// prevs should be same
		if (!cansame(i))
			break;
		if (c[i] == '?' && j[i] == '?')
			c[i] = j[i] = '0';
		else if (c[i] == '?')
			c[i] = j[i];
		else if (j[i] == '?')
			j[i] = c[i];
	}

	printf("Case #%d: %s %s\n", no, bestc, bestj);
}

int main()
{
	int T;
	cin >> T;
	for (int i=0; i<T; ++i) {
		solve(i+1);
	}
	return 0;
}
