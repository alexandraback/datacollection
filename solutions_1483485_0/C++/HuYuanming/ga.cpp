/*2012.4.13*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
#include <cmath>
using namespace std;
#define PL printf("%d\n", __LINE__);
#define MM(a, b) memset(a, b, sizeof(a));
#define For(i, a) for (register int i = 0; i < (a); i++)
#define Foru(i, a, b) for (register int i = (a); i < (b); i++)
#define foru(i, a, b) for (register int i = (a); i <= (b); i++)
#define ford(i, a, b) for (register int i = (a); i >= (b); i--)
#define fore(i, a, b) for (register __typeof(a) i = (a); (i) != (b); (i)++)
#define inf 1000000000
#define linf 10000000000000000LL
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define Walk(u) for (elist l = de[u]; l; l = l->next)
#define bgn begin
#define fi first
#define se second
#define ite iterator
#define All(x) (x).bgn(), (x).end()
#define sz(x) ((int)x.size())
#define pq priority_queue
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

char s[111111];

char trans(char ch) {
	if (ch == 'a') return 'y';
	if (ch == 'b') return 'h';
	if (ch == 'c') return 'e';
	if (ch == 'd') return 's';
	if (ch == 'e') return 'o';
	if (ch == 'f') return 'c';
	if (ch == 'g') return 'v';
	if (ch == 'h') return 'x';
	if (ch == 'i') return 'd';
	if (ch == 'j') return 'u';
	if (ch == 'k') return 'i';
	if (ch == 'l') return 'g';
	if (ch == 'm') return 'l';
	if (ch == 'n') return 'b';
	if (ch == 'o') return 'k';
	if (ch == 'p') return 'r';
	if (ch == 'q') return 'z';
	if (ch == 'r') return 't';
	if (ch == 's') return 'n';
	if (ch == 't') return 'w';
	if (ch == 'u') return 'j';
	if (ch == 'v') return 'p';
	if (ch == 'w') return 'f';
	if (ch == 'x') return 'm';
	if (ch == 'y') return 'a';
	if (ch == 'z') return 'q';
	if (ch == ' ') return ' ';
	return ch;
}

void getline(char *s) {
	char ch;
	while ((ch = getchar()) != '\n') *s++ = ch;
	*s = 0;
}

int main() {
	int n;
	scanf("%d\n", &n);
	For (i, n) {
		getline(s); 
		int len = strlen(s);
		printf("Case #%d: ", i + 1);
		For (i, len) printf("%c", trans(s[i]));
		printf("\n");
	}
	return 0;
}
