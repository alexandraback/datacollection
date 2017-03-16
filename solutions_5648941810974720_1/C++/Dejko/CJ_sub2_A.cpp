#include <bits/stdc++.h>

using namespace std;

int t, num[128], num2[128];
char s[2008];
int x[2000];
/*
string digit[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
                        z            w                               x                  g
                                            H
                                                    R
                                                            F
                            O
                                                                            S
                                                                                        N
*/
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &t);
    for (int tp=1; tp<=t; tp++) {
        for (int c='A'; c<='Z'; c++) num[c] = 0;
        scanf("%s", s);
        printf("Case #%d: ", tp);
        int l = strlen(s);
        for (int i=0; i<l; i++) num[s[i]]++;
        int n = 0;
        while (true) {
            if (num['Z']) {
                num['Z']--;
                num['E']--;
                num['R']--;
                num['O']--;
                x[n++] = 0;
                continue;
            }
            if (num['W']) {
                num['T']--;
                num['W']--;
                num['O']--;
                x[n++] = 2;
                continue;
            }
            if (num['X']) {
                num['S']--;
                num['I']--;
                num['X']--;
                x[n++] = 6;
                continue;
            }
            if (num['G']) {
                num['E']--;
                num['I']--;
                num['G']--;
                num['H']--;
                num['T']--;
                x[n++] = 8;
                continue;
            }
            if (num['H']) {
                num['T']--;
                num['H']--;
                num['R']--;
                num['E']--;
                num['E']--;
                x[n++] = 3;
                continue;
            }

            if (num['R']) {
                num['F']--;
                num['O']--;
                num['U']--;
                num['R']--;
                x[n++] = 4;
                continue;
            }
            if (num['F']) {
                num['F']--;
                num['I']--;
                num['V']--;
                num['E']--;
                x[n++] = 5;
                continue;
            }

            if (num['O']) {
                num['O']--;
                num['N']--;
                num['E']--;
                x[n++] = 1;
                continue;
            }

            if (num['S']) {
                num['S']--;
                num['E']--;
                num['V']--;
                num['E']--;
                num['N']--;
                x[n++] = 7;
                continue;
            }
            if (num['N']) {
                num['N']--;
                num['I']--;
                num['N']--;
                num['E']--;
                x[n++] = 9;
                continue;
            }
            break;
        }
        sort(x, x+n);
        for (int i=0; i<n; i++) printf("%d", x[i]);
        printf("\n");
    }


    return 0;
}
