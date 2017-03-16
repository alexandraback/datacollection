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

int n, m, cases, ans, a[10];

int square(int x) {
    int p = sqrt(x);
    for (int i = p-2; i <= p+2; i++) if (i*i == x) return i;
    return 0;
}

bool pal(int x) {
    if (x == 0) return false;
    int t;
    for (t = 0; x; x/=10){
        a[++t] = x % 10;
    }
    for (int i = 1; i <= t / 2; i++)
        if (a[i] != a[t-i+1]) return false;
    return true;
}

bool check(int x) {
    if (!pal(square(x))) return false;
    if (!pal(x)) return false;
    return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
	cin >>cases;
	for (int _ = 1; _ <= cases; _++) {
        cout << "Case #"<< _ <<": ";
        cin >>n >>m; ans = 0;
        for (int i = n; i <= m; i++)
        if (check(i)) {
            ans++;
            //cout << i <<endl;
        }
        cout <<ans <<endl;
	}
	return 0;
}
