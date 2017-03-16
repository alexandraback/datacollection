#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

int n;
string s[4];

int mx[4] = {1, -1, 1, 0};
int my[4] = {1, 1, 0, 1};
int flag = 0;

bool check(int i, int j, char t) {
    if (i < 0 || i >= 4 || j < 0 || j >= 4) {
        return false;
    }
    if (s[i][j] == '.') {
        flag = 1;
    }
    return (s[i][j] == t || s[i][j] == 'T');
}

void process() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int move = 0; move < 4; move++) {
                int flag1 = 1, flag2 = 1;
                for (int k = 0; k < 4; k++) {
                    if (!check(i + k * mx[move], j + k * my[move], 'X')) {
                        flag1 = 0;
                    }
                    if (!check(i + k * mx[move], j + k * my[move], 'O')) {
                        flag2 = 0;
                    }
                }
                if (flag1) {
                    printf("X won\n");
                    return;
                }
                if (flag2) {
                    printf("O won\n");
                    return;
                }
            }
        }
    }
    if (flag) {
        printf("Game has not completed\n");
    } else {
        printf("Draw\n");
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    string d;
    forn (t, n) {
        forn (i, 4) {
            cin >> s[i];
            //cout << s[i] << endl;
        }
        //cout << endl;
        flag = 0;
        printf("Case #%d: ", t + 1);
        process();
    }

    return 0;
}
