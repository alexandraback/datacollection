#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

#define H 2500
int c[H+1];

int main()
{
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(c, 0, sizeof(c));
        int n; cin >> n;
        for (int i = (2 * n - 1)*n; i--; ) {
            int h; cin >> h;
            c[h]++;
        }
        

        printf("Case #%d:", t);

        for (int i = 0; i <= H; i++) {
            if (c[i] & 1)
                printf(" %d", i);
        }
        
        putchar('\n');
    }

    return 0;
}
