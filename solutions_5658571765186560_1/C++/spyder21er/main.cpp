/** Google Codejam 2015
  * Qualification Round
  * Problem D: Ominous Omino
  * Author: spyder21er
  */

#include <bits/stdc++.h>
using namespace std;

#define fileName "D-large"
int caseNum = 0;

void solve() {
    printf("Case #%d: ", ++caseNum);
	int xx, rr, cc;
	scanf("%d %d %d", &xx, &rr, &cc);
    if(xx == 1) {
        printf("GABRIEL\n");
        return;
    }
    if(xx > (rr*cc)) {
        printf("RICHARD\n");
        return;
    }
    if((rr*cc) % xx) {
        printf("RICHARD\n");
        return;
    }
    if(xx == 2) {
        printf("GABRIEL\n");
        return;
    }
    if(xx == 3) {
        if(cc == 1 || rr == 1) {
            printf("RICHARD\n");
            return;
        } else {
            printf("GABRIEL\n");
            return;
        }
    }
    if(xx == 4) {
        if(cc <= 2 || rr <= 2) {
            printf("RICHARD\n");
            return;
        } else {
            printf("GABRIEL\n");
            return;
        }        
    }
    if(xx == 5) {
        if(cc < 3 || rr < 3) {
            printf("RICHARD\n");
            return;
        }
        if((cc == 3 || rr == 3) && (cc == 5 || rr == 5)) {
            printf("RICHARD\n");
            return;
        } else {
            printf("GABRIEL\n");
            return;
        }
    }
    if(xx == 6) {
        if(cc <= 3 || rr <= 3) {
            printf("RICHARD\n");
            return;
        } else {
            printf("GABRIEL\n");
            return;
        }
    }    
    printf("RICHARD\n");
}

int main() {
    freopen(fileName ".in", "r", stdin);
    freopen(fileName ".txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
	while(T--) {
        solve();
    }
    return 0;
}