#include <cstdio>
#include <cstring>
#include <string>

#define B(x) (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u')

using namespace std;

const int MAXL = 10001;

typedef char str [MAXL];

int n, len;
str s;

inline bool ok (int L, int R) {
	int sum = 0;
	for (int i = L; i <= R; ++i)
		if (B (s [i])) {
			sum++; if (sum >= n) return true;
		} else
			sum = 0;
	
	return false;
}

int main () {
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	
	int task; scanf ("%d\n", &task);
	for (int T = 1; T <= task; ++T) {
		scanf ("%s %d\n", s + 1, &n), len = (int)strlen (s + 1);
		
		int res = 0;
		for (int i = 1; i <= len; ++i)
			for (int j = i; j <= len; ++j)
				res += ok (i, j);
		
		printf ("Case #%d: %d\n", T, res);
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
