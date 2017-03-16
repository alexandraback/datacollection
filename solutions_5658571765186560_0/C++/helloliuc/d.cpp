#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

char ans[5][5][5];

int main()
{
    int T;
    scanf("%d",&T);
    int n,r,c;
    char win;
    for(int cas=1;cas<=T;cas++) {
        scanf("%d%d%d", &n, &r, &c);
        int fr = r, fc = c;
        if(r > c) {
            swap(r, c);
        }

        if(r * c < n) {
            win = 'R';
        }
        else if(r * c % n != 0) {
            win = 'R';
        }
        else if(n == 1) {
            win = 'G';
        }
        else if(n == 2) {
            if((r * c) % 2 == 0) {
                win = 'G';
            }
            else {
                win = 'R';
            }
        }
        else if(n == 3) {
            if(r == 1) {
                win = 'R';
            }
            else if(r % 3 == 0 || c % 3 == 0) {
                win = 'G';
            }
            else {
                win = 'R';
            }
            /*
            else if(r == 2) {
                if(c % 3 == 0) win = 'G';
                else win = 'R';
            }
            else if(r == 3) {
                win = 'G';
            }
            else if(r == 4) {
                if(c % 3 == 0) win = 'G';
                else win = 'R';
            }
            */
        }
        else if(n == 4) {
            if(r == 1 || r == 2)    win = 'R';
            else if(r == 3) win = 'G';
            else if(r == 4) win = 'G';
        }
        else {
            printf("Wrong!\n");
        }

        if(win == 'R') {
            printf("Case #%d: RICHARD\n", cas);
        }
        else {
            printf("Case #%d: GABRIEL\n", cas);
        }
        //ans[n][fr][fc] = win;
    }

    /*
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=4;j++) {
            for(int k=1;k<=4;k++) {
                printf("%d %d %d ", i,j, k);
                if(ans[i][j][k] == 'R') {
                    printf("RICHARD\n");
                }
                else
                    printf("GABRIEL\n");
            }
        }
    }
    */
    return 0;
}
