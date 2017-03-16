#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const double EPS = 1e-6;
const int INF = 1000000000;

int gauss (vector < vector<double> > a, vector<double> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}

char s[4096];

void add_str(string let, int num, vector<vector<double> > &a) {
    for (int i = 0; i < (int) let.size(); ++i) {
        ++a[let[i] - 'A'][num];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%s", s);
        int ln = strlen(s);
        vector<vector<double> > a;
        a.resize(26);
        for (int i = 0; i < 26; ++i) {
            a[i].assign(11, 0);
        }
        for (int i = 0; i < ln; ++i) {
            ++a[s[i] - 'A'][10];
        }
        add_str("ZERO", 0, a);
        add_str("ONE", 1, a);
        add_str("TWO", 2, a);
        add_str("THREE", 3, a);
        add_str("FOUR", 4, a);
        add_str("FIVE", 5, a);
        add_str("SIX", 6, a);
        add_str("SEVEN", 7, a);
        add_str("EIGHT", 8, a);
        add_str("NINE", 9, a);
        
        vector<double> cnt;
        gauss(a, cnt);
        printf("Case #%d: ", te);
        for (int i = 0; i < 10; ++i) {
            while (cnt[i] + EPS > 1) {
                cnt[i] -= 1;
                printf("%c", '0' + i);
            }
        }
        printf("\n");
    }
    return 0;
}
