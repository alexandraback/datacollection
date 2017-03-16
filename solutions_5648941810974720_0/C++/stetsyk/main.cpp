#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#ifdef lyosha
#define files freopen("input.txt", "r", stdin);
#else
#define files //freopen("howmany.in","r",stdin); freopen("howmany.out","w",sdout);
#endif
using namespace std;
typedef long long ll;
#define y1 fjlwekf
double EPS = 1e-9;
double INF = 1e-9;
const int mod = 1e9 + 7;
const int N = 200005;
string t[11] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", ""};
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
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for(int qw = 1; qw <= T; ++qw){
        string s;
        cin >> t[10];
        vector<vector<double> > a;
        a.resize(26);
        for(char j = 0; j < 26; ++j){
            a[j].resize(11);
            for(int i = 0; i <= 10; ++i){
                for(auto it : t[i]){
                    a[j][i] += ((j + 'A') == it);
                }
            }
        }
        vector<double> ans;
        gauss(a, ans);
        cout << "Case #" << qw << ": ";
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < (int)(ans[i] + 0.5); ++j){
                cout << i;
            }
        }
        cout << "\n";
    }
    return 0;
}
