#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#define fo(i, l, r) for (int i = l; i <= r; ++i)
#define fd(i, r, l) for (int i = r; i >= l; --i)
#define LL long long
using namespace std;
#define N 111

int n, m, cases;
int maxnc[N], maxnr[N], a[N][N];

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] < maxnr[i] && a[i][j] < maxnc[j]) return false;
    return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
	cin >>cases;
	for (int _ = 1; _ <= cases; _++) {
        cout << "Case #"<< _ <<": ";
        memset(maxnc, 0, sizeof(maxnc));
        memset(maxnr, 0, sizeof(maxnr));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin>>a[i][j];
                maxnr[i] = max(maxnr[i], a[i][j]);
                maxnc[j] = max(maxnc[j], a[i][j]);
            }
        if (check()) puts("YES"); else puts("NO");
	}
	return 0;
}
