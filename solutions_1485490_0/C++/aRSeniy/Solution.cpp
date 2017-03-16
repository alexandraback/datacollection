#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

int n, m;
vector <int> tA, tB;
vector <long long> numtA, numtB;
int it;

long long stupid (int l, int r, long long numA, long long numB) {
    ++it;
    if (it % 10000 == 0)
        cerr << it << endl;

    long long cur = 0;
    if (tA[l] == tB[r])
        cur = min(numA, numB);

    numA -= cur;
    numB -= cur;

    long long c1 = 0;
    if (l + 1 < n) c1 = stupid(l + 1, r, numtA[l + 1], numB);
    long long c2 = 0;
    if (r + 1 < m) c2 = stupid(l, r + 1, numA, numtB[r + 1]);
    return cur + max(c1, c2);
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> n >> m;
        cerr << "test = " << test << endl;
        it = 0;

        numtA.assign(n, 0), numtB.assign(m, 0);
        tA.assign(n, 0), tB.assign(m, 0);

        for (int i = 0; i < n; ++i) {
            cin >> numtA[i] >> tA[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> numtB[i] >> tB[i];
        }

        /*vector < vector <long long> > d(n, vector <long long> (m, 0));
        vector < vector <long long> > answ(n, vector <long long> (m, 0));

        for (int i = 0; i < n; ++i) {
            long long now = numtA[i];
            for (int j = 0; j < m; ++j) {
                if (tA[i] == tB[j]) {
                    long long cur = min(numtA[i], numtB[j]);
                    cur = min(cur, now);
                    now -= cur;
                    d[i][j] = cur + (j ? d[i][j - 1] : 0);
                }
            }
        }
		
        answ[0] = d[0];
        for (int i = 1; i < n; ++i) {

        }

        long long ans = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans = max(ans, d[i][j]);*/
        
		cout << "Case #" << test << ": " << stupid(0, 0, numtA[0], numtB[0]) << endl;
	}
	return 0;
}