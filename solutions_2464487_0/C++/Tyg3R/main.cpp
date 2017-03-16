/* 
 * File:   main.cpp
 * Author: tyg3r
 *
 * Created on 27. duben 2013, 3:37
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    
    int T, r, t;
    scanf("%d", &T);
    for(int caseN = 1; caseN <= T; caseN++) {
        scanf("%d%d", &r, &t);
        int cnt = 0;
        for(r = r+1; t >= 0; r += 2) {
            if(2*r-1 <= t) {
                t -= 2*r-1;
                cnt++;
            } else break;
        }
        printf("Case #%d: %d\n", caseN, cnt);
    }
    return 0;
}

