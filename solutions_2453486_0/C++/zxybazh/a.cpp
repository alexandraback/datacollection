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

int n, m, cases;
char a[10][10];

bool fullfill() {
    for (int i = 0; i < 4; i++)
        for (int j = 0 ; j < 4; j++)
            if (a[i][j] == '.') return false;
    return true;
}

bool check(char p) {
    bool flag;
    for (int i = 0; i < 4; i++) {
        flag = true;
        for (int j = 0; j < 4; j++)
            flag &= a[i][j] == p || a[i][j] == 'T';
        if (flag) return true;
        flag = true;
        for (int j = 0; j < 4; j++)
            flag &= a[j][i] == p || a[j][i] == 'T';
        if (flag) return true;
    }
    flag = true;
    for (int i = 0; i < 4; i++)
        flag &= a[i][i] == p || a[i][i] == 'T';
    if (flag) return true;
    flag = true;
    for (int i = 0; i < 4; i++)
        flag &= a[i][3-i] == p || a[i][3-i] == 'T';
    if (flag) return true;
    return false;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
	scanf("%d\n", &cases);
	for (int _ = 1; _ <= cases; _++) {
        for (int i = 0; i < 4; i++) gets(a[i]); gets(a[5]);
        cout << "Case #" << _ << ": ";
        if (check('X')) puts("X won"); else
        if (check('O')) puts("O won"); else
        if (fullfill()) puts("Draw"); else
        puts("Game has not completed");
	}
	return 0;
}
