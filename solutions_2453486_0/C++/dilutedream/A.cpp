#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 11;

char a [MAXN][MAXN];

inline bool check (char c) {
	for (int i = 1; i <= 4; ++i) {
		bool yes = true;
		for (int j = 1; j <= 4; ++j)
			if (a [i][j] != 'T' && a [i][j] != c)
				yes = false;
		
		if (yes)
			return true;
	}

	for (int j = 1; j <= 4; ++j) {
		bool yes = true;
		for (int i = 1; i <= 4; ++i)
			if (a [i][j] != 'T' && a [i][j] != c)
				yes = false;
		
		if (yes)
			return true;
	}
	
	bool yes = true;
	for (int i = 1; i <= 4; ++i)
		if (a [i][i] != 'T' && a [i][i] != c)
			yes = false;
	
	if (yes)
		return true;
	
	yes = true;
	for (int i = 1; i <= 4; ++i)
		if (a [i][5 - i] != 'T' && a [i][5 - i] != c)
			yes = false;
	
	if (yes)
		return true;
	
	return false;
}

inline bool full () {
	bool yes = true;
	
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			if (a [i][j] == '.')
				yes = false;
	
	return yes;
}

int main () {
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	
	int task; scanf ("%d\n", &task);
	for (int t = 1; t <= task; ++t) {
		for (int i = 1; i <= 4; ++i)
			scanf ("%s\n", a [i] + 1);
		
		scanf ("\n");
		
		printf ("Case #%d: ", t);
		
		if (check ('X'))
			printf ("X won\n");
		else if (check ('O'))
			printf ("O won\n");
		else if (full ())
			printf ("Draw\n");
		else
			printf ("Game has not completed\n");
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
