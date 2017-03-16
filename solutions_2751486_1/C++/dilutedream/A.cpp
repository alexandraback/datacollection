#include <cstdio>
#include <cstring>
#include <string>

#define B(x) (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u')

using namespace std;

typedef long long int64;

const int MAXL = 5000001;

typedef char str [MAXL];

int n, len;
int f [MAXL], nxt [MAXL];
str s;

int main () {
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	
	int task; scanf ("%d\n", &task);
	for (int T = 1; T <= task; ++T) {
		scanf ("%s %d\n", s + 1, &n), len = (int)strlen (s + 1);
		
		for (int i = len; i >= 1; --i)
			if (B (s [i]))
				f [i] = f [i + 1] + 1;
			else
				f [i] = 0;
		
		nxt [len + 1] = len + 1;
		for (int i = len; i >= 1; --i)
			if (f [i] >= n)
				nxt [i] = i;
			else
				nxt [i] = nxt [i + 1];
		
		int64 res = 0;
		
		for (int i = 1; i <= len; ++i)
			if (nxt [i] + n - 1 <= len)
				res += len - (nxt [i] + n - 1) + 1;
		
		printf ("Case #%d: %I64d\n", T, res);
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
