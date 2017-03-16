#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;



int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int test; cin >> test;
    for (int it = 0; it < test; it++) {
        printf("Case #%d: ", it+1);
		int x, y; scanf("%d%d", &x, &y);
		int cx = 0, cy = 0;
		if (x > 0) {
            while (cx < x) {
                cx++;
                printf("WE");
            }
		} else {
            while (cx > x) {
                cx--;
                printf("EW");
            }
		}
		if (y > 0) {
            while (cy < y) {
                cy++;
                printf("SN");
            }
		} else {
            while (cy > y) {
                cy--;
                printf("NS");
            }
		}
        printf("\n");
    }
    return 0;
}

