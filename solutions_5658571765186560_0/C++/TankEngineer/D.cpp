#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const char f[] = "RICHARD", g[] = "GABRIEL";

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r, c;
        scanf("%d%d%d", &n, &r, &c);
        if (r > c) {
            swap(r, c);
        }
        static int id = 0;
        printf("Case #%d: ", ++id);
        if (n == 1) {
            puts(g);
        } else if (n == 2) {
            if (r * c % 2 != 0) {
                puts(f);
            } else {
                puts(g);
            }
        } else if (n == 3) {
            if (r * c % 3 != 0 || r == 1) {
                puts(f);
            } else {
                puts(g);
            }
        } else if (n == 4) {
            if (r * c % 4 != 0 || r == 1 || r == 2) {
                puts(f);
            } else {
                puts(g);
            }
        }
    }
    return 0;
}
