#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cctype>
#include <cstring>
using namespace std;

template <class T> inline void checkmin(T& a, const T& b) { if (a > b) a = b; } 

FILE *fp = fopen("garbled_email_dictionary.txt", "r");
const int inf = 1000000000;

struct node {
	node *next[26];
	int v;
	node() {
		memset(this, 0, sizeof *this);
	}
} *root;

void insert(const char *s) {
	node *p = root;
	for ( ;*s; ++s ) {
		assert( islower(s[0]) );
		int j = s[0] - 'a';
		if ( !p->next[j] ) {
			p->next[j] = new node();
		}
		p = p->next[j];
	}
	p->v = 1;
}

void init() {
	root = new node();
	char s[15];
	while ( fscanf(fp, "%s", s) != EOF ) {
		insert(s);
	}
}

int n;
static char s[4000 + 5];
static int dp[7][4000 + 5];

void go(node *p, int i, int dist, int lastdp) {
	if ( p->v ) {
		checkmin( dp[dist][i], lastdp ); 
	}
	if ( i == n ) return;
	if ( dist == 5 ) {
		int j = s[i] - 'a';
		for ( int k = 0; k < 26; ++k ) {
			if ( p->next[k] ) {
				if ( k == j ) {
					go(p->next[j], i + 1, dist, lastdp);
				} else {
					go(p->next[k], i + 1, 1, lastdp + 1);
				}
			}
		}
	} else {
		int j = s[i] - 'a';
		if ( p->next[j] ) {
			go(p->next[j], i + 1, dist + 1, lastdp);
		}
	}
}

void solve(int ri) {
	fprintf(stderr, "working on test %d\n", ri);
	scanf("%s", s);
	n = strlen(s);
	for ( int k = 1; k <= 6; ++k ) {
		for ( int i = 0; i <= n; ++i ) {
			dp[k][i] = inf;
		}
	}
	dp[5][0] = 0;
	for ( int i = 0; i <= n; ++i ) {
		for ( int k = 1; k <= 5; ++k ) {
			if ( dp[k][i] == inf ) continue;
			//printf("dp[%d][%d] = %d\n", k, i, dp[k][i]);
			go(root, i, k, dp[k][i]);
		}
	}
	int ans = inf;
	for ( int k = 1; k <= 5; ++k ) {
		checkmin( ans, dp[k][n] );
	}
	printf("Case #%d: %d\n", ri, ans);
}

int main() {
	init();
	int re; cin >> re;
	for ( int ri = 1; ri <= re; ++ri ) {
		solve(ri);
	}
}
