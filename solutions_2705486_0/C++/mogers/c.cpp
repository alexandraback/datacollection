#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <stack>
#include <fstream>
using namespace std;
#define PB			push_back
#define ALL(v)			(v).begin() , (v).end()
#define SZ(v)			( (int) v.size() )
#define Set(v,x)		memset(  v , x , sizeof(v))
#define two(n)			( 1 << (n) )
#define contain(S,i)		( (S) & two(i) ) 
#define SQR(v)			( (v) * (v) )
#define ABS(x)			( ( (x) >= 0 ) ? (x) : -(x) )
#define foreach(v,it)		for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
int max_wsize = 0;
const int MAX = 60;
char w[MAX];
int dp[MAX][MAX], N, v[MAX];

struct Trie {
	Trie * next[26];
	bool end;
	Trie() {
		memset(next, 0, sizeof next);
		end = false;
	}
} root;
void insert( char* s ) {
	int i;
	Trie * p = &root;
	while (*s) {
		i = *s - 'a';	
		if (p->next[i] == NULL)
			p->next[i] = new Trie();
		p = p->next[i];
		s++;
	}
	p->end = true;
}
bool ok(Trie * t, int i, int end, int p1, int p2) {
	if (i == end)
		return t->end;
	if (i == p1 || i == p2) {
		for (int j = 0; j < 26; j++)
			if (t->next[j] && ok(t->next[j], i+1, end, p1, p2))
				return true;
		return false;
	}
	else {
		if (t->next[v[i]] == NULL)
			return false;
		return ok(t->next[v[i]], i+1, end, p1, p2);
	}
}
int go(int i, int last) {
	int &r = dp[i][last];
	if (r != -1)
		return r;
	if (i == N)
		return r = 0;
	int j = 1, a, b;
	r = 100000;
	for (j = 1; j <= max_wsize && i+j <= N; j++) {
		int end = i+j;
		if (ok(&root, i, end, -1, -1))
			r = min(r, go(end, last));

		for (a = max(i, last+5); a < end; a++) {
			if (ok(&root, i, end, a, -1))
				r = min(r, 1 + go(end, a));

			for (b = a+5; b < end; b++)
				if (ok(&root, i, end, a, b))
					r = min(r, 2+go(end, b));
		}
	}
	return r;
}
void solve() {
	scanf("%s", w);
	N = strlen(w);
	for (int i = 0; i < N ; i++)
		v[i+5] = w[i]-'a';
	N += 5;
	Set(dp, -1);
	cout << go(5, 0) << endl;
}

int main() {
	int C , nc;
	char word[100];
	FILE  *f = fopen("dict.txt", "r");

	while (fscanf(f, "%s", word) != EOF) {
		max_wsize = max(max_wsize, (int)strlen(word));	
		insert(word);
	}
	scanf("%d\n", &C);
	for ( nc = 1 ; nc <= C ; nc++) {
		cout << "Case #" << nc << ": ";
		solve();
	}	
	return 0;
}
