#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fore(i, b, e) for (int i = (int)b; i <= (int)e; i++)
#define f first
#define s second
#define next qwertyusdfgh
#define read(x) scanf("%d", &x)
#define write(x) printf("%d ", x)
#define writeln(x) printf("%d\n", x)
#define pb push_back
#define mp make_pair

const int maxN = 102;
const ld eps = 1e-9;

int p[maxN];
int go[maxN][maxN];
ld d[maxN][maxN][maxN];
ld a[maxN], b[maxN];
int k, l, s;
string lt, word;

void kmp() {
	p[0] = 0;
	int len = 0;
	for (int i = 1; i < l; i++) {
		while (len > 0 && word[i] != word[len])
			len = p[len - 1];
		if (word[i] == word[len])
			len++;
		p[i] = len;
 	}	
}

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> k >> l >> s;
		cin >> lt >> word;
		kmp();
		int y = l - p[l - 1];
		int mx = 1 + (s - l) / y;
		for (int i = 0; i < 26; i++)
			a[i] = 0;
		for (int i = 0; i < k; i++)
			a[lt[i] - 'A']++;
		for (int i = 0; i < l; i++)
			if (a[word[i] - 'A'] == 0) {
				mx = 0;
				break;
			}
		if (mx == 0) {
			printf("Case #%d: 0.0\n", t);
			continue; 
		}
		for (int i = 0; i < 26; i++)
			a[i] /= k;
		for (int i = 0; i <= l; i++) {
	    	for (int j = 0; j < 26; j++) {
	    		int x = i;
	    		if (i == l)
	    			x = p[x - 1];
	    		while (x > 0 && word[x] != char('A' + j))
	    			x = p[x - 1];
	    		if (word[x] == char('A' + j))
	    			x++;
	    		go[i][j] = x;	    			
	    	}
	    }

		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= s; j++)
				for (int k = 0; k <= l; k++)
					d[i][j][k] = 0;
		d[0][0][0] = 1;	
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				for (int k = 0; k <= l; k++) 
					if (d[i][j][k] >= eps) {
						//printf("%d %d %d %.10f\n", i, j, k, d[i][j][k]);
						int nj = j + (k == l);
						for (int c = 0; c < 26; c++)
							d[i + 1][nj][go[k][c]] += d[i][j][k] * a[c]; 
					}
		for (int i = 0; i <= s; i++)
			b[i] = 0;
		for (int i = 1; i <= s; i++)
			b[i] = d[s][i - 1][l];
		for (int i = 0; i <= s; i++)
			for (int k = 0; k < l; k++)
				b[i] += d[s][i][k];
		
		double ans = 0;
		for (int i = 0; i <= s; i++)
			ans += b[i] * i;			
				
		printf("Case #%d: %.10f\n", t, mx - ans);
	}
	
	return 0;
}